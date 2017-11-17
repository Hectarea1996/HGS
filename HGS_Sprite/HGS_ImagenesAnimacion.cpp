
#include "HGS_ImagenesAnimacion.h"

/*
static int HGS_ImagenCuentaCarpetas(char * carpetaRaiz){

    int animacion= 0;
    SDL_Surface * imagen;
    char nombre[50]="";
    do{
        sprintf(nombre,"%s/Animacion%d/Imagen0.bmp",carpetaRaiz,animacion);
        imagen= IMG_Load(nombre);
        if (imagen!=NULL){
            animacion++;
            SDL_free(imagen);
        }
    }while (imagen!=NULL);

    return animacion;

}
*/


/*
static SDL_Texture *** HGS_ImagenLeerImagenes(char * carpeta, HGS_Ventana * ventana, int maxAnim, int * maxImag){

    assert(maxAnim!=0);

    char nombre[50]= "";
    SDL_Texture *** imagenes;

    imagenes= new SDL_Texture**[maxAnim];
    for (int i=0; i<maxAnim; i++){
        assert(maxImag[i]!=0);
        imagenes[i]= new SDL_Texture*[maxImag[i]];
        for (int j=0; j<maxImag[i]; j++){
            sprintf(nombre,"%s/Animacion%d/Imagen%d.bmp",carpeta,i,j);
            try{
                imagenes[i][j]= HGS_ImagenLee(nombre,ventana);
            }
            catch (char * error){
                cout << error << endl;
            }
        }
    }

    return imagenes;

}
*/

/*
static int * HGS_ImagenCuentaTodasImagenes(char * carpeta, int maxAnim){

    int * numImagenes= new int[maxAnim];
    char nombre[50]="";

    for (int i=0; i<maxAnim; i++){
        sprintf(nombre,"%s/Animacion%d",carpeta,i);
        numImagenes[i]= HGS_ImagenCuentaImagenes(nombre);
    }

    return numImagenes;

}
*/

/*
static void HGS_ImagenLiberaImagenes(SDL_Texture *** imagenes, int maxAnim, int * maxImag){

    for (int i=0; i<maxAnim; i++){
        for (int j=0; j<maxImag[i]; j++){
            SDL_free(imagenes[i][j]);
        }
        delete imagenes[i];
    }
    delete imagenes;

}
*/

static int HGS_CuentaImagenes(char * carpeta){

    int ficheros=0;
    SDL_Surface * imagen;
    char nombre[50]= "";
    do {
        sprintf(nombre,"%s/Imagen%d.bmp",carpeta,ficheros);
        imagen= IMG_Load(nombre);
        if (imagen!=NULL){
            ficheros++;
            SDL_free(imagen);
        }
    } while (imagen!=NULL);

    return ficheros;

}

HGS_ImagenesAnimacion::HGS_ImagenesAnimacion(char * carpeta, HGS_Ventana * ventana){

    this->numImagenes= HGS_CuentaImagenes(carpeta);

    this->imagenes= new HGS_Imagen*[this->numImagenes];
    char nombre[50]= "";
    for (int i=0; i<this->numImagenes; i++){
        sprintf(nombre,"%s/Imagen%d.bmp",carpeta,i);
        this->imagenes[i]= new HGS_Imagen(nombre,ventana);
    }

}

HGS_ImagenesAnimacion::~HGS_ImagenesAnimacion(){

    for (int i=0; i<this->numImagenes; i++){
        delete this->imagenes[i];
    }
    delete this->imagenes;

}

int HGS_ImagenesAnimacion::cogerNumImagenes(){

    return this->numImagenes;

}


void HGS_ImagenesAnimacion::dibuja(double x, double y, double w, double h, int numImagen){

    assert(numImagen>=0 && numImagen<this->numImagenes);

    this->imagenes[numImagen]->dibuja(x,y,w,h);

}

