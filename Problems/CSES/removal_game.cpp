#include <iostream>

using namespace std;

#define ll long long

ll n;
ll b [5000];
ll psum [5000];
ll dp [5000][5000];

ll rec(ll start, ll end) {
    if (start > end) return 0;
    else if (dp[start][end] != -1) return dp[start][end];
    else {
        ll solA = b[start]+psum[end]-psum[start]-rec(start+1, end);
        ll solB = b[end]+psum[end-1]-rec(start, end-1);
        if (start-1 >= 0) solB -= psum[start-1];
        dp[start][end] = max(solA, solB);
        return dp[start][end];
    }
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> b[i];
    psum[0] = b[0];
    for (ll i = 1; i < n; i++) psum[i] = b[i]+psum[i-1];
    for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) dp[i][j] = -1;
    cout << rec(0, n-1);
    ll d = 0;
    d++;
}