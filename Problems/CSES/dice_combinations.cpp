#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 1000001;
int b [n];

int main() {
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        b[i] = 0;
        for (int j = max(0, i-6); j < i; j++) {
            b[i] += b[j];
            b[i] %= 1000000007;
        }
    }

    int req;
    cin >> req;
    cout << b[req];

    int d = 0;
    d++;
}