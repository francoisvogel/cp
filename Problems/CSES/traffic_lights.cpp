#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int streetLen, n;
    cin >> streetLen >> n;

    set<int> lights;
    map<int, int> space;
    lights.insert(0);
    lights.insert(streetLen);
    space[streetLen] = 1;
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        if (pos != 0 and pos != streetLen) {
            int leftPos = *(prev(lights.upper_bound(pos)));
            int rightPos = *(lights.upper_bound(pos));
            space[rightPos-leftPos]--;
            if (space[rightPos-leftPos] <= 0) space.erase(rightPos-leftPos);
            if (space.find(pos-leftPos) == space.end()) space[pos-leftPos] = 1;
            else space[pos-leftPos]++;
            if (space.find(rightPos-pos) == space.end()) space[rightPos-pos] = 1;
            else space[rightPos-pos]++;
            lights.insert(pos);
        }
        cout << (*(space.rbegin())).first << endl;
    }

    int d = 0;
    d++;
}