#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
	int size;
	int** matrix;
};

Matrix* createMatrix(int size);

void deleteMatrix(Matrix* matrix) {
	__asm {

	}
}

int get(Matrix* matrix, int i, int j) {
	__asm {

	}
}

void set(Matrix* matrix, int elem, int i, int j) {
	__asm {

	}
}

void print(Matrix* matrix) {
	__asm {

	}
}

int* rowPermutations(Matrix* matrix) {
	__asm {

	}
}