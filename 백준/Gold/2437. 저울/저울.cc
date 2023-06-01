#include<bits/stdc++.h>

using namespace std;

int n, i, sum;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    sum = 1;
    for (i = 0; i < n; ++i) {
        if (v[i] > sum) break;
        sum += v[i];
    }
    cout << sum;
}
