#include <bits/stdc++.h>

using namespace std;

int n, arr[51][51], res;
vector<int> v(9);

int solve() {
    // init point, hitter turn
    int point = 0, turn = 0;
    for (int k = 0; k < n; k++) {
        // init base, out count
        int out = 0;
        vector<int> base(8, 0);
        while (out < 3) {
            base[0] = 1;
            int hit = arr[k][v[turn]];
            if (!hit) ++out;
            else {
                for (int i = 3; i >= 0; i--)
                    if (base[i])
                        base[i + hit] = 1, base[i] = 0;
                for (int i = 4; i < 8; i++)
                    point += base[i], base[i] = 0;
            }
            turn = (turn + 1) % 9;
        }
    }
    return point;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    for (int i = 0; i < 9; i++)
        v[i] = i;
    do {
        if (v[3] != 0) continue;
        res = max(res, solve());
    } while (next_permutation(v.begin(), v.end()));
    cout << res;
    return 0;
}
