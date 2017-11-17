#ifndef HGS_ANIMACION_H_INCLUDED
#define HGS_ANIMACION_H_INCLUDED

#include "HGS_ImagenesAnimacion.h"
#include "../HGS_Control/HGS_Control.h"

class HGS_Animacion{

    protected:

        double * factorLambda;
        double imagSeg;
        double imagenDibujo;

        SDL_mutex * mutex;

        HGS_ImagenesAnimacion * imagenesAnimacion;
        int numImagenes;

        double (*avanzarImagenAux)(double imagenDibujo,double imagSegXfactorLambda, int numImagenes);

        HGS_Animacion(HGS_ImagenesAnimacion * imagenes, double imagSeg);


    public:

        ~HGS_Animacion();
        void avanzarImagen();
        int cogerNumImagenes();
        double cogerSigImagenDibujo();
        void asignarSigImagenDibujo(double sigImagen);
        void dibuja(double x, double y, double w, double h);

};



#endif // HGS_ANIMACION_H_INCLUDED
