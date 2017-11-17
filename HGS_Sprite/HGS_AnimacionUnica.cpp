
#include "HGS_AnimacionUnica.h"


static double HGS_AnimacionUnicaAvanzarImagen(double imagenDibujo,double imagSegXfactorLambda, int numImagenes){

    if (imagenDibujo+1.0<(double)numImagenes){
        imagenDibujo+= imagSegXfactorLambda;
    }
    else if(imagenDibujo+1.0>(double)numImagenes){
        imagenDibujo= numImagenes-1;
    }

    return imagenDibujo;

}


HGS_AnimacionUnica::HGS_AnimacionUnica(HGS_ImagenesAnimacion * imagenes, double imagSeg) : HGS_Animacion(imagenes,imagSeg){

    this->avanzarImagenAux= HGS_AnimacionUnicaAvanzarImagen;

}
