#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* circulo;

/*
Cria um circulo com os parametros passados
*/
circulo *createCircle(int id, double x, double y, double r, char *fill);
/*
Define o id do circulo
*/
void circleSetId(circulo *cir, int id);
/*
define a coordenada x do circulo
*/
void circleSetCx(circulo *cir, double x);
/*
define a coordenada y do circulo
*/
void circleSetCy(circulo *cir, double y);
/*
define o raio do circulo
*/
void circleSetR(circulo *cir, double r);
/*
define a cor de preenchimento do circulo
*/
void circleSetFill(circulo *cir, char *fill);
/*
Libera a memoria alocada para o circulo
*/
void circleFree(circulo *cir);
/*
Retorna o id do circulo
*/
int circleGetId(circulo *cir);
/*
Retorna a coordenada x do circulo
*/
double circleGetCx(circulo *cir);
/*
Retorna a coordenada y do circulo
*/
double circleGetCy(circulo *cir);
/*
Retorna o raio do circulo
*/
double circleGetR(circulo *cir);
/*
Retorna a cor de preenchimento do circulo
*/
char *circleGetFill(circulo *cir);
#endif