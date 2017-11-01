#ifndef HGS_IMAGEN_H_INCLUDED
#define HGS_IMAGEN_H_INCLUDED


#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include <stdio.h>
#include "../HGS_Ventana/HGS_Ventana.h"
#include <iostream>
using namespace std;



class HGS_Imagen{

    private:

        HGS_Ventana * ventana;
        int maxAnimaciones;
        int * maxImagenes;
        SDL_Texture *** imagenes;


    public:

        HGS_Imagen(char * carpeta, HGS_Ventana * ventana);
        ~HGS_Imagen();
        int cogerNumAnimaciones();
        int cogerNumImagenes(int animacion);
        void dibuja(double x, double y, double w, double h, int animacion, int imagen);

};

#endif // HGS_IMAGEN_H_INCLUDED
