/*
 * Author: Francois Vogel
 * Comment: Range Update Point Query Segtree
*/

const int p2 = 1<<-1; // define your bounds here

struct Segtree {
    Segtree() {
        t = new int [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    void upd(int b, int e, int v) {
        b += p2; e += p2;
        while (b <= e) {
            if (b%2 == 1) t[b++] += v;
            if (e%2 == 0) t[e--] += v;
            b /= 2; e /= 2;
        }
    }
    int get(int x) {
        int r = 0;
        for (x += p2; x; x /= 2) r += t[x];
        return r;
    }
    int* t;
};