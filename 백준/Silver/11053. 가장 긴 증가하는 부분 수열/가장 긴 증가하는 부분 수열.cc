#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1'003

int n;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    v.push_back(0);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        if (v.back() < a) v.push_back(a);
        else v[lower_bound(v.begin(), v.end(), a) - v.begin()] = a;
    }
    cout << v.size() - 1;
    return 0;
}
