#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define million 10000000LL

int n, k;
int b [200000];
ll minv = million*million;

void bs(ll start, ll end) {
    if (start <= end) {
        ll mid = (start+end)/2;
        int divNum = 0;
        ll divSize = 0;
        for (int i = 0; i < n; i++) {
            divSize += (ll)(b[i]);
            if (divSize > mid) {
                divSize = (ll)(b[i]);
                if (divSize > mid) {
                    divNum = million;
                }
                divNum++;
            }
        }
        if (divSize > 0LL) divNum++;
        if (divNum <= k) {
            minv = min(minv, mid);
            bs(start, mid-1);
        }
        else bs(mid+1, end);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> b[i];

    if (k == 1) {
        minv = 0;
        for (int i = 0; i < n; i++) minv += (ll)(b[i]);
    }
    else bs(0, million*million*100);

    cout << minv;

    int d = 0;
    d++;
}