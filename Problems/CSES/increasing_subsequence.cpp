#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define pow2 262144

int binTree [pow2*2];

void btSet(int idx, int val) {
    idx += pow2;
    while (idx != 0) {
        binTree[idx] = max(binTree[idx], val);
        idx /= 2;
    }
}

int btGet(int rBegin, int rEnd, int qNode, int qBegin, int qEnd) {
    if (rBegin > qEnd or rEnd < qBegin or qNode >= pow2*2) return 0;
    else if (rBegin <= qBegin and qEnd <= rEnd) return binTree[qNode];
    else return max(btGet(rBegin, rEnd, qNode*2, qBegin, (qBegin+qEnd)/2), btGet(rBegin, rEnd, qNode*2+1, (qBegin+qEnd)/2+1, qEnd));
}

void btClear() {
    for (int i = 0; i < pow2*2; i++) binTree[i] = 0;
}

int main() {
    int n;
    cin >> n;
    int b [n];
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    map<int, int> m;
    int i = 0;
    for (int j : s) {
        m[j] = i;
        i++;
    }
    for (int i = 0; i < n; i++) b[i] = m[b[i]];
    btClear();
    for (int i = n-1; i >= 0; i--) {
        int dpVal = btGet(b[i]+1, pow2-1, 1, 0, pow2-1)+1;
        btSet(b[i], dpVal);
    }
    cout << btGet(0, pow2-1, 1, 0, pow2-1);
    int d = 0;
    d++;
}