#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int a, int b) {
    if (a == 0) return -1;
    else return f(b%a, a)+(b/a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << f(a, b);
    int d = 0;
    d++;
}