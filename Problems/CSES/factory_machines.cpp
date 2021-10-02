// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// #define pii pair<ll, ll>

// ll main() {
//     ll n, prodNumber;
//     cin >> n >> prodNumber;

//     multiset<pii> s;
//     for (ll i = 0; i < n; i++) {
//         ll t;
//         cin >> t;
//         s.insert(pii(t, t));
//     }

//     for (ll i = 0; i < prodNumber; i++) {
//         pii cur = *(s.begin());
//         s.insert(pii(cur.first+cur.second, cur.second));
//         s.erase(s.begin());
//     }

//     ll maxt = 0;
//     for (pii i : s) {
//         maxt = max(maxt, i.first-i.second);
//     }

//     cout << maxt;

//     ll d = 0;
//     d++;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define million 1000000000LL

ll b [200000];
ll n, target;
ll maxv = million*million;

void bs(ll start, ll end) {
    if (start <= end) {
        ll mid = (start+end)/2;
        ll placed = 0;
        for (ll i = 0; i < n; i++) {
            placed += mid/b[i];
            placed = min(placed, million*million);
        }
        if (placed >= target) {
            maxv = min(maxv, mid);
            bs(start, mid-1);
        }
        else bs(mid+1, end);
    }
}

int main() {
    cin >> n >> target;
    for (ll i = 0; i < n; i++) cin >> b[i];
    bs(0, million*million);
    cout << maxv;
    ll d = 0;
    d++;
}