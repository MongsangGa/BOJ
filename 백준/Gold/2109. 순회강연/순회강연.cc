#include <bits/stdc++.h>

using namespace std;

#define MAX 10001
int n, d, p, res;
vector<int> arr[MAX];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        arr[d].push_back(p);
    }
    for (int i = 10000; i >= 1; i--) {
        for (auto &c: arr[i])
            pq.push(c);
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
    return 0;
}
