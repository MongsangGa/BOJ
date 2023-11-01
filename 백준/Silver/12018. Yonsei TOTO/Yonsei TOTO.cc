#include <bits/stdc++.h>

using namespace std;

int n, m, p, l, sum, res;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (n--) {
        cin >> p >> l;
        vector<int> v(p);
        for (int i = 0; i < p; i++) cin >> v[i];
        sort(v.begin(), v.end());
        if (v.size() < l) pq.push(1);
        else pq.push(v[p - l]);
    }
    while (!pq.empty() && sum + pq.top() <= m) {
        sum += pq.top();
        pq.pop();
        res++;
    }
    cout << res;
    return 0;
}
