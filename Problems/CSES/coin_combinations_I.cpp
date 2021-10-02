#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, target;
int dp [1000001];
int b [100];

int rec(int i) {
    if (dp[i] == -1) {
        dp[i] = 0;
        for (int j = 0; j < n; j++) if (i-b[j] >= 0) {
            dp[i] += rec(i-b[j]);
            dp[i] %= 1000000007;
        }
    }
    return dp[i];
}

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i <= target; i++) dp[i] = -1;
    dp[0] = 1;
    cout << rec(target);
    int d = 0;
    d++;
}