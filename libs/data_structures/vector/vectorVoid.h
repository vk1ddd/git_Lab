//
// Created by ivanu on 13.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#ifndef GIT_LAB_VECTORVOID_H
#define GIT_LAB_VECTORVOID_H

typedef  struct  vectorVoid  {
    void  *data; //  указатель  на  нулевой  элемент  вектора
    size_t  size; //  размер  вектора
    size_t  capacity; //  вместимость  вектора
    size_t  baseTypeSize; //  размер  базового  типа
} vectorVoid;

vectorVoid  createVectorV(size_t  n,  size_t  baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void  shrinkToFitV(vectorVoid  *v);

void  clearV(vectorVoid  *v);

void  deleteVectorV(vectorVoid  *v);

#endif //GIT_LAB_VECTORVOID_H
