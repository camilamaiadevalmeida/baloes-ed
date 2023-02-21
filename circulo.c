#include "circulo.h"

struct Circle
{
    int id;
    double cx;
    double cy;
    double r;
    char *fill;
};

Circle *createCircle(int id, double x, double y, double r, char *fill)
{
    Circle *cir = malloc(sizeof(Circle));
    cir->id = id;
    cir->cx = x;
    cir->cy = y;
    cir->r = r;
    cir->fill = fill;
    return cir;
}

void circleSetId(Circle *cir, int id)
{
    cir->id = id;
}

void circleSetCx(Circle *cir, double cx)
{
    cir->cx = cx;
}

void circleSetCy(Circle *cir, double cy)
{
    cir->cy = cy;
}

void circleSetR(Circle *cir, double r)
{
    cir->r = r;
}

void circleSetFill(Circle *cir, char *fill)
{
    cir->fill = fill;
}

void circleFree(Circle *cir)
{
    free(cir);
}

int circleGetId(Circle *cir)
{
    return cir->id;
}

double circleGetCx(Circle *cir)
{
    return cir->cx;
}

double circleGetCy(Circle *cir)
{
     return cir->cy;
}

double circleGetR(Circle *cir)
{
    return cir->r;
}

char *circleGetFill(Circle *cir)
{
    return cir->fill;
}