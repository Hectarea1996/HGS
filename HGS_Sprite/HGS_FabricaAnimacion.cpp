
#include "HGS_FabricaAnimacion.h"


HGS_Animacion * HGS_FabricaAnimacionBucle(HGS_ImagenesAnimacion * imagenes, double imagSeg){

    return (HGS_Animacion*) new HGS_AnimacionBucle(imagenes,imagSeg);

}

HGS_Animacion * HGS_FabricaAnimacionUnica(HGS_ImagenesAnimacion * imagenes, double imagSeg){

    return (HGS_Animacion*) new HGS_AnimacionUnica(imagenes,imagSeg);

}
