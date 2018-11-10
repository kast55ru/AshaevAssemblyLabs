#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
	int size;
	int** matrix;
};

Matrix* createMatrix(int matrixSize);
void deleteMatrix(Matrix* matrix);
int get(Matrix* matrix, int i, int j);
void set(Matrix* matrix, int elem, int i, int j);
void print(Matrix* matrix);
int* rowPermutations(Matrix* matrix);