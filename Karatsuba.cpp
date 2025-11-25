#include <iostream>
#include <cmath>
using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int m = max(to_string(x).length(), to_string(y).length());
    int m2 = m / 2;
    long long power = pow(10, m2);

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long ac = karatsuba(a, c);                  // z2
    long long bd = karatsuba(b, d);                  // z0
    long long ab_cd = karatsuba(a + b, c + d);       // z1

    return ac * pow(10, m2 * 2) + (ab_cd - ac - bd) * power + bd;
}

int main() {
    long long x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    long long result = karatsuba(x, y);
    cout << x << " * " << y << " = " << result << endl;

    return 0;
}
