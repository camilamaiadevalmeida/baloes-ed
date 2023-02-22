#include "learquivo.h"

struct LeArquivo
{
    FILE *arquivo;
    char *nome;
    char *modo;
};

ArqCmds abreArquivoCmd(char *fn)
{
    struct LeArquivo *ac = malloc(sizeof(struct LeArquivo));
    ac->nome = fn;
    ac->modo = "r";
    ac->arquivo = fopen(fn, ac->modo);
    return ac;
}

bool leLinha(ArqCmds ac, char *buf, int bufLen)
{
    struct LeArquivo *pointer = ac;
    if (fgets(buf, bufLen, pointer->arquivo) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

void fechaArquivoCmd(ArqCmds ac)
{
    struct LeArquivo *pointer = ac;
    fclose(pointer->arquivo);
}


void getParametroI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen)
{
    struct LeArquivo *pointer = ac;
    char *token = strtok(buf, " ");
    int j = 0;
    while (token != NULL)
    {
        if (j == i)
        {
            strcpy(paramI, token);
            break;
        }
        token = strtok(NULL, " ");
        j++;
    }
}

void getParametroDepoisI(ArqCmds ac, char *buf, int i, char *paramI, int paramILen)
{
    struct LeArquivo *pointer = ac;
    char *token = strtok(buf, " ");
    int j = 0;
    while (token != NULL)
    {
        if (j == i)
        {
            strcpy(paramI, token);
            while (token != NULL)
            {
                token = strtok(NULL, " ");
                if (token != NULL)
                {
                    strcat(paramI, " ");
                    strcat(paramI, token);
                }
            }
            break;
        }
        token = strtok(NULL, " ");
        j++;
    }
}




