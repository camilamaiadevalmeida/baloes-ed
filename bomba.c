#include "bomba.h"

struct coordenadas
{
    double x;
    double y;
};

double distanciaEntrePontos(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

struct coordenadas calcularCoordenadas(double x, double y, double r, double angulo)
{
    struct coordenadas coord;
    coord.x = x + r * cos(angulo);
    coord.y = y + r * sin(angulo);
    return coord;
}

bool atirarBomba(double xcaca, double ycaca, double distancia, double angulo, char tipo, Lista L, ArqCmds svg, FILE* txt){
    struct coordenadas coord = calcularCoordenadas(xcaca, ycaca, distancia, angulo);
    double raio;
    switch (tipo)
    {
    case 'A':
        raio = 3;
        break;
    case 'B':
        raio = 5;
        break;
    case 'C':
        raio = 7;
        break;
    }
    Posic atual = getFirst(L);
    while (atual != NIL)
    {
        switch (ovniGetTipo(get(L, atual)))
        {
            case 'c':
                if (distanciaEntrePontos(coord.x, coord.y, circleGetCx(ovniGetItem(get(L, atual))), circleGetCy(ovniGetItem(get(L, atual))) <= raio))
                {
                    fprintf(txt, "Bomba %c atingiu circulo de x=%lf, y=%lf, cor b=%s, cor p=%s, raio=%d e id=%d\n", tipo, circleGetCx(ovniGetItem(get(L, atual))),circleGetCy(ovniGetItem(get(L, atual))), circleGetCorb(ovniGetItem(get(L, atual))),circleGetCorp(ovniGetItem(get(L, atual))) ,circleGetR(ovniGetItem(get(L, atual)))) ,circleGetId(ovniGetItem(get(L, atual)));
                    remover(L, atual, destroiOvni);
                    return true;
                }
                break;
            case 'r':
                if (distanciaEntrePontos(coord.x, coord.y, retanguloGetx(ovniGetItem(get(L, atual))),retanguloGety(ovniGetItem(get(L, atual)))) <= raio)
                {
                    fprintf(txt, "Bomba %c atingiu retangulo de x=%d, y=%d, w=%d, h=%d, cor b=%s, cor p=%s, id=%d\n", tipo,retanguloGetx(ovniGetItem(get(L, atual))),retanguloGety(ovniGetItem(get(L, atual))) ,retanguloGeti(ovniGetItem(get(L, atual))));
                    remover(L, atual, destroiOvni);
                    return true;
                }
                break;
            case 'l':
                if (distanciaEntrePontos(coord.x, coord.y, linhaGetx1(ovniGetItem(get(L, atual))),linhaGety1(ovniGetItem(get(L, atual)))) <= raio || distanciaEntrePontos(coord.x, coord.y, linhaGetx2(ovniGetItem(get(L, atual))),linhaGety2(ovniGetItem(get(L, atual)))) <= raio)
                {
                    fprintf(txt, "Bomba %c atingiu linha de x1=%d, y1=%d, x2=%d, y2=%d, cor=%s, id=%d\n", tipo,linhaGetx1(ovniGetItem(get(L, atual))),linhaGety1(ovniGetItem(get(L, atual))), linhaGetx2(ovniGetItem(get(L, atual))), linhaGety2(ovniGetItem(get(L, atual))), linhaGetcor(ovniGetItem(get(L, atual))), linhaGeti(ovniGetItem(get(L, atual))));
                    remover(L, atual, destroiOvni);
                    return true;
                }
                break;
            case 't':
                if (distanciaEntrePontos(coord.x, coord.y, textoGetX(ovniGetItem(get(L, atual))),textoGetY(ovniGetItem(get(L, atual)))) <= raio)
                {
                    fprintf(txt, "Bomba %c atingiu texto de x=%d, y=%d, cor b=%s, cor p=%s, conteudo=%s, fonte=%s, tamanho=%s, peso=%s, rotação=%s, id=%d\n", tipo,textoGetX(ovniGetItem(get(L, atual))),textoGetY(ovniGetItem(get(L, atual))), textoGetCorb(ovniGetItem(get(L, atual))),textoGetCorp(ovniGetItem(get(L, atual))), textoGetConteudo(ovniGetItem(get(L, atual))), textoGetFonte(ovniGetItem(get(L, atual))), textoGetTamanho(ovniGetItem(get(L, atual))), textoGetPeso(ovniGetItem(get(L, atual))), textoGetRotacao(ovniGetItem(get(L, atual))), textoGetId(ovniGetItem(get(L, atual))));
                    return true;
                }
                break;
        }
        atual = getNext(L, atual);
    }

}