
#include "HGS_ConjuntoAnimacion.h"



HGS_ConjuntoAnimacion::HGS_ConjuntoAnimacion(int numAnimaciones, HGS_Animacion ** animaciones){

    this->numAnimaciones= numAnimaciones;
    this->animaciones= animaciones;
    this->animacionDibujo= 0;

}

int HGS_ConjuntoAnimacion::cogerNumAnimaciones(){

    return this->numAnimaciones;

}


void HGS_ConjuntoAnimacion::iniciarAnimacion(int numAnimacion){

    assert(numAnimacion>=0 && numAnimacion<this->numAnimaciones);

    this->animacionDibujo= numAnimacion;
    this->animaciones[animacionDibujo]->asignarSigImagenDibujo(0.0);

}


void HGS_ConjuntoAnimacion::cambiarAnimacion(int numAnimacion){

    assert(numAnimacion>=0 && numAnimacion<this->numAnimaciones);

    this->animacionDibujo= numAnimacion;
    double sigImagen= this->animaciones[this->animacionDibujo]->cogerSigImagenDibujo();

    if ((int)sigImagen>=this->animaciones[animacionDibujo]->cogerNumImagenes())
        this->animaciones[animacionDibujo]->asignarSigImagenDibujo(0.0);

}


void HGS_ConjuntoAnimacion::dibuja(double x, double y, double w, double h){

    this->animaciones[this->animacionDibujo]->dibuja(x,y,w,h);

}
