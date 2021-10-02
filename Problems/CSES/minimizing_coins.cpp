#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, target;
int dp [1000001];
int b [100];

int rec(int i) {
    if (dp[i] == -1) {
        dp[i] = 1000001;
        for (int j : b) if (i-j >= 0) dp[i] = min(dp[i], rec(i-j)+1);
    }
    return dp[i];
}

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i <= target; i++) dp[i] = -1;
    dp[0] = 0;
    int res = rec(target);
    if (res == 1000001) cout << -1;
    else cout << res;
    int d = 0;
    d++;
}