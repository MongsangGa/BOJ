#include<bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define vll vector<vector<ll>>
#define MOD (ll)1'000'000'007

int d;
vll factor = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};
vll multiply(const vll &a, const vll &b) {
    vll tmp(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ll v = 0;
            for (int k = 0; k < 8; k++)
                v += (a[i][k] * b[k][j]) % MOD;
            tmp[i][j] = v % MOD;
        }
    }
    return tmp;
}

int main() {
    fastio;
    cin >> d;
    vll res(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) res[i][i] = 1;
    while (d) {
        if (d & 1) {
            res = multiply(res, factor);
            d -= 1;
        }
        factor = multiply(factor, factor);
        d /= 2;
    }
    cout << res[0][0];
    return 0;
}
