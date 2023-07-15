#include<bits/stdc++.h>

using namespace std;

int N, a, b, D, res;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        v.push_back({a, b});
    }
    cin >> D;
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) -> bool {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    for (int i = 0; i < N; i++) {
        if (v[i].second - v[i].first > D) continue; // 집과 사무실이 모두 포함되지 않는 경우
        pq.push(v[i].first);
        if (!pq.empty() && v[i].second - D > pq.top())
            pq.pop();
        res = max<int>(res, pq.size());
    }
    cout << res;
    return 0;
}
