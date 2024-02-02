#include<bits/stdc++.h>

using namespace std;

int n, res;
vector<int> v;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // !!priority!! : 7 -> 5 -> 3
    cin >> n;
    v.resize(n+3);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++) {
        // [i + 1] > [i + 2] -> 5 to 7 to 3
        if (v[i + 1] > v[i + 2]) {
            int five = min(v[i], v[i + 1] - v[i + 2]);
            v[i] -= five, v[i + 1] -= five;
            res += 5 * five;

            int seven = min(v[i], min(v[i + 1], v[i + 2]));
            v[i] -= seven, v[i + 1] -= seven, v[i + 2] -= seven;
            res += 7 * seven;
        }
        // [i + 1] < [i + 2] -> 7 to 5 to 3
        else {
            int seven = min(v[i], min(v[i + 1], v[i + 2]));
            v[i] -= seven, v[i + 1] -= seven, v[i + 2] -= seven;
            res += 7 * seven;

            int five = min(v[i], v[i + 1]);
            v[i] -= five, v[i + 1] -= five;
            res += 5 * five;
        }
        res += 3 * v[i];
    }
    cout << res;
    return 0;
}
