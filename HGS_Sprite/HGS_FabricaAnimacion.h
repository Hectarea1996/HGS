#ifndef HGS_FABRICAANIMACION_H_INCLUDED
#define HGS_FABRICAANIMACION_H_INCLUDED

#include "HGS_AnimacionBucle.h"
#include "HGS_AnimacionUnica.h"
#include "HGS_ImagenesAnimacion.h"


HGS_Animacion * HGS_FabricaAnimacionBucle(HGS_ImagenesAnimacion * imagenes, double imagSeg);

HGS_Animacion * HGS_FabricaAnimacionUnica(HGS_ImagenesAnimacion * imagenes, double imagSeg);



#endif // HGS_FABRICAANIMACION_H_INCLUDED
