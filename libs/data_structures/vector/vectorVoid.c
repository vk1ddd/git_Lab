//
// Created by ivanu on 13.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid a;
    a.capacity = n;
    a.size = 0;
    a.data = malloc(baseTypeSize * n);
    a.baseTypeSize = baseTypeSize;

    if (a.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return a;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
    } else if (v->size > newCapacity) {
        v->size = newCapacity;
    } else if (v->capacity < newCapacity) {
        void *newData = realloc(v->data, v->baseTypeSize * newCapacity);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = newData;
    }

    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "index out of bounds");
        exit(1);
    }
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "index out of bounds");
        exit(1);
    }
    memcpy((char *)v->data + index * v->baseTypeSize, source, v->baseTypeSize);
}

void  popBackV(vectorVoid  *v){
    if (v->size == 0) {
        fprintf(stderr, "Error: vector is empty");
        exit(1);
    }
    v->size--;
}

void  pushBackV(vectorVoid  *v,  void  *source){
    if (v->size >= v->capacity) {
        size_t newCapacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        reserveV(v, newCapacity);
    }
    memcpy((char*)v->data + v->size * v->baseTypeSize, source, v->baseTypeSize);
    v->size++;
}