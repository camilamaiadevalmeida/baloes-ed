#ifndef _BOMBA_H_
#define _BOMBA_H_
#include <stdbool.h>
#include "math.h"
#include "svg.h"
#include "learquivo.h"
#include "lista.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "ovni.h"
#include "stdio.h"

/* Uma bomba pode ser atirada por um Caça com o objetivo de derrubar um balão.
As bombas funcionam por detonação por afastamento. 
Existem três tipos de bombas: A, B e C.*/

/* A função atirar bomba */
bool atirarBomba(double xcaca, double ycaca, double distancia, double angulo, char tipo, Lista L, ArqCmds svg, FILE* txt);



#endif