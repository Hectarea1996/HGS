#ifndef HGS_IMAGENESANIMACION_H_INCLUDED
#define HGS_IMAGENESANIMACION_H_INCLUDED

#include "HGS_Imagen.h"

class HGS_ImagenesAnimacion{

    private:

        int numImagenes;
        HGS_Imagen ** imagenes;


    public:

        HGS_ImagenesAnimacion(char * carpeta, HGS_Ventana * ventana);
        ~HGS_ImagenesAnimacion();
        int cogerNumImagenes();
        void dibuja(double x, double y, double w, double h, int numImagen);

};

#endif // HGS_IMAGENESANIMACION_H_INCLUDED
