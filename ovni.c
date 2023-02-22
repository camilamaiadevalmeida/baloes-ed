#include "ovni.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

struct Ovni
{
    Item info;
    int id;
    char tipo;
    bool envio;
};

ovni *createOvni(int id, char tipo, bool envio, Item info)
{
    struct Ovni *ov = malloc(sizeof(struct Ovni));
    ovniSetid(ov, id);
    ovniSettipo(ov, tipo);
    ovniSetenvio(ov, envio);
    ovniSetinfo(ov, info);
    return ov;
}

void ovniSetId(ovni ov, int id)
{
    struct Ovni *pointer = ov;
    pointer->id = id;
}

void ovniSetTipo(ovni ov, char tipo)
{
    struct Ovni *pointer = ov;
    pointer->tipo = tipo;
}

void ovniSetEnvio(ovni ov, bool envio)
{
    struct Ovni *pointer = ov;
    pointer->envio = envio;
}

void ovniSetInfo(ovni ov, Item info)
{
    struct Ovni *pointer = ov;
    pointer->info = info;
}

int ovniGetId(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->id;
}

char ovniGetTipo(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->tipo;
}

bool ovniGetEnvio(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->envio;
}

Item ovniGetInfo(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->info;
}

void ovniSetItem(ovni o, void *item)
{
    struct Ovni *pointer = o;
    pointer->info = item;
}

Item ovniGetItem(ovni o)
{
    struct Ovni *pointer = o;
    return pointer->info;
}

void destroiOvni(Item ov)
{
    struct Ovni *pointer = ov;
    switch (pointer->tipo)
    {
    case 'c':
        circleFree(pointer->info);
        break;
    case 'l':
        linhaFree(pointer->info);
        break;
    case 'r':
        retanguloFree(pointer->info);
        break;
    case 't':
        textoFree(pointer->info);
        break;
    }
    free(pointer);
}



