#include "Fachada_Juego.h"


map<Letra, Nat> vectAMap(const Variante& v)
{
    // para cada letra del abc, hago ord(letra), y la agrego en el dic
    map<Letra, Nat> puntajes;
    for (int i = 0; i < TAMANIO_ALFABETO; i++)
    {
        Letra l = inversaDeOrd(i);
        puntajes[l] = v.puntajeLetra(l);
    }
    return puntajes;
}

set<Palabra> listaASet(const list<Palabra>& pals)
{
    set<Palabra> palabrasLegitimas;
    for (Palabra p : pals)
    {
        palabrasLegitimas.insert(p);
    }
    return palabrasLegitimas;
}


Fachada_Juego::Fachada_Juego(Nat k, const Fachada_Variante &v, const Repositorio &r): juego(k,v.daVariante(),r){

    list<Palabra> palabras = juego.obtenerVariante().palabras();
    map<Letra, Nat> puntajes = vectAMap(juego.variante());
    set<Palabra> palabrasLegitimas = listaASet(palabras);
    fachaVar = new Fachada_Variante(juego.variante().tableroSize(), juego.variante().cantFichas(), puntajes, palabrasLegitimas);
}

void Fachada_Juego::ubicar(const Ocurrencia &o) {
    juego.ubicar(o);
}

IdCliente Fachada_Juego::turno() {
    return juego.obtenerTurno();
}

const Fachada_Variante &Fachada_Juego::variante() {
    return fachaVar;
}

bool Fachada_Juego::jugadaValida(const Ocurrencia &o) {
    return juego.EsjugadaValida(o);
}

bool Fachada_Juego::hayLetra(Nat x, Nat y) {
    return juego.hayFicha(x,y);
}

Letra Fachada_Juego::letra(Nat i, Nat j) {
    return juego.fichaEnPosicion(i,j);
}

Nat Fachada_Juego::puntaje(IdCliente id) {
    return juego.obtenerPuntaje(id);
}

Nat Fachada_Juego::cantFicha(IdCliente id, Letra l) {
    return juego.cuantasDeEstaTiene(l,id);
}