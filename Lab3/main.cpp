#include <iostream>

double ctg(double x) {
	int ctgConstant2 = 3;
	int ctgConstant3 = 45;
	int ctgConstant4 = 945;
	int ctgConstant5 = 4725;
	__asm {
		finit

		fld		qword ptr x
		fst		st(1)
		fst		st(2)
		fst		st(3)
		fst		st(4)

		fmul	st(2), st(0)
		fxch	st(2)
		fmul	st(3), st(0)
		fmul	st(4), st(0)
		fmul	st(3), st(0)
		fmul	st(4), st(0)
		fmul	st(4), st(0)
		fxch	st(2)
		fmul	st(2), st(0)

		fld1
		fdivrp	st(1), st(0)

		fild	ctgConstant2
		fdivp	st(2), st(0)

		fild	ctgConstant3
		fdivp	st(3), st(0)

		fld		st(3)
		faddp	st(4), st(0)

		fld		st(4)
		faddp	st(5), st(0)

		fild	ctgConstant4
		fdivp	st(4), st(0)

		fild	ctgConstant5
		fdivp	st(5), st(0)

		fsub	st(0), st(1)
		fsub	st(0), st(2)
		fsub	st(0), st(3)
		fsub	st(0), st(4)
	}
}

int main() {
	std::cout << ctg(1.5) << std::endl;
	return 0;
}