#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct Circle Circle;

Circle *createCircle(int id, double x, double y, double r, char *fill);

void circleSetId(Circle *cir, int id);

void circleSetCx(Circle *cir, double x);

void circleSetCy(Circle *cir, double y);

void circleSetR(Circle *cir, double r);

void circleSetFill(Circle *cir, char *fill);

void circleFree(Circle *cir);

int circleGetId(Circle *cir);

double circleGetCx(Circle *cir);

double circleGetCy(Circle *cir);

double circleGetR(Circle *cir);

char *circleGetFill(Circle *cir);

#endif