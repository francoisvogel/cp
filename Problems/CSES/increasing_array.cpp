#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    
    int b [n];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll steps = 0;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i-1]) {
            steps += b[i-1]-b[i];
            b[i] = b[i-1];
        }
    }

    cout << steps;

    int d = 0;
    d++;
}