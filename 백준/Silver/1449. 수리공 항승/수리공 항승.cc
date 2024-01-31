#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n, l, res;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    fastio;
    cin >> n >> l;
    while (n--) {
        int a;
        cin >> a;
        pq.push(a);
    }
    while (!pq.empty()) {
        double cur = pq.top() - 0.5;
        pq.pop();
        res++;
        while (!pq.empty() && pq.top() <= cur + l)
            pq.pop();
    }
    cout << res;
    return 0;
}
