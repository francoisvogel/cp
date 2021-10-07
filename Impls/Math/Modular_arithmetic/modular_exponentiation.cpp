/*
 * Author: Francois Vogel
 * Comment: Modular exponentiation code (O(log e)), and make sure to add int / long long conversion if you are using a large MOD
*/

const int MOD = -1; // set your value here

int p(int b, int e) {
    if (e == 0) return 1;
    else if (e%2 == 0) {
        int v = p(b, e/2);
        return (v*v)%MOD;
    }
    else return (b*p(b, e-1))%MOD;
}