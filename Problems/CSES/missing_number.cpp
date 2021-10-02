#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    bool b [n];
    for (int i = 0; i < n; i++) b[i] = false;

    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        b[x-1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            cout << i+1;
        }
    }
}