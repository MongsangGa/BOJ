#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define piv pair<int, vector<int>>

int n, q;
map<vector<int>, int> d;
priority_queue<piv, vector<piv >, greater<> > pq;

int main() {
    fastio;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> q;
    vector<tuple<int, int, int> > Q(q);
    for (int i = 0, x, y, c; i < q; i++) {
        cin >> x >> y >> c;
        Q[i] = {x, y, c};
    }
    pq.push({0, A});
    d[A] = 0;
    while (!pq.empty()) {
        auto [nowC, nowA] = pq.top();
        pq.pop();
        if (d[nowA] < nowC) continue;
        for (auto [x,y,c]: Q) {
            --x, --y;
            swap(nowA[x], nowA[y]);
            if (d.find(nowA) == d.end() || d[nowA] > nowC + c) {
                d[nowA] = nowC + c;
                pq.push({nowC + c, nowA});
            }
            swap(nowA[x], nowA[y]);
        }
    }
    sort(A.begin(), A.end());
    if (d.find(A) == d.end()) cout << -1;
    else cout << d[A];
    return 0;
}
