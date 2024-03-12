//
// Created by ivanu on 13.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid a;
    a.capacity = n;
    a.size = 0;
    a.data = malloc(baseTypeSize * n);

    if (a.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return a;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else if (v->size > newCapacity) {
        v->size = newCapacity;
    } else if (v->capacity < newCapacity) {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    }

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->capacity = newCapacity;
}

void  shrinkToFitV(vectorVoid  *v){
    reserveV(v, v->size);
}

void  clearV(vectorVoid  *v){
    v->size = 0;
}

void  deleteVectorV(vectorVoid  *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}
