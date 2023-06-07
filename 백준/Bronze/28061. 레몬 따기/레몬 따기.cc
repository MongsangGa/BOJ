#include<bits/stdc++.h>

using namespace std;

int n, res;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++)
        res = max(res, v[i] - (n - i));
    cout << res;
    return 0;
}
