#include <iostream>
#include <math.h>
using namespace std;
long* allPrime(long number);
bool isPrime(long &number) {
	if (number <=1)// one zero and negative
	{
		return false;
	}
	else if (number <= 3)//2 and 3
		return true;
	else {
		
		for (long i = 2;i <= sqrt(number);i++)
			if (number % i == 0)
				return false;
				
	}
	return true;
}
long* allPrime(long number) {
	long count = 0;

	for (long i = 2; i <= number; i++) {
		if (i % 2 != 0) {
			if (isPrime(i)) {
				count++;
			}
		}
	}

		long* primes = new long[count + 2];
		primes[0] = count;
		primes[1] = 2;
		count = 2;

		for (long i = 3; i <= number; i+=2) {
			if (isPrime(i)) {
				primes[count] = i;
				count++;
			}
		}

		return primes;
	}


int main() {
	long number;
	cout << "enter a number to check\n";
	cin >> number;
	if (isPrime(number) == true) {
		cout << number << " is prime\n";
		long* primes = allPrime(number);
		for (long i = 1;i <= primes[0]+1;i++)
			cout << primes[i] << "  "  ;

		delete[] primes;
	}
	else
		cout << number << " is not prime\n";





	return 0;
}