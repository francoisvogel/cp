#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main() {
    string s;
    cin >> s;
    
    map<int, int> ma;
    for (char i : s) {
        if (ma.find(int(i)) == ma.end()) ma.insert(pii(int(i), 0));
        ma[int(i)]++;
    }
    
    vector<pii> m(ma.size());
    for (pii i : ma) m.push_back(i);

    int nbUneven = 0;
    int unevenValue = -1;
    for (pii i : m) {
        if (i.second%2 != 0) {
            nbUneven++;
            unevenValue = i.first;
        }
    }

    if (nbUneven <= 1) {
        string newS = "";
        for (int i = 0; i < m.size(); i++) {
            if (m[i].first == unevenValue) continue;
            for (int j = 0; j < m[i].second/2; j++) newS += char(m[i].first);
        }
        if (unevenValue != -1) {
            for (int j = 0; j < ma[unevenValue]; j++) newS += char(unevenValue);
        }
        for (int i = m.size()-1; i >= 0; i--) {
            if (m[i].first == unevenValue) continue;
            for (int j = 0; j < m[i].second/2; j++) newS += char(m[i].first);
        }
        cout << newS;
    }
    else {
        cout << "NO SOLUTION";
    }

    int d = 0;
    d++;
}