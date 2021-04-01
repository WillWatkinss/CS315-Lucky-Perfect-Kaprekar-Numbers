/* Course: CS 315 Algorithms JWJ CS UK
 * Author: William Watkins
 * Project: Final Project - Perfect Numbers
 * Algorithm: see perfect()
 * Compilation: g++ -std=c++11
 * Date: 12/22/2019
 * Reference: beginnersbook.com for isPrime() function
*/

#include <iostream>

using namespace std;

// Reference:
// https://beginnersbook.com/2017/09/cpp-program-to-display-prime-numbers-from-1-to-100-and-1-to-n/
bool isPrime(unsigned long long p) {
	for (unsigned long long i = 2; i <= p/2; i++){
		if (p % i == 0) {
			return false; // p is not prime
		}
	}
	return true; // p is prime
} // (end reference)

void perfect(int max) {
	unsigned long long x = 1;
	for (unsigned long long i = 2; i <= max; i++) {
		if (isPrime(i)) { // i is prime
			unsigned long long q = (x << i) - x; // q = 2^i - 1, bitshifting to handle large numbers.
			if (isPrime(q)) { // q is Mersenne prime
				unsigned long long perfect = (q * (q + 1)) / 2;
				cout << perfect << " is an even perfect number for prime " << i << "\n";
			}
		}
	}
}

int main() {
	int max;
	while(true) { // until user input is 0
		cout << "Enter the max power of 2 :  ";
		cin >> max;
		if (max < 1) { return 0; }
		if (max > 31) {
			// unsigned long long shows error at 2^32
			cout << "max too large, setting max to 31\n"; 
			max = 31;
		}

		perfect(max);
	}

	return 0;
}