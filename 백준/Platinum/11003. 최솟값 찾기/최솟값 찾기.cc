#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, l, a;
deque<pair<int, int>> dq;

int main() {
    fastio;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front().second <= i - l) dq.pop_front();
        cin >> a;
        while (!dq.empty() && dq.back().first >= a) dq.pop_back();
        dq.push_back({a, i});
        cout << dq.front().first << ' ';
    }
    return 0;
}
