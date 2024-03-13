//
// Created by ivanu on 13.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef GIT_LAB_VECTORVOID_H
#define GIT_LAB_VECTORVOID_H

typedef struct vectorVoid {
    void *data; //  указатель  на  нулевой  элемент  вектора
    size_t size; //  размер  вектора
    size_t capacity; //  вместимость  вектора
    size_t baseTypeSize; //  размер  базового  типа
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

//записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу
void  setVectorValueV(vectorVoid  *v,  size_t  index,  void  *source);

void  popBackV(vectorVoid  *v);

void  pushBackV(vectorVoid  *v,  void  *source);

#endif //GIT_LAB_VECTORVOID_H
