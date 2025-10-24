#ifndef ALBUM_H
#define ALBUM_H

typedef struct{
    char nome[30];
    int id;
    float valor;
}Album;

int cmpValueAlbum(void *a, void *b);
int cmpNameAlbum(void *a, void *b);
int cmpIdAlbum(void *a, void *b);

#endif
