#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 9);
    assert(v.size == 1);
}

void test_pushBack_fullVector() {
    vector v = createVector(4);
    v.size = 4;
    pushBack(&v, 9);
    assert(v.size == 5 && v.capacity == 8);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        pushBack(&v, i);
    }

    for (int i = 0; i < 5; i++) {
        int *result = atVector(&v, i);
        assert(*result == i);
    }

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        pushBack(&v, i);
    }

    int *result = atVector(&v, 4);
    assert(*result == 4);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 42);

    int *result = back(&v);
    assert(*result == 42);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 42);

    int *result = front(&v);
    assert(*result == 42);

    deleteVector(&v);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}


int main() {
    //vector v = createVector(SIZE_MAX);
    test();

    /*size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushBackV(&v, &x);
    }

    for (int i = 0; i < 3; i++) {
        int *value = (int *) (((char *) v.data) + i * v.baseTypeSize);
        printf("%d", *value);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        printf("%d  ", x);
    }


    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(float));

    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f  ", x);
    }*/


    return 0;
}
