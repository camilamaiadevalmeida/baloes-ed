#ifndef _TEXTO_H
#define _TEXTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
TEXTO é um polígono que possui um ponto de origem no início, meio ou fim (âncora definida por x e y),
conteúdo, cor de borda, cor de preenchimento e estilo.
*/
typedef void *texto;

/**CREATE_TEXTO retorna um TEXTO;*/
texto createTexto(int id, double x, double y, char *corb, char *corp, char *conteudo, char *ancora, char *estilo);

/**TEXTO_SET_I recebe um TEXTO e um inteiro e seta o ID do TEXTO*/
void textoSetId(texto text, int id);

/**TEXTO_SET_ANCOR recebe um TEXTO e um char e seta a posição da ancora do TEXTO*/
void textoSetAncora(texto text, char *ancora);

/**TEXTO_SET_X recebe um TEXTO e um double e seta o x da ancora do TEXTO*/
void textoSetX(texto text, double x);

/**TEXTO_SET_Y recebe um TEXTO e um double e seta o y da ancora do TEXTO*/
void textoSetY(texto text, double y);

/**TEXTO_SET_CONTEUDO recebe um TEXTO e uma char* e seta o conteúdo do TEXTO*/
void textoSetConteudo(texto text, char *conteudo);

/**TEXTO_SET_CORB recebe um TEXTO e uma char* e seta a cor de borda do TEXTO*/
void textoSetCorb(texto text, char *corb);

/**TEXTO_SET_CORP recebe um TEXTO e uma char* e seta a cor de preenchimento do TEXTO*/
void textoSetCorp(texto text, char *corp);

/**TEXTO_GET_I recebe um TEXTO e retorna o ID do TEXTO*/
int textoGetI(texto text);

/**TEXTO_GET_ANCOR recebe um TEXTO e retorna a posição da ancora do TEXTO*/
char *textoGetAncora(texto text);

/**TEXTO_GET_X recebe um TEXTO e retorna o x da ancora do TEXTO*/
double textoGetX(texto text);

/**TEXTO_GET_Y recebe um TEXTO e retorna o y da ancora do TEXTO*/
double textoGetY(texto text);

/**TEXTO_GET_CONTEUDO recebe um TEXTO e retorna o conteúdo do TEXTO*/
char *textoGetConteudo(texto text);

/**TEXTO_GET_CORB recebe um TEXTO e retorna a cor de borda do TEXTO*/
char *textoGetCorb(texto text);

/**TEXTO_GET_CORP recebe um TEXTO e retorna a cor de preenchimento do TEXTO*/
char *textoGetCorp(texto text);

/**TEXTO_GET_ESTILO recebe um TEXTO e retorna o estilo do TEXTO*/
char *textoGetEstilo(texto text);

/**TEXTO_SET_ESTILO recebe um TEXTO e uma char* e seta o estilo do TEXTO*/
void textoSetEstilo(texto text, char *estilo);

/**TEXTO_FREE recebe um TEXTO e libera a memória alocada para o TEXTO*/
void textoFree(texto text);

#endif