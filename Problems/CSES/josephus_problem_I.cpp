#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node(int lidx) {
        idx = lidx;
    }
    int idx;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node* ll [n];
    for (int i = 0; i < n; i++) ll[i] = new Node(i);
    for (int i = 0; i < n-1; i++) ll[i]->next = ll[i+1];
    ll[n-1]->next = ll[0];

    Node* cur = ll[0];
    for (int i = 0; i < n; i++) {
        cout << cur->next->idx+1 << endl;
        cur->next = cur->next->next;
        cur = cur->next;
    }

    int d = 0;
    d++;
}