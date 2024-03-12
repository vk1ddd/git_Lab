//
// Created by ivanu on 11.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifndef GIT_LAB_VECTOR_H
#define GIT_LAB_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//создание вектора (задает капасити)
vector createVector(size_t n);

//перевыделяет память для вектора (изменяет капасити)
void  reserve(vector  *v,  size_t  newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память
struct vector clear(vector  *v);

//освобождает  память,  выделенную  под неиспользуемые элементы
void  shrinkToFit(vector  *v);

//освобождает память, выделенную вектору
void  deleteVector(vector  *v);

#endif //GIT_LAB_VECTOR_H
