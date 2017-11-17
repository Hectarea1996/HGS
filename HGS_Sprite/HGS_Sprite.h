#ifndef HGS_SPRITE_H_INCLUDED
#define HGS_SPRITE_H_INCLUDED

#include <SDL2/SDL_mutex.h>
#include "HGS_ConjuntoAnimacion.h"
#include "../HGS_Ventana/HGS_Camara.h"

class HGS_Camara;

class HGS_Sprite{

    private:

        double x;
        double y;
        double w;
        double h;
        double anchorX;
        double anchorY;

        HGS_Camara * camara;

        HGS_ConjuntoAnimacion * animacion;

        SDL_mutex * mutex;

        double * factorLambda;


    public:

        HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double w, double h);
        HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double x, double y, double w, double h);
        HGS_Sprite(HGS_Camara * camara, HGS_ConjuntoAnimacion * cjtoAnimacion, double x, double y, double w, double h, double anchorX, double anchorY);
        ~HGS_Sprite();

        void cogerPosicion(double& posX, double& posY);
        void asignarPosicion(double posX, double posY);
        void mover(double velX, double velY);
        void moverRapido(double cantX, double cantY);

        void cogerDimensiones(double& dimW, double& dimH);
        void asignarDimensiones(double dimW, double dimH);
        void cambiarDimensiones(double velW, double velH);
        void cambiarRapidoDimensiones(double cantW, double cantH);

        void cogerAnchor(double& anchorX, double& anchorY);
        void asignarAnchor(double anchorX, double anchorY);

        void avanzarImagen();
        void dibuja();

};


#endif // HGS_SPRITE_H_INCLUDED
