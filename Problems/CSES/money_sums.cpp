#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int b [100];
bool dp [100][100001];
set<int> s;

void rec(int i, int sum) {
    if (i >= n) {
        if (sum != 0) s.insert(sum);
    }
    else if (dp[i][sum]) return;
    else {
        dp[i][sum] = true;
        rec(i+1, sum);
        rec(i+1, sum+b[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < 100001; j++) dp[i][j] = false;
    rec(0, 0);
    cout << s.size() << endl;
    for (int i : s) cout << i << " ";
    int d = 0;
    d++;
}