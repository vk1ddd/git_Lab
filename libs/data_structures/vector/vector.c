//
// Created by ivanu on 11.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
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
        v->size = 0;
    } else if (v->size > newCapacity) {
        v->data = realloc(v->data, newCapacity);
        v->size = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else {
        v->data = realloc(v->data, newCapacity);

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    v->capacity = newCapacity;
}

vector clear(vector *v) {
    return (vector) {v->data, 0, v->capacity};
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size < v->capacity) {
        v->data[v->size] = x;
        v->size++;
    } else {
        size_t size = v->size == (0 || NULL) ? 1 : 2 * v->size;
        reserve(v, size);
        v->data[v->size] = x;
        v->size++;
    }
}

void popBack(vector *v){
    if (v->size == 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size = v->size - 1;
}

