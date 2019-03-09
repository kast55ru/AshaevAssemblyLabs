#include "matrix.h"

Matrix* createMatrix(int matrixSize) {
	__asm {
		mov		ebx, matrixSize

		cmp		ebx, 0
		jle		WRONG_MATRIX_SIZE

		mov		eax, ebx
		inc		eax
		imul	ebx
		inc		eax
		mov		ecx, 4
		imul	ecx

		push	eax
		call	malloc
		add		esp, 4

		xchg	eax, esi

		mov		ecx, ebx

		mov		[esi], ebx
	CYCLE:
		mov		eax, ecx
		imul	ebx
		mov		edx, 4
		imul	edx
		lea		edx, [esi+4 + eax]
		mov		[esi + ecx*4], edx
		loop CYCLE

		xchg	eax, esi
		jmp		END
	WRONG_MATRIX_SIZE:
		mov		eax, 0
	END:
	}
}

void deleteMatrix(Matrix* matrix) {
	__asm {
		mov		eax, matrix
		push	eax
		call	free
		add		esp, 4
	}
}

int get(Matrix* matrix, int i, int j) {
	__asm {
		mov		esi, matrix
		mov		ebx, i
		mov		ecx, j
		mov		edi, [esi]; size

		cmp		ebx, 0
		jl		END
		cmp		ecx, j
		jl		END
		cmp		ebx, edi
		jge		END
		cmp		ecx, edi
		jge		END

		mov		edx, [esi + 4 + ebx * 4]
		mov		eax, [edx + ecx * 4]
	END:
	}
}

void set(Matrix* matrix, int elem, int i, int j) {
	__asm {
		mov		esi, matrix
		mov		ebx, i
		mov		ecx, j
		mov		edi, [esi]; size

		cmp		ebx, 0
		jl		END
		cmp		ecx, j
		jl		END
		cmp		ebx, edi
		jge		END
		cmp		ecx, edi
		jge		END

		mov		edx, [esi+4 + ebx*4]

		mov		edi, elem
		mov		[edx + ecx*4], edi
	END:
	}
}

void print(Matrix* matrix) {
	const char* formatString = "%4d";
	const char* newLine = "\n";
	__asm {
		mov		esi, matrix
		mov		edi, [esi]; size
		dec		edi
		
		xor		ebx, ebx; i
		xor		ecx, ecx; j

	CYCLE:
		mov		edx, [esi + 4 + ebx * 4]
		push	ecx
		push	[edx + ecx * 4]
		push	dword ptr formatString
		call	printf
		add		esp, 8
		pop		ecx

		cmp		ecx, edi
		je		J_EQUALS_SIZE
		inc		ecx
		jmp		CYCLE
	J_EQUALS_SIZE:
		push	dword ptr newLine
		call	printf
		add		esp, 4
		cmp		ebx, edi
		je		END
		xor		ecx, ecx
		inc		ebx
		jmp		CYCLE
	END:
	}
}

int* rowPermutations(Matrix* matrix) {
	/*
	int* result = new int[matrix->size]{};

	for (int i = 0; i < matrix->size; i++) {
		for (int j = 0; j < matrix->size; j++) {
			if (i != j) {
				bool flag;
				for (int k = 0; k < matrix->size; k++) {
					flag = false;
					for (int l = 0; l < matrix->size; l++) {
						if (get(matrix, i, k) == get(matrix, j, l)) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						break;
					}
				}
				if (flag) {
					result[i] = 1;
					break;
				}
			}
		}
	}
	
	return result;
	*/
	__asm {
		mov		esi, matrix
		mov		edi, [esi]

		mov		eax, edi
		mov		ebx, 4
		imul	ebx
		
		push	eax
		call	malloc
		add		esp, 4

		mov		ecx, edi
		dec		ecx

	INIT_RESULT:
		mov[eax + ecx * 4], 0
		loop INIT_RESULT
		mov[eax + ecx * 4], 0

		push	eax

		mov		edx, 0
	CYCLE_I:
		cmp		edx, edi
		jge		END_CYCLE_I

		mov		ecx, 0
		CYCLE_J:
			cmp		ecx, edi
			jge		END_CYCLE_J
			
			cmp		edx, ecx
			je		I_EQUALS_J

			; bool flag;

			mov		ebx, 0
			CYCLE_K:
				cmp		ebx, edi
				jge		END_CYCLE_K
				
				; flag = false;

				mov		eax, 0
				CYCLE_L:
					cmp		eax, edi
					jge		END_CYCLE_L

					; if (get(matrix, i, k) == get(matrix, j, l))
						; flag = true
						; break;

					inc		eax
					jmp		CYCLE_L
				END_CYCLE_L:

				; if (!flag) { break; }
				
				inc		ebx
				jmp		CYCLE_K
			END_CYCLE_K:

			; if (flag) { result[i] = 1; break; }

			I_EQUALS_J:
			inc		ecx
			jmp		CYCLE_J
		END_CYCLE_J:

		inc		edx
		jmp		CYCLE_I
	END_CYCLE_I:
		pop		eax
	}
}