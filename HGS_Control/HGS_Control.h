#ifndef HGS_CONTROL_H_INCLUDED
#define HGS_CONTROL_H_INCLUDED


#include <SDL2/SDL.h>

class HGS_Control{

    private:

        double factorLambda;
        double fps;
        HGS_Control * control;

        HGS_Control(){
            this->factorLambda= 0;
            this->fps= 0;
            this->control= new HGS_Control();
        };


    public:

        static HGS_Control * HGS_ControlCogerControl();

        double * cogerFactorLambda();
        double cogerFPS();
        void controlarFactorLambda();

};

#endif // HGS_CONTROL_H_INCLUDED
