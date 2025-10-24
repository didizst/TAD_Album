#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include "gCofo.h"
#include "album.h"

gCofo *gcofCreate( int max_itens )
{   gCofo *gc;
    if ( max_itens > 0) {
        gc = (gCofo *) malloc(sizeof(gCofo)*1);
        if ( gc != NULL ) {
            gc->item = (void **) malloc (sizeof(void *)*max_itens);
            if ( gc->item != NULL) {
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc-> cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gcofDestroy (gCofo *gc){
    if ( gc != NULL ) {
        if ( gc->numItens == 0 ) {
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gcofInsert(gCofo *gc, void *item )
{
    if ( gc != NULL ) {
        if ( gc->numItens < gc->maxItens) {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void * ) )
{
    void * data; int i, stat;
    if ( c != NULL ) {
        if ( c->numItens > 0 ){
            i = 0;
            while (i < c->numItens) {
                stat = cmp(c->item[i], key);
                if (stat == TRUE) {
                    data = c->item[i];
                    return data;
                }
                i++;
            }
        }
    }
    return NULL;
}

void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *) )
{
    int i;int j; void *data; int stat;
    if ( c != NULL) {
        if (c->numItens > 0 ) {
            i = 0;
            stat = FALSE;
            while ( i < c->numItens ) {
                stat = cmp (c->item[i], key);
                if (stat == TRUE) {
                    data = c->item[i];
                    for (j = i; j < c->numItens - 1; j++) {
                        c->item[j] = c->item[j+1];
                    }
                    c->numItens--;
                    return data;
                }
                i++;
            }
        }
    }
    return NULL;
}

int gcofClean(gCofo* gc){
    int i, j;
    if (gc != NULL){
        for (i = 0; i < gc->numItens; i++){
            free(gc->item[i]);
        }
        gc->numItens = 0;
        return TRUE;
    }
    return FALSE;
}