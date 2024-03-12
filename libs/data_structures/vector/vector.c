//
// Created by ivanu on 11.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "vector.h"

vector createVector(size_t n) {
    vector a;
    a.capacity = n;
    a.size = 0;
    a.data = malloc(sizeof(int) * n);

    if (a.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return a;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->capacity = 0;
        v->size = 0;
    } else if (v->size > newCapacity) {
        v->data = realloc(&v, newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else {
        v->data = realloc(&v, newCapacity);
        v->capacity = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
}

vector clear(vector  *v){
    return (vector){v->data, 0, v->capacity};
}

void  shrinkToFit(vector  *v){
    reserve(v, v->size);
}

void  deleteVector(vector  *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}
