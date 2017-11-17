
#include "HGS_Imagen.h"

static SDL_Texture * HGS_ImagenLee(char * nombre, HGS_Ventana * ventana){

    SDL_Surface * imagen = IMG_Load(nombre);

    if (imagen==NULL){
        throw "La imagen se ha leido incorrectamente.";
    }

    SDL_Texture * textura= SDL_CreateTextureFromSurface(ventana->cogerRenderer(),imagen);

    if (textura==NULL){
        SDL_free(imagen);
        throw "El archivo SDL_Texture no se ha creado correctamente.";
    }

    SDL_free(imagen);

    return textura;

}



HGS_Imagen::HGS_Imagen(char * archivo, HGS_Ventana * ventana){

    assert(archivo!=NULL);
    assert(ventana!=NULL);

    this->ventana= ventana;
    this->imagen= HGS_ImagenLee(archivo,ventana);

}

HGS_Imagen::~HGS_Imagen(){

    SDL_free(this->imagen);

}


void HGS_Imagen::dibuja(double x, double y, double w, double h){

    this->ventana->dibujaImagen(this->imagen,x,y,w,h);

}
