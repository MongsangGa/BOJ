#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
map<int, int> m;
set<pair<int, int>> s;

int main() {
    fastio;
    int n, p;
    cin >> n;
    while (n--) {
        int num, l;
        cin >> num >> l;
        s.insert({l, num});
        m[num] = l;
    }
    cin >> p;
    while (p--) {
        string order;
        cin >> order;
        int a, b;
        if (order == "add") {
            cin >> a >> b;
            s.insert({b, a});
            m[a] = b;
        } else if (order == "recommend") {
            cin >> a;
            if (a == 1) cout << s.rbegin()->second;
            else cout << s.begin()->second;
            cout << '\n';
        } else {
            cin >> a;
            s.erase({m[a], a});
        }
    }
    return 0;
}
