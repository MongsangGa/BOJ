#include <bits/stdc++.h>

using namespace std;

int n, a, res, cur;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (res <= pq.size() - 1) {
        int cur = pq.top();
        if (res + cur <= pq.size() - 1) res += cur;
        else res = pq.size() - 1;
        pq.pop();
    }
    cout << res;
    return 0;
}
