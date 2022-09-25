#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(long number)
{
    long maxDiv = lround(sqrt(number));

    if (((number % 2) == 0  && number != 2)|| number == 1) {
        return false;
    }

    for (long i = 3; i <= maxDiv; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    string primeNumber;
    while(getline(cin, primeNumber, ' ')) {
            long number = stol(primeNumber);
            cout << to_string(number) + " is a Prime: " + (isPrime(number) ? "True\n" : "False\n");
    }

    return 0;
};



