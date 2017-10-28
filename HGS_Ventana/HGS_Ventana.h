#ifndef HGS_VENTANA_H_INCLUDED
#define HGS_VENTANA_H_INCLUDED

#include <SDL2/SDL.h>

class HGS_Ventana{

    private:

        SDL_Window * ventana;
        SDL_Renderer * render;


    public:

        HGS_Ventana(const char * titulo, int w, int h, int fullscreen);
        ~HGS_Ventana();
        void dibujaImagen(SDL_Texture * imagen, double x, double y, double w, double h);
        void actualiza();

};


#endif // HGS_VENTANA_H_INCLUDED
