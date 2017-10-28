

#include <iostream>
#include "HGS_Ventana.h"

using namespace std;


HGS_Ventana::HGS_Ventana(const char * titulo, int w, int h, int fullscreen){

    if (fullscreen) this->ventana=SDL_CreateWindow(titulo,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,0,0,SDL_WINDOW_FULLSCREEN_DESKTOP);
    else this->ventana=SDL_CreateWindow(titulo,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,0);

    if (this->ventana==NULL){
        cout << "Error en HGS_CreaVentana|SDL_CreateWindow: %s" << endl << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    this->render= SDL_CreateRenderer(this->ventana,-1,SDL_RENDERER_ACCELERATED);

}

HGS_Ventana::~HGS_Ventana(){

    SDL_DestroyRenderer(this->render);
    SDL_DestroyWindow(this->ventana);

}

void HGS_Ventana::dibujaImagen(SDL_Texture * imagen, double x, double y, double w, double h){

    static SDL_Rect rect;
    rect.x= x;
    rect.y= y;
    rect.w= w;
    rect.h= h;
    SDL_RenderCopy(this->render,imagen,NULL,&rect);

}

void HGS_Ventana::actualiza(){

    SDL_RenderPresent(this->render);

}



