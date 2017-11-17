
#include "HGS_Animacion.h"


HGS_Animacion::HGS_Animacion(HGS_ImagenesAnimacion * imagenes, double imagSec){

    this->numImagenes= imagenes->cogerNumImagenes();
    this->imagenesAnimacion= imagenes;
    this->imagSeg= imagSeg;
    this->imagenDibujo= 0;
    this->factorLambda= HGS_ControlCogerFactorLambda();
    this->mutex= SDL_CreateMutex();

    this->avanzarImagenAux= NULL;

}

HGS_Animacion::~HGS_Animacion(){

    SDL_free(this->mutex);

}

int HGS_Animacion::cogerNumImagenes(){

    return this->numImagenes;

}

double HGS_Animacion::cogerSigImagenDibujo(){

    SDL_LockMutex(this->mutex);
    double imagDibujo= this->imagenDibujo;
    SDL_UnlockMutex(this->mutex);

    return imagDibujo;

}

void HGS_Animacion::asignarSigImagenDibujo(double sigImagen){

    assert(sigImagen>=0.0 && sigImagen<(double)this->numImagenes);

    SDL_LockMutex(this->mutex);
    this->imagenDibujo= sigImagen;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Animacion::avanzarImagen(){

    assert(this->avanzarImagenAux!=NULL);


    double imagen= this->cogerSigImagenDibujo();
    imagen= this->avanzarImagenAux(imagen,this->imagSeg*(*this->factorLambda),this->numImagenes);
    this->asignarSigImagenDibujo(imagen);

}

void HGS_Animacion::dibuja(double x, double y, double w, double h){

    SDL_LockMutex(this->mutex);
    double numImagen= this->imagenDibujo;
    SDL_UnlockMutex(this->mutex);

    this->imagenesAnimacion->dibuja(x,y,w,h,numImagen);

}
