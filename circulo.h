#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct Circle Circle;

Circle *createCircle(int id, double x, double y, double r, char *fill);
/*
Cria um circulo com os parametros passados
*/
void circleSetId(Circle *cir, int id);
/*
Define o id do circulo
*/
void circleSetCx(Circle *cir, double x);
/*
define a coordenada x do circulo
*/
void circleSetCy(Circle *cir, double y);
/*
define a coordenada y do circulo
*/
void circleSetR(Circle *cir, double r);
/*
define o raio do circulo
*/
void circleSetFill(Circle *cir, char *fill);
/*
define a cor de preenchimento do circulo
*/
void circleFree(Circle *cir);
/*
Libera a memoria alocada para o circulo
*/
int circleGetId(Circle *cir);
/*
Retorna o id do circulo
*/
double circleGetCx(Circle *cir);
/*
Retorna a coordenada x do circulo
*/
double circleGetCy(Circle *cir);
/*
Retorna a coordenada y do circulo
*/
double circleGetR(Circle *cir);
/*
Retorna o raio do circulo
*/
char *circleGetFill(Circle *cir);
/*
Retorna a cor de preenchimento do circulo
*/
#endif