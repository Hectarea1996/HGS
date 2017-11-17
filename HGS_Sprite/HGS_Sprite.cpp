
#include "HGS_Sprite.h"


HGS_Sprite::HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double x, double y, double w, double h, double anchorX, double anchorY){

    assert(anchorX>=0.0 && anchorX<=1.0);
    assert(anchorY>=0.0 && anchorY<=1.0);

    this->x= x;
    this->y= y;
    this->w= w;
    this->h= h;
    this->anchorX= anchorX;
    this->anchorY= anchorY;

    this->animacion= cjtoAnimacion;

    this->camara= camara;

    this->mutex= SDL_CreateMutex();

    this->factorLambda= HGS_ControlCogerFactorLambda();

}

HGS_Sprite::HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double x, double y, double w, double h)

    : HGS_Sprite(camara,cjtoAnimacion,x,y,w,h,0.5,0.5){}


HGS_Sprite::HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double w, double h)

    : HGS_Sprite(camara,cjtoAnimacion,0,0,w,h,0.5,0.5){}


HGS_Sprite::~HGS_Sprite(){

    SDL_free(this->mutex);

}

void HGS_Sprite::cogerPosicion(double& posX, double& posY){

    SDL_LockMutex(this->mutex);
    posX= this->x;
    posY= this->y;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::asignarPosicion(double posX, double posY){

    SDL_LockMutex(this->mutex);
    this->x= posX;
    this->y= posY;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::mover(double velX, double velY){

    velX= velX*(*this->factorLambda);
    velY= velY*(*this->factorLambda);

    SDL_LockMutex(this->mutex);
    this->x+= velX;
    this->y+= velY;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::moverRapido(double cantX, double cantY){

    SDL_LockMutex(this->mutex);
    this->x+= cantX;
    this->y+= cantY;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::cogerDimensiones(double& dimW, double& dimH){

    SDL_LockMutex(this->mutex);
    dimW= this->w;
    dimH= this->h;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::asignarDimensiones(double dimW, double dimH){

    SDL_LockMutex(this->mutex);
    this->w= dimW;
    this->h= dimH;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::cambiarDimensiones(double velW, double velH){

    velW= velW*(*this->factorLambda);
    velH= velH*(*this->factorLambda);

    SDL_LockMutex(this->mutex);
    this->w+= velW;
    this->h+= velH;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::cambiarRapidoDimensiones(double cantW, double cantH){

    SDL_LockMutex(this->mutex);
    this->w+= cantW;
    this->h+= cantH;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::cogerAnchor(double& anchorX, double& anchorY){

    SDL_LockMutex(this->mutex);
    anchorX= this->anchorX;
    anchorY= this->anchorY;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::asignarAnchor(double anchorX, double anchorY){

    assert(anchorX>=0.0 && anchorX<=1.0);
    assert(anchorY>=0.0 && anchorY<=1.0);

    SDL_LockMutex(this->mutex);
    this->anchorX= anchorX;
    this->anchorY= anchorY;
    SDL_UnlockMutex(this->mutex);

}

void HGS_Sprite::avanzarImagen(){

    this->animacion->avanzarImagen();

}

void HGS_Sprite::dibuja(){

    double camaraX,camaraY;
    this->camara->cogerPosicion(camaraX,camaraY);

    SDL_LockMutex(this->mutex);
    double posX= this->x-(this->w*this->anchorX);
    double posY= this->y-(this->h*this->anchorY);
    double dimW= this->w;
    double dimH= this->h;
    SDL_UnlockMutex(this->mutex);

    posX+= -camaraX;
    posY+= -camaraY;

    this->animacion->dibuja(posX,posY,dimW,dimH);

}
