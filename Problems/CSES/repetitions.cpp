#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string b;
    cin >> b;

    int n = b.size();

    int cont [n];
    cont[0] = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i-1]) {
            cont[i] = cont[i-1]+1;
        }
        else cont[i] = 1;
    }

    int maxv = 0;
    for (int i = 0; i < n; i++) {
        maxv = max(maxv, cont[i]);
    }

    cout << maxv;

    int d = 0;
    d++;
}