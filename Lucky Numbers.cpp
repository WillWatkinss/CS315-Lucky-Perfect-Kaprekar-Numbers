/* Course: CS 315 Algorithms JWJ CS UK
 * Author: William Watkins
 * Project: Final Project
 * Algorithm: see lucky()
 * Compilation: g++ -std=c++11
 * Date: 12/22/2019
 * Reference: no coding references
*/

#include <iostream>

using namespace std;

const int MAX = 1000; // number of elements in array
int a[MAX];

void lucky() {

	int pos = 1, counter, counterMax = 2;
	while (pos <= MAX) { // iterate over array
		counter = 1;
		if(a[pos] > 1) { // next element
			counterMax = a[pos];
			for (int i = 0; i < MAX; i++) { // iterate over array
				if (a[i] != -1) {
					if (counterMax == counter) { // strike out this integer
						a[i] = -1;
						counter = 1;
					}
					else {  // leave this integer
						counter++;
					}
				}
			}
		}
		pos++; // next position
	}

	return;
}

int main() {

	for (int i = 0; i < MAX; i++) { // fill array with integers
		a[i] = i + 1;
	}

	cout << "Lucky numbers from 1-1000 are :\n";

	lucky();

	for (int i = 0; i < MAX; i++) { // print lucky numbers
		if (a[i] != -1) {
			cout << a[i] << "\n";
		}
	}

	return 0;
}