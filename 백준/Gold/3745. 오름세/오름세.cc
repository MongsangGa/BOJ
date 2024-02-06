#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 2001

int n, a;

int main() {
    fastio;
    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (v.empty() || v.back() < a) v.push_back(a);
            else {
                int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
                v[idx] = a;
            }
        }
        cout << v.size() << '\n';
    }
    return 0;
}
