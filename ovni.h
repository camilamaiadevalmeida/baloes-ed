#ifndef _OVNI_H_
#define _OVNI_H_
#include <stdbool.h>
#include "lista.h"

/** Um OVNI é uma estrutura que contém um id, um item, uma checagem de envio e um tipo.
 * O tipo pode ser um circulo, um retangulo, uma linha ou um texto.
 * O item é um ponteiro para a estrutura que representa o objeto.
 * O id é um inteiro que identifica o objeto.
 */
typedef void* ovni;

/** Cria um ovni com os parametros passados
 * @param id - id do ovni
 * @param item - item do ovni
 * @param envio - checagem de envio do ovni
 * @param tipo - tipo do ovni
 * @return - retorna um ovni
 */
ovni *createOvni(int id, void *item, char tipo);

/** Define o id do ovni
 * @param o - ovni
 * @param id - id do ovni
 */
void ovniSetId(ovni o, int id);

/** Define o item do ovni
 * @param o - ovni
 * @param item - item do ovni
 */
void ovniSetItem(ovni o, void *item);

/** Define o tipo do ovni
 * @param o - ovni
 * @param tipo - tipo do ovni
 */
void ovniSetTipo(ovni o, char tipo);

/** Define a checagem de envio do ovni
 * @param o - ovni
 * @param envio - checagem de envio do ovni
 */
void ovniSetEnvio(ovni o, bool envio);

/** Libera a memoria alocada para o ovni
 * @param o - ovni
 */
void ovniFree(ovni o);

/** Retorna o id do ovni
 * @param o - ovni
 * @return - retorna o id do ovni
 */
int ovniGetId(ovni o);

/** Retorna o item do ovni
 * @param o - ovni
 * @return - retorna o item do ovni
 */
void *ovniGetItem(ovni o);

/** Retorna o tipo do ovni
 * @param o - ovni
 * @return - retorna o tipo do ovni
 */
char *ovniGetTipo(ovni o);

/** Retorna a checagem de envio do ovni
 * @param o - ovni
 * @return - retorna a checagem de envio do ovni
 */
bool ovniGetEnvio(ovni o);

/** Retorna o tipo do ovni
 * @param o - ovni
 * @return - retorna o tipo do ovni
 */
char *ovniGetTipo(ovni o);

/** Retorna o tipo do ovni
 * @param o - ovni
 * @return - retorna o tipo do ovni
 */
char *ovniGetTipo(ovni o);

/** Retorna o tipo do ovni
 * @param o - ovni
 * @return - retorna o tipo do ovni
 */
char *ovniGetTipo(ovni o);

/** Destroi o ovni*/
void destroiOvni(Item o);




#endif
