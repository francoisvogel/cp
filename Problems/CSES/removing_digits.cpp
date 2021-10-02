#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 1000001;
int dp [n];

int main() {
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = n;
        string s = to_string(i);
        for (char j : s) {
            if (i-((int(j)-48)) >= 0) {
                dp[i] = min(dp[i], dp[i-(int(j)-48)]+1);
            }
        }
    }
    int req;
    cin >> req;
    cout << dp[req];
    int d = 0;
    d++;
}