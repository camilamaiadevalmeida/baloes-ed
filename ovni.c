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

ovni createOvni(int id, char tipo, bool envio)
{
    struct Ovni *ov = malloc(sizeof(struct Ovni));
    ovniSetid(ov, id);
    ovniSettipo(ov, tipo);
    ovniSetenvio(ov, envio);
    return ov;
}

void ovniSetid(ovni ov, int id)
{
    struct Ovni *pointer = ov;
    pointer->id = id;
}

void ovniSettipo(ovni ov, char tipo)
{
    struct Ovni *pointer = ov;
    pointer->tipo = tipo;
}

void ovniSetenvio(ovni ov, bool envio)
{
    struct Ovni *pointer = ov;
    pointer->envio = envio;
}

void ovniSetinfo(ovni ov, Item info)
{
    struct Ovni *pointer = ov;
    pointer->info = info;
}

int ovniGetid(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->id;
}

char ovniGettipo(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->tipo;
}

bool ovniGetenvio(ovni ov)
{
    struct Ovni *pointer = ov;
    return pointer->envio;
}

Item ovniGetinfo(ovni ov)
{
    struct Ovni *pointer = ov;
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



