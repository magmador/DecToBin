#include <iostream>

using namespace std;

#define BITS_IN_BYTE 8

int BitsRequired(long const number) {
	int bits = 0;
	unsigned long checkNumber = abs(number);

	while (checkNumber > 0) {
		checkNumber >>= BITS_IN_BYTE;
		bits++;
	}

	return BITS_IN_BYTE * bits - 1;
}
void ConvertToBin(long const number) {
	int i = BitsRequired(number);

	cout << number << " -> ";

	while (i >= 0) {
		cout << (bool)(number & (1 << i));
		i--;
	}
}


int main() {
	long number = 0;

	while (1) {
		cout << "Enter any number: ";
		cin >> number;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}

	ConvertToBin(number);

	return 0;
}