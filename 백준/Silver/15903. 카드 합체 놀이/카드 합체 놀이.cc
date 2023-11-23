#include<bits/stdc++.h>

using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
long long int n, m, a, x, y, res;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (m--) {
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res;
    return 0;
}
