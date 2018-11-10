#include <iostream>
#include "matrix.h"

int main() {
	const int size = 3;
	Matrix* matrix = createMatrix(size);

	set(matrix, 1, 0, 0); set(matrix, 2, 0, 1); set(matrix, 3, 0, 2);
	set(matrix, 4, 1, 0); set(matrix, 5, 1, 1); set(matrix, 6, 1, 2);
	set(matrix, 3, 2, 0); set(matrix, 2, 2, 1); set(matrix, 1, 2, 2);

	print(matrix);

	int* result = rowPermutations(matrix);
	std::cout << "result = { " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << result[i] << " ";
	}
	std::cout << "}" << std::endl;
	delete[] result;

	deleteMatrix(matrix);

	return 0;
}