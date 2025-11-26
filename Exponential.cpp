#include <iostream>
using namespace std;

// O(N) Exponentiation
long long power_ON(long long base, long long exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// O(LogN) Exponentiation (Binary Exponentiation)
long long power_LogN(long long base, long long exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {       
            result *= base;
        }
        base *= base;            
        exp /= 2;               
    }
    return result;
}

int main() {
    long long base, exp;
    cout << "Enter base value: ";
    cin >> base;
    cout << "Enter exponent value: ";
    cin >> exp;

    cout << "Power (O(N)) = " << power_ON(base, exp) << endl;
    cout << "Power (O(LogN)) = " << power_LogN(base, exp) << endl;

    return 0;
}
