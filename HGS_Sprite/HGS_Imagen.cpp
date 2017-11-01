
#include "HGS_Imagen.h"

static SDL_Texture * HGS_ImagenLee(char * nombre, HGS_Ventana * ventana){

    SDL_Surface * imagen = IMG_Load(nombre);

    if (imagen==NULL){
        throw "La imagen se ha leido incorrectamente.";
    }

    SDL_Texture * textura= SDL_CreateTextureFromSurface(ventana->cogerRenderer(),imagen);

    if (textura==NULL){
        SDL_free(imagen);
        throw "El archivo SDL_Texture no se ha creado correctamente.";
    }

    SDL_free(imagen);

    return textura;

}

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

static int HGS_ImagenCuentaImagenes(char * carpeta){

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

static int * HGS_ImagenCuentaTodasImagenes(char * carpeta, int maxAnim){

    int * numImagenes= new int[maxAnim];
    char nombre[50]="";

    for (int i=0; i<maxAnim; i++){
        sprintf(nombre,"%s/Animacion%d",carpeta,i);
        numImagenes[i]= HGS_ImagenCuentaImagenes(nombre);
    }

    return numImagenes;

}

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

static void HGS_ImagenLiberaImagenes(SDL_Texture *** imagenes, int maxAnim, int * maxImag){

    for (int i=0; i<maxAnim; i++){
        for (int j=0; j<maxImag[i]; j++){
            SDL_free(imagenes[i][j]);
        }
        delete imagenes[i];
    }
    delete imagenes;

}

HGS_Imagen::HGS_Imagen(char * carpeta, HGS_Ventana * ventana){

    assert(carpeta!=NULL);
    assert(ventana!=NULL);

    this->ventana= ventana;
    this->maxAnimaciones= HGS_ImagenCuentaCarpetas(carpeta);
    this->maxImagenes= HGS_ImagenCuentaTodasImagenes(carpeta,this->maxAnimaciones);
    this->imagenes= HGS_ImagenLeerImagenes(carpeta,ventana,this->maxAnimaciones,this->maxImagenes);

}

HGS_Imagen::~HGS_Imagen(){

    HGS_ImagenLiberaImagenes(this->imagenes,this->maxAnimaciones,this->maxImagenes);
    delete this->maxImagenes;

}

int HGS_Imagen::cogerNumAnimaciones(){

    return this->maxAnimaciones;

}

int HGS_Imagen::cogerNumImagenes(int animacion){

    assert(animacion>=0 && animacion<this->maxAnimaciones);

    return this->maxImagenes[animacion];

}


void HGS_Imagen::dibuja(double x, double y, double w, double h, int animacion, int imagen){

    assert(animacion>=0 && animacion<this->maxAnimaciones);
    assert(imagen>=0 && imagen<this->maxImagenes[animacion]);

    this->ventana->dibujaImagen(this->imagenes[animacion][imagen],x,y,w,h);

}
