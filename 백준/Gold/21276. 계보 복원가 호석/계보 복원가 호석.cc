#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define SIZE 1'003

int n, m;
map<string, vector<string>> adj;
map<string, set<string>> res;
map<string, int> ind;
queue<string> q;
vector<string> name, sijo;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        name.push_back(s);
        ind.insert({s, 0});
    }
    sort(name.begin(), name.end());
    cin >> m;
    while (m--) {
        string u, v;
        cin >> v >> u;
        adj[u].push_back(v);
        ++ind[v];
    }
    for (auto i: ind)
        if (!i.second)
            q.push(i.first), sijo.push_back(i.first);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        vector<string> temp;
        for (auto nxt: adj[now]) {
            --ind[nxt];
            if (!ind[nxt])
                q.push(nxt), temp.push_back(nxt);;
        }
        for (auto t: temp)
            res[now].insert(t);
    }
    cout << sijo.size() << '\n';
    for (auto s: sijo)
        cout << s << ' ';
    cout << '\n';
    for (auto i: name) {
        cout << i << ' ' << res[i].size() << ' ';
        for (auto r: res[i]) cout << r << ' ';
        cout << '\n';
    }
    return 0;
}
