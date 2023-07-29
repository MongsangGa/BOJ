#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int n, a, idx;

int main() {
    cin >> n;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > v.back()) v.push_back(a);
        else {
            idx = lower_bound(v.begin(), v.end(), a) - v.begin();
            v[idx] = a;
        }
    }
    cout << v.size() - 1;
    return 0;
}
