#ifndef FFPLAYER_SDL
#define FFPLAYER_SDL

#include "ffplayer.h"



















int sdl2_test(char *filepath)
{
    using namespace std;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The image we will load and show on the screen
    SDL_Surface* gHelloWorld = NULL;

    //首先初始化   初始化SD视频子系统
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //创建窗口
    gWindow=SDL_CreateWindow("SHOW BMP",//窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//窗口位置设置
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,//窗口的宽度
                            SCREEN_HEIGHT,//窗口的高度
                            SDL_WINDOW_SHOWN//显示窗口
                            );
    if(gWindow==NULL)
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //Use this function to get the SDL surface associated with the window.
    //获取窗口对应的surface
    gScreenSurface=SDL_GetWindowSurface(gWindow);

    //加载图片
    gHelloWorld = SDL_LoadBMP(filepath);//加载图片
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "Hello_World.bmp", SDL_GetError() );
        return false;
    }
    //Use this function to perform a fast surface copy to a destination surface.
    //surface的快速复制
    //下面函数的参数分别为： SDL_Surface* src ,const SDL_Rect* srcrect , SDL_Surface* dst ,  SDL_Rect* dstrect
    SDL_BlitSurface( gHelloWorld ,     NULL ,                     gScreenSurface ,          NULL);
    SDL_UpdateWindowSurface(gWindow);//更新显示copy the window surface to the screen
    SDL_Delay(8000);//延时2000毫秒

    //释放内存
    SDL_FreeSurface( gHelloWorld );//释放空间
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow);//销毁窗口
    gWindow = NULL ;

    SDL_Quit();//退出SDL
}

















#endif // FFPLAYER_SDL

