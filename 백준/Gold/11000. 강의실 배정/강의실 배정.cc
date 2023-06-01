#include<bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }
    cout << pq.size();
}
