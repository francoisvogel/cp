#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        int a = min(u1, u2);
        int b = max(u1, u2);
        int dif = b-a;
        a -= dif;
        b -= 2*dif;
        if (a >= 0 and a%3 == 0) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    int d = 0;
    d++;
}