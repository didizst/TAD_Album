#ifndef _GCOFO_H_
#define _GCOFO_H_


typedef struct _gcofo_ {
    int numItens;
    int maxItens;
    int cur;
    void **item;
} gCofo;

gCofo *gcofCreate( int max_itens );
int gcofInsert(gCofo *gc, void *item );
void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *) );
void *gcofQuery(gCofo *c, void *key, int (*cmp)(void *, void * ) );
int gcofDestroy (gCofo *gc);
int gcofClean(gCofo* gc);

#endif
