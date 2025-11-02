#include <iostream>
#include<cmath>
using namespace std;

int Fibonacci_Series_1(int num) {

	if (num == 0) {
		return 0;
	}
	else if (num == 1 || num == 2) {
		return 1;
	}
	else {
		return Fibonacci_Series_1(num - 1) + Fibonacci_Series_1(num - 2);

	}
}

void multiplyInTwoMatrices(long long Matrix_A[2][2], long long Matrix_B[2][2]) {

	long long w = Matrix_A[0][0] * Matrix_B[0][0] + Matrix_A[0][1] * Matrix_B[1][0];
	long long x = Matrix_A[0][0] * Matrix_B[0][1] + Matrix_A[0][1] * Matrix_B[1][1];
	long long y = Matrix_A[1][0] * Matrix_B[0][0] + Matrix_A[1][1] * Matrix_B[1][0];
	long long z = Matrix_A[0][1] * Matrix_B[1][0] + Matrix_A[1][1] * Matrix_B[1][1];

	Matrix_A[0][0] = w;
	Matrix_A[0][1] = x;
	Matrix_A[1][0] = y;
	Matrix_A[1][1] = z;

}

void power(long long M[2][2], long long num) {
	if ( num == 1) {
		return;
	}
	long long Matrix_base[2][2] = { {1,1},{1,0} };
	power(M, num / 2);
	multiplyInTwoMatrices(M, M);

	if (num % 2 != 0) 
		multiplyInTwoMatrices(M, Matrix_base);
	


	
}
long long Fibonacci_Series_2(long long num) {
	if (num == 0)
		return 0;
	long long M[2][2] = { {1,1},{1,0} };
	power(M, num);
	return M[0][1];
}


int main() {

	int num;
	char choice;
	;
	do {
		cout << "Enter Number please: ";
		cin >> num;
		if (num < 0) {
			cout << "In Fibonacci Series never work on negative numbers.";
			return 0;
		}
		cout << Fibonacci_Series_2(num) << endl;
		cout << "Do you want another Fibonacci number? (y/n): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	return 0;

}

