#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define mPair pair<pii, int>
#define pii pair<int, int>
#define pow2 524288

int binTree [pow2*2];

void btClear() {
    for (int i = 0; i < pow2*2; i++) binTree[i] = 0;
}

void btAdd(int rBegin, int rEnd, int rAdd, int qNode, int qBegin, int qEnd) {
    if (rBegin > qEnd or rEnd < qBegin) return;
    else if (rBegin <= qBegin and qEnd <= rEnd) binTree[qNode] += rAdd;
    else {
        int qMid = (qBegin+qEnd)/2;
        btAdd(rBegin, rEnd, rAdd, qNode*2, qBegin, qMid);
        btAdd(rBegin, rEnd, rAdd, qNode*2+1, qMid+1, qEnd);
    }
}

int btGet(int idx) {
    idx += pow2;
    int sum = 0;
    while (idx > 0) {
        sum += binTree[idx];
        idx /= 2;
    }
    return sum;
}

bool sf1(mPair a, mPair b) {
    return (a.first.second > b.first.second or (a.first.second == b.first.second and a.first.first <= b.first.first));
}

bool sf2(mPair a, mPair b) {
    return (a.first.second < b.first.second or (a.first.second == b.first.second and a.first.first >= b.first.first));
}

int main() {
    int n;
    cin >> n;

    mPair included [n];
    mPair includes [n];
    vector<int> startIndexes;
    map<int, int> startCompress;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        included[i] = mPair(pii(a, b), i);
        includes[i] = mPair(pii(a, b), i);
        startIndexes.push_back(a);
    }
    sort(startIndexes.begin(), startIndexes.end());
    for (int i = 0; i < startIndexes.size(); i++) {
        startCompress[startIndexes[i]] = i;
    }

    sort(included, included+n, sf1);
    sort(includes, includes+n, sf2);

    btClear();
    int isIncludes [n];
    for (mPair i : includes) {
        isIncludes[i.second] = btGet(startCompress[i.first.first]);
        btAdd(0, startCompress[i.first.first], 1, 1, 0, pow2-1);
    }

    btClear();
    int isIncluded [n];
    for (mPair i : included) {
        isIncluded[i.second] = btGet(startCompress[i.first.first]);
        btAdd(startCompress[i.first.first], pow2-1, 1, 1, 0, pow2-1);
    }

    for (int i : isIncludes) cout << i << " ";
    cout << endl;
    for (int i : isIncluded) cout << i << " ";

    int d = 0;
    d++;
}