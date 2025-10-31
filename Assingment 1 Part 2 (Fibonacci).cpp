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


//long long Fibonacci_Series_2(long long num) {

//}


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
		cout << Fibonacci_Series_1(num) << endl;
		cout << "Do you want another Fibonacci number? (y/n): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	return 0;

}

