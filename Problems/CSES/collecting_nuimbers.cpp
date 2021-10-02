#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int b [n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    int pos [n];
    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    int count = 1;
    for (int i = 0; i < n-1; i++) {
        if (pos[i] > pos[i+1]) {
            count++;
        }
    }

    cout << count;

    int d = 0;
    d++;
}