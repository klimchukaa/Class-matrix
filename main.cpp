#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    int n1, m1; cin >> n1 >> m1;
    Matrix<int> a(n1, m1);
    cin >> a;
    int n2, m2; cin >> n2 >> m2;
    Matrix<int> b(n2, m2);
    cin >> b;
    int k, p; cin >> k >> p;
    try {
        cout << "a + b:\n" << a + b;
    } catch (const invalid_argument& e) {
        cout << e.what() << "\n";
    }
    try {
        cout << "a * b:\n" << a * b;
    } catch (const invalid_argument& e) {
        cout << e.what() << "\n";
    }
    cout << "a * k:\n" << a * k;
    try {
        cout << "a^p:\n" << a.get_power(p);
    } catch (const invalid_argument& e) {
        cout << e.what() << "\n";
    }
    cout << "Transpose a:\n" << a.transposition();
    return 0;
}
