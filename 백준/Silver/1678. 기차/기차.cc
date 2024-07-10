#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)

int t, m, n, a, st;
vector<pair<int, string>> v;

int main() {
    fastio;
    cin >> t >> m >> n;
    vector<string> name(t);
    for (int i = 0; i < t; i++) {
        while (1) {
            if (name[i].empty()) cin >> name[i];
            else {
                cin >> a;
                if (a == -1) break;
                v.push_back({a, name[i]});
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first >= m) {
            st = i;
            break;
        }
    }
    cout << v[(n + st - 1) % v.size()].second;
    return 0;
}
