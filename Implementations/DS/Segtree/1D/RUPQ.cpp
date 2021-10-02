/*
 * Author: Francois Vogel
 * Comment: Point Update Range Query Segtree
*/

const int p2 = 1<<20; // define your bounds here

struct Segtree {
    Segtree() {
        t = new unsigned short [p2*2];
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
    unsigned short* t;
};