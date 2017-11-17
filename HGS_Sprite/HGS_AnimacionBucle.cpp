

#include "HGS_AnimacionBucle.h"


double HGS_AnimacionBucleAvanzarImagen(double imagenDibujo,double imagSegXfactorLambda, int numImagenes){

    imagenDibujo+= imagSegXfactorLambda;
    if (imagenDibujo+1.0>numImagenes) imagenDibujo+= -(double)(numImagenes+1);

    return imagenDibujo;

}

HGS_AnimacionBucle::HGS_AnimacionBucle(HGS_ImagenesAnimacion * imagenes, double imagSeg) : HGS_Animacion(imagenes,imagSeg){

    this->avanzarImagenAux= HGS_AnimacionBucleAvanzarImagen;

}
