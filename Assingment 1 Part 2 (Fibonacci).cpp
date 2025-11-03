#include <iostream>
#include<cmath>
#include<chrono>
using namespace std;
using namespace std::chrono;

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
	if (num == 1) {
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

long long Fibonacci_Series_3(long long num) {

	int prev2 = 0;
	int prev1 = 1;
	int current;
	if (num <= 1)
		return num;
	for (int i = 2;i <= num;i++) {
		current = prev1 + prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}

int main() {

	int num;
	int choice;
	char exit;
	while (true) {
		cout << "Enter Number please: ";
		cin >> num;
		if (num < 0) {
			cout << "In Fibonacci Series never work on negative numbers.";
			return 0;
		}
		cout << "Choose a method for Fibonacci: \n";
		cout << "1. Recursion method \n";
		cout << "2. Matrix Multiply method \n";
		cout << "3. Dynamic Programming method \n";
		cin >> choice;
		// Start timer
		auto start = steady_clock::now();
		switch (choice) {
		case 1:
			cout << "Recursion result = " << Fibonacci_Series_1(num) << endl;
			break;
		case 2:
			cout << "Matrix Multiply result = " << Fibonacci_Series_2(num) << endl;
			break;
		case 3:
			cout << "Dynamic Programming result = " << Fibonacci_Series_3(num) << endl;
			break;
		default:
			cout << "Invalid Input!!!! \n";
			break;
		}
		// End timer
		auto end = steady_clock::now();
		//To calculate time for method
		auto duration = duration_cast<milliseconds>(end - start);
		cout << "This method takes: " << duration.count() << " milliseconds" << endl;

		cout << "Do you want to continue? (y/n): ";
		cin >> exit;
		if (exit != 'y' && exit != 'Y')
		{
			cout << "Good Bye :)" << endl;
			return 0;
		}
		cout << "------------------------------------------- \n";
	}



}