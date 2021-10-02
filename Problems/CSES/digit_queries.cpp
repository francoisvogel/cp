#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll unsigned long long

ll pow(int base, int exp) {
    if (exp == 0) return 1;
    else if (exp%2 == 0) {
        ll v = pow(base, exp/2);
        return v*v;
    }
    else return pow(base, exp-1)*(ll)(base);
}

int upBound(vector<ll>& b, ll v) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i] > v) {
            return i;
        }
    }
    return b.size();
}

int main() {
    const int s = 18;
    vector<ll> cutoffs(s);
    cutoffs[0] = 0;
    for (int i = 1; i < s; i++) {
        cutoffs[i] = 9ULL*pow(10, i-1)*(ll)(i);
        cutoffs[i] += cutoffs[i-1];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        k--;
        int level = upBound(cutoffs, k)-1;
        k -= cutoffs[level];
        ll actual = k/(ll)(level+1)+pow(10, level);
        ll rank = k%(ll)(level+1);
        string actualString = to_string(actual);
        cout << actualString[rank] << endl;
    }

    int d = 0;
    d++;
}