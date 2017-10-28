#ifndef HGS_LISTA_H_INCLUDED
#define HGS_LISTA_H_INCLUDED

#include <iostream>
using namespace std;

template <class T> class HGS_Lista;


template <class T> class HGS_ElementoLista{

    friend class HGS_Lista<T>;

    private:
        HGS_Lista<T> * lista;
        T elemento;
        HGS_ElementoLista<T> * sig;
        HGS_ElementoLista<T> * ant;

    public:
        HGS_ElementoLista(T elemento);
        T cogerContenido();
        HGS_ElementoLista<T> * cogerSiguiente();
        HGS_ElementoLista<T> * cogerAnterior();
        HGS_Lista<T> * cogerLista();

};


template <class T> class HGS_Lista{

    HGS_ElementoLista<T> * primerElemento;
    HGS_ElementoLista<T> * ultimoElemento;
    int numElementos;

    public:

        HGS_Lista();
        void insertaElementoAntes(HGS_ElementoLista<T> * it, HGS_ElementoLista<T> * elemento);
        void insertaElementoDespues(HGS_ElementoLista<T> * it, HGS_ElementoLista<T> * elemento);
        void insertarElementoInicio(HGS_ElementoLista<T> * elemento);
        void insertarElementoFinal(HGS_ElementoLista<T> * elemento);
        void extraerElemento(HGS_ElementoLista<T> * elemento);

};


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------


template <class T>
HGS_ElementoLista<T>::HGS_ElementoLista(T elemento){

    this->lista= NULL;
    this->elemento= elemento;
    this->sig= NULL;
    this->ant= NULL;

}

template <class T>
T HGS_ElementoLista<T>::cogerContenido(){

    return this->elemento;

}

template <class T>
HGS_ElementoLista<T> * HGS_ElementoLista<T>::cogerSiguiente(){

    return this->sig;

}

template <class T>
HGS_ElementoLista<T> * HGS_ElementoLista<T>::cogerAnterior(){

    return this->ant;

}

template <class T>
HGS_Lista<T> * HGS_ElementoLista<T>::cogerLista(){

    return this->lista;

}




//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------




template <class T>
HGS_Lista<T>::HGS_Lista(){

    this->primerElemento= NULL;
    this->ultimoElemento= NULL;
    this->numElementos= 0;

}

template <class T>
void HGS_Lista<T>::insertaElementoAntes(HGS_ElementoLista<T> * it, HGS_ElementoLista<T> * elemento){

    if (elemento==NULL || elemento->lista!=NULL) return;

    if (it!=NULL){
        if (it->lista!=this) return;

        HGS_ElementoLista<T> * izq= it->ant;
        elemento->sig= it;
        elemento->ant= izq;
        it->ant= elemento;
        if (izq!=NULL){
            izq->sig= elemento;
        }
        else{
            this->primerElemento= elemento;
        }
    }
    else{
        this->insertarElementoInicio(elemento);
    }

}

template <class T>
void HGS_Lista<T>::insertaElementoDespues(HGS_ElementoLista<T> * it, HGS_ElementoLista<T> * elemento){

    if (elemento==NULL || elemento->lista!=NULL) return;

    if (it!=NULL){
        if (it->lista!=this) return;

        HGS_ElementoLista<T> * der= it->sig;
        elemento->sig= der;
        elemento->ant= it;
        it->sig= elemento;
        if (der!=NULL){
            der->ant= elemento;
        }
        else{
            this->ultimoElemento= elemento;
        }
    }
    else{
        this->insertarElementoFinal(elemento);
    }

}

template <class T>
void HGS_Lista<T>::insertarElementoInicio(HGS_ElementoLista<T> * elemento){

    if (this->primerElemento==NULL){
        this->primerElemento= elemento;
        this->ultimoElemento= elemento;
        elemento->sig= NULL;
    }
    else{
        elemento->sig=this->primerElemento;
        this->primerElemento= elemento;
    }
    elemento->ant= NULL;
    this->numElementos++;

}

template <class T>
void HGS_Lista<T>::insertarElementoFinal(HGS_ElementoLista<T> * elemento){

    if (this->primerElemento==NULL){
        this->primerElemento= elemento;
        this->ultimoElemento= elemento;
        elemento->ant= NULL;
    }
    else{
        elemento->ant= this->ultimoElemento;
        this->ultimoElemento= elemento;
    }
    elemento->sig= NULL;
    this->numElementos++;

}

template <class T>
void HGS_Lista<T>::extraerElemento(HGS_ElementoLista<T> * elemento){

    if (elemento->lista!=this) return;

    elemento= this->primerElemento;
    HGS_ElementoLista<T> * izq= elemento->ant;
    HGS_ElementoLista<T> * der= elemento->sig;
    if (izq!=NULL){
        izq->sig= der;
    }
    else{
        this->primerElemento= der;
    }
    if (der!=NULL){
        der->ant= izq;
    }
    else{
        this->ultimoElemento= izq;
    }

    this->numElementos--;

    return elemento;

}

#endif // HGS_LISTA_H_INCLUDED
