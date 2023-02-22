#ifndef _LE_ARQUIVOS__
#define _LE_ARQUIVOS__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* EXERCICIO: escrever a descricao do modulo e das operacoes */
// arquivo organizado em linhas: // aaaa bbb cccc dddd eeee

/* Este modulo prove funções para a leitura de arquivos de texto. */

typedef void *ArqCmds;

// A função abreArquivoCmd abre o arquivo fn para leitura.
ArqCmds abreArquivoCmd(char *fn);

// A função leLinha lê uma linha do arquivo e armazena no buffer.
bool leLinha (ArqCmds ac,char *buf, int bufLen);
// aaaa bbbb ccccc dddd eeee

/* A função getParametroI tem como objetivo extrair 
o i-ésimo parâmetro de uma linha lida de um arquivo 
de comandos e armazená-lo em um buffer */
void getParametroI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen);
// i==2: ccccc

/* A função getParametroDepoisI tem como objetivo extrair
o i-ésimo parâmetro de uma linha lida de um arquivo
de comandos e armazená-lo em um buffer */
void getParametroDepoisI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen);
// i==2: ccccc dddd eeee

// A função fechaArquivoCmd fecha o arquivo especificado.
void fechaArquivoCmd(ArqCmds ac);

#endif
