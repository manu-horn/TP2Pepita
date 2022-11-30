#ifndef TP_JUEGODEPALABRAS_JUEGO_H
#define TP_JUEGODEPALABRAS_JUEGO_H

#include "Variante.h"


class Juego {
public:
    Juego(Nat numJugadores, const Variante& var, Repositorio rep);
    void ubicar(Ocurrencia o);
    const Variante obtenerVariante() const;
    const Nat obtenerTurno() const;
    const Nat obtenerPuntaje(Nat j);
    const bool EsjugadaValida(Ocurrencia o);
    const Letra fichaEnPosicion(Nat fila , Nat columna) const;
    const bool hayFicha(Nat fila, Nat columna) const;
    const Nat cuantasDeEstaTiene(Letra l, Nat idCliente) const;
    const Nat tamanoTab() const;
    const bool tieneFichas(Ocurrencia o, Nat idCliente) const;
    const Nat cantidadLetrasOcurrencia(Letra l, Ocurrencia o) const;
    const Nat puntajeAnterior(Nat id)const;
    multiset<Letra> reponerN(Nat n,Nat id);
    const Repositorio dameRep() const;
    const Nat numJugadores() const;
    const
private:
    struct Casillero{
        Letra letra;
        Nat   turnoJugado;
        bool  ocupado;
    };
    using Tablero = vector<vector<Casillero>>;
    struct jugador{
        using Mano = vector<int>;
        Mano mano;
        Nat puntaje;
        Ocurrencia fichasQuePusoDesde;

    };
    using Jugadores = vector<jugador>;



    Jugadores jugadores;
    Nat numJug;
    Nat turnoActual;
    Tablero tablero;
    const Variante& v;
    Repositorio _rep;



    Jugadores repartirFichas(const Variante v, Nat cantJugadores, Repositorio rep);
    Tablero crearTablero(Nat tamano);
    void agregarPalabraHorizontal(ConjTrie conjPalabras, pair<Nat, Nat> prim, pair<Nat, Nat> ult);
    void agregarPalabraVertical(ConjTrie conjPalabras, pair<Nat, Nat> arr, pair<Nat, Nat> abj);
    Nat puntajeTotal(ConjTrie conjPalabras);
    const bool enRango(Nat i, Nat j);
    const bool Horizontal(Ocurrencia o) const;
    const bool Vertical(Ocurrencia o) const;
    const bool sonContiguas(pair<Nat, Nat> prim, pair<Nat, Nat> ult, bool horizontal);
};

#endif //TP_JUEGODEPALABRAS_JUEGO_H