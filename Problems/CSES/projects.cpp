#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long
#define pii pair<ll, ll>

int main() {
    ll n;
    cin >> n;
    pii ints [n];
    ll intScore [n];
    set<ll> pointsSet;
    for (ll i = 0; i < n; i++) {
        ll s, e, p;
        cin >> s >> e >> p;
        e++;
        ints[i] = pii(s, e);
        intScore[i] = p;
        pointsSet.insert(s);
        pointsSet.insert(e);
    }
    vector<ll> pointsVec;
    unordered_map<ll, ll> compress;
    for (ll i : pointsSet) {
        pointsVec.push_back(i);
        compress[i] = pointsVec.size()-1;
    }
    vector<pii> endAt [pointsVec.size()];
    for (int i = 0; i < n; i++) endAt[compress[ints[i].first]].push_back(pii(compress[ints[i].second], intScore[i]));
    ll dp [pointsVec.size()];
    ll mVal [pointsVec.size()];
    for (ll i = pointsVec.size()-1; i >= 0; i--) {
        if (i < pointsVec.size()-1) dp[i] = mVal[i+1];
        else dp[i] = 0;
        for (pii j : endAt[i]) {
            ll loc = j.second+mVal[j.first];
            dp[i] = max(dp[i], loc);
        }
        mVal[i] = dp[i];
        if (i < pointsVec.size()-1) mVal[i] = max(mVal[i], mVal[i+1]);
    }
    cout << dp[0];
    ll d = 0;
    d++;
}