#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b;
    b.push_back(0);
    b.push_back(1);
    int pow2i = 1;
    for (int i = 1; i < n; i++) {
        int bs = b.size();
        pow2i *= 2;
        for (int j = bs-1; j >= 0; j--) {
            b.push_back(pow2i+b[j]);
        }
    }
    
    for (int i : b) {
        bitset<16> bit(i);
        for (int j = 0; j < n; j++) {
            if (bit[j] == true) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }

    int d = 0;
    d++;
}