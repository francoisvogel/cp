// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// #define ll long long

// ll n;
// ll b [200000];

// ll calc(ll tar) {
//     ll cost = 0;
//     for (ll i = 0; i < n; i++) cost += max(tar-b[i], b[i]-tar);
//     return cost;
// }

// int main() {
//     cin >> n;
//     for (ll i = 0; i < n; i++) cin >> b[i];

//     ll av = 0;
//     for (ll i = 0; i < n; i++) av += b[i];
//     av /= n;

//     ll res = min(calc(av), calc(av+1));
//     res = min(res, calc(av-1));

//     cout << res;

//     ll d = 0;
//     d++;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll n;
ll b [200000];

ll calc(ll tar) {
    ll cost = 0;
    for (ll i = 0; i < n; i++) {
        ll locv = tar-b[i];
        if (b[i]-tar > 0) locv = b[i]-tar;
        cost += locv;
    }
    return cost;
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> b[i];

    ll av = 0;
    for (ll i = 0; i < n; i++) av += b[i];
    av /= n;

    ll res = min(calc(av), calc(av+1));
    res = min(res, calc(av-1));

    cout << res;

    ll d = 0;
    d++;
}