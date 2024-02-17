#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) v.push_back(i);
    do {
        for (auto &i: v) cout << i << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
