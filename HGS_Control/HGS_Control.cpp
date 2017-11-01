
#include "HGS_Control.h"


double * HGS_Control::cogerFactorLambda(){

    return &this->factorLambda;

}

double HGS_Control::cogerFPS(){

    return this->fps;

}

void HGS_Control::controlarFactorLambda(){

    static long ciclosAnt= 0;
    static long ciclosAct= 0;
    static int ciclos= 500000;

    ciclosAct= SDL_GetTicks();

    if (ciclosAct!=ciclosAnt){
        this->fps= (1000.0/(double)(ciclosAct-ciclosAnt))*(double)ciclos;
        this->factorLambda= 1.0/this->fps;
        ciclosAnt= ciclosAct;
        ciclos=1;
    }
    else ciclos++;

}
