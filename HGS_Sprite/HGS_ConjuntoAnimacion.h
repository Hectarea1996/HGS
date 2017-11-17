#ifndef HGS_CONJUNTOANIMACION_H_INCLUDED
#define HGS_CONJUNTOANIMACION_H_INCLUDED


#include "HGS_Animacion.h"
#include "HGS_FabricaAnimacion.h"

class HGS_ConjuntoAnimacion{

    private:

        int numAnimaciones;
        HGS_Animacion ** animaciones;


    protected:

        int animacionDibujo;

        HGS_ConjuntoAnimacion(int numAnimaciones, HGS_Animacion ** animaciones);
        void iniciarAnimacion(int numAnimacion);
        void cambiarAnimacion(int numAnimacion);
        int cogerNumAnimaciones();


    public:

        virtual void avanzarImagen() = 0;
        void dibuja(double x, double y, double w, double h);

};


#endif // HGS_CONJUNTOANIMACION_H_INCLUDED
