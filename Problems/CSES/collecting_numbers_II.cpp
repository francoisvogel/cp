#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pos [200000];
int counter, n;

void sw(int i, int newv) {
    int rem = 0;
    int add = 0;
    if (i > 0) {
        if (pos[i-1] > pos[i]) {
            rem++;
        }
        if (pos[i-1] > newv) {
            add++;
        }
    }
    if (i < n-1) {
        if (pos[i] > pos[i+1]) {
            rem++;
        }
        if (newv > pos[i+1]) {
            add++;
        }
    }
    counter -= rem;
    counter += add;
}

int main() {
    int nbReq;
    cin >> n >> nbReq;

    int b [n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    counter = 1;
    for (int i = 0; i < n-1; i++) {
        if (pos[i] > pos[i+1]) {
            counter++;
        }
    }

    for (int i = 0; i < nbReq; i++) {
        int posA, posB;
        cin >> posA >> posB;
        posA--;
        posB--;
        int posbposA = pos[b[posA]];
        sw(b[posA], pos[b[posB]]);
        pos[b[posA]] = pos[b[posB]];
        sw(b[posB], posbposA);
        pos[b[posB]] = posbposA;
        int bposA = b[posA];
        b[posA] = b[posB];
        b[posB] = bposA;
        // cout << "--> ";
        cout << counter << endl;
    }

    int d = 0;
    d++;
}