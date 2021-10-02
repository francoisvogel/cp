/*
 * Author: Francois Vogel
 * Comment: Point Update Range Query 2D Segment Tree (O(n^2log^2n) space complexity)
*/

/* Practice problems:
 * Codeforces (2400) - The Unintended Antiquity - https://codeforces.com/problemset/problem/869/E (A good problem to test your first implementation on)
*/

const int p2 = 1<<12; // bounds here

struct Segtree1D {
    Segtree1D() {
        t = new int [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    void upd(int b, int e, int v) {
        b += p2; e += p2;
        while (b <= e) {
            if (b%2 == 1) {
                t[b] += v;
                b++;
            }
            if (e%2 == 0) {
                t[e] += v;
                e--;
            }
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

struct Segtree2D {
    Segtree2D() {
        t = new Segtree1D [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = Segtree1D();
    }
    void upd(int bX, int eX, int bY, int eY, int v) {
        bX += p2; eX += p2;
        while (bX <= eX) {
            if (bX%2 == 1) {
                t[bX].upd(bY, eY, v);
                bX++;
            }
            if (eX%2 == 0) {
                t[eX].upd(bY, eY, v);
                eX--;
            }
            bX /= 2; eX /= 2;
        }
    }
    int get(int x, int y) {
        int r = 0;
        for (x += p2; x; x /= 2) r += t[x].get(y);
        return r;
    }
    Segtree1D* t;
};