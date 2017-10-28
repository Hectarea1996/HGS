#ifndef HGS_LISTA_H_INCLUDED
#define HGS_LISTA_H_INCLUDED

#include <cassert>
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
        HGS_ElementoLista<T> * extraerElementoInicio();
        HGS_ElementoLista<T> * extraerElementoFinal();

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

    assert(elemento!=NULL);
    assert(elemento->lista==NULL);
    assert(it==NULL || it->lista==this);

    if (it!=NULL){
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

    elemento->lista= this;

}

template <class T>
void HGS_Lista<T>::insertaElementoDespues(HGS_ElementoLista<T> * it, HGS_ElementoLista<T> * elemento){

    assert(elemento!=NULL);
    assert(elemento->lista==NULL);
    assert(it==NULL || it->lista==this);

    if (it!=NULL){
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

    elemento->lista= this;

}

template <class T>
void HGS_Lista<T>::insertarElementoInicio(HGS_ElementoLista<T> * elemento){

    assert(elemento!=NULL);
    assert(elemento->lista==NULL);

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

    elemento->lista= this;

}

template <class T>
void HGS_Lista<T>::insertarElementoFinal(HGS_ElementoLista<T> * elemento){

    assert(elemento!=NULL);
    assert(elemento->lista==NULL);

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

    elemento->lista= this;

}

template <class T>
void HGS_Lista<T>::extraerElemento(HGS_ElementoLista<T> * elemento){

    assert(elemento!=NULL);
    assert(elemento->lista==this);

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

    elemento->lista= NULL;

    return elemento;

}

template <class T>
HGS_ElementoLista<T> * HGS_Lista<T>::extraerElementoInicio(){

    HGS_ElementoLista<T> * extraer= this->primerElemento;
    if (extraer!=NULL)
        this->extraerElemento(extraer);

    return extraer;

}

template <classT>
HGS_ElementoLista<T> * HGS_Lista<T>::extraerElementoFinal(){

    HGS_ElementoLista<T> * extraer= this->ultimoElemento;
    if (extraer!=NULL)
        this->extraerElemento(extraer);

    return extraer;

}




#endif // HGS_LISTA_H_INCLUDED
