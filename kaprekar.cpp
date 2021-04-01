/* Course: CS 315 Algorithms JWJ CS UK
 * Author: William Watkins
 * Project: Final Project - Kaprekar Numbers
 * Algorithm: see kaprekar()
 * Compilation: g++ -std=c++11
 * Date: 12/22/2019
 * Reference: geeksforgeeks.com for chopping digits
 *			javatpoint.com for reversing order of digits
 *			stackoverflow.com for counting digits
*/

#include <iostream>

using namespace std;

// chop digits from right
// Reference:
// https://www.geeksforgeeks.org/program-to-delete-nth-digit-of-a-number/
unsigned long long chopRight(unsigned long long num, int iterations) {
	for (int i = 0; i < iterations; i++) {
		num /= 10;
	}
	return num;
} // (end reference)

// reverse order of digits
// Reference:
// https://www.javatpoint.com/cpp-program-to-reverse-number
unsigned long long reverse(unsigned long long num) {
	unsigned long long remainder, revNum = 0;
	while (num != 0) {
		remainder = num % 10;
		revNum = revNum * 10 + remainder;
		num /= 10;
	}
	return revNum;
} // (end reference)

void kaprekar(int high, int low) {
	unsigned long long square;
	for (unsigned long long i = low; i <= high; i++) {
		// square i
		square = i * i;

		if (square % 9 == 0 || square % 9 == 1) {
			// get number of digits 
			//(Reference: 
			// https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer)
			int digits = 0;
			unsigned long long tempSquare = square;
			do {
				tempSquare /= 10;
				digits++;
			} while (tempSquare != 0); // (end reference)

			// get number of digits on left, right
			int digLeft = digits/2, digRight;
			if (digits % 2 == 0) {
				digRight = digLeft;
			}
			else {
				digRight = digLeft + 1;
			}

			unsigned long long numLeft, numRight;
			// get number on left
			// chop digits from right
			numLeft = chopRight(square, digRight);
			
			// get number on right
			// reverse order of digits
			unsigned long long revSquare, revNumRight;
			int zerosCount = 0;

			// count tail zeros
			if (square != 0) { // don't divide by zero
				while (square % 10 == 0) {
					zerosCount++;
					square /= 10;
				}
			}

			revSquare = reverse(square);

			// chop digits from right
			revNumRight = chopRight(revSquare, digLeft);

			// reverse number again
			numRight = reverse(revNumRight);

			// add tail zeros if any
			for (int j = 0; j < zerosCount; j++) {
				numRight *= 10;
			}

			if ((numLeft + numRight) == i) {
				// results
				cout << i << " squared is " << square << ".  It is the sum of " << numLeft << " + " << numRight << "\n";
			}
		}
	}
	return;
}

int main() {

	// get input
	while (true) {
		int lower, upper;
		cout << "Enter 0s for both to quit\n";
		cout << "Enter a lower bound: ";
		cin >> lower;
		cout << "Enter an upper bound: ";
		cin >> upper;

		// less than 1 to quit
		if (upper < 1 && lower < 1) { return 0; }
		else if (lower > upper) {
			cout << lower << " is more than " << upper << "\n";
			return 0;
		}

		// call kaprekar()
		kaprekar(upper, lower);
	}
	return 0;
}