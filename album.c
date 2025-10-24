#include <string.h>

int cmpValueAlbum(void *a, void *b){
    return ((Album*)a)->valor == *((float*)b);
}

int cmpNameAlbum(void *a, void *b){
    return !strcmp( ((Album*)a)->nome, (char*)b );
}

int cmpIdAlbum(void *a, void *b){
    return ((Album*)a)->id == *((int*)b);
}

