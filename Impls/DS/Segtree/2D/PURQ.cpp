/*
 * Author: Francois Vogel
 * Comment: Point Update Range Query 2D Segment Tree (O(n^2log^2n) time complexity, O(n^2) space complexity)
*/

const int p2 = 1<<-1; // bounds here

struct Segtree1D {
    Segtree1D() {
        t = new short [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    int get(int b, int e) {
        int sum = 0;
        b += p2; e += p2;
        while (b <= e) {
            if (b%2 == 1) sum += t[b++];
            if (e%2 == 0) sum += t[e--];
            b /= 2; e /= 2;
        }
        return sum;
    }
    void upd(int x, int v) {
        for (x += p2; x; x /= 2) t[x] += v;
    }
    short* t;
};

struct Segtree2D {
    Segtree2D() {
        t = new Segtree1D [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = Segtree1D();
    }
    int get(int bX, int eX, int bY, int eY) {
        int sum = 0;
        bX += p2; eX += p2;
        while (bX <= eX) {
            if (bX%2 == 1) {
                sum += t[bX].get(bY, eY);
                bX++;
            }
            if (eX%2 == 0) {
                sum += t[eX].get(bY, eY);
                eX--;
            }
            bX /= 2; eX /= 2;
        }
        return sum;
    }
    void upd(int x, int y, int v) {
        for (x += p2; x; x /= 2) t[x].upd(y, v);
    }
    Segtree1D* t;
};