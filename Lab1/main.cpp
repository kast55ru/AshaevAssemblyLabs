#include <stdlib.h>

char* quantitiveCopy(const char* input, int len, int quantity) {
	__asm {
		mov		edi, len
		mov		eax, edi
		imul	eax, quantity
		push	eax

		mov		ebx, eax

		inc		eax
		push	eax
		call	malloc
		add		esp, 4

		mov		ecx, ebx

		xchg	eax, ebx

		mov		esi, input

		CYCLE:
		xor		edx, edx
		mov		eax, ecx
		dec		eax
		idiv	edi
		mov		al, [esi+edx]
		mov		byte ptr [ebx+ecx-1], al
		loop	CYCLE

		pop		eax
		mov		byte ptr [ebx+eax], 0
		xchg	eax, ebx
	}
}

int main() {
	char* result = quantitiveCopy("1337 ", 5, 5);
	delete result;
	return 0;
}