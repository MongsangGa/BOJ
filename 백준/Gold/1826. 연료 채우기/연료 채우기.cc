#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;
int n, dist, fuel, now, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    cin >> dist >> fuel;
    while (dist > fuel) {
        for (int i = now; i < n; i++) {
            if (fuel >= v[i].first)
                pq.push(v[i].second);
            else {
                now = i;
                break;
            }
        }
        if (pq.empty()) {
            cout << "-1";
            exit(0);
        }
        fuel += pq.top();
        pq.pop();
        res++;
    }
    cout << res;
    return 0;
}
