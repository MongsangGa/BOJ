#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long int
#define pi pair<int,int>
#define SIZE 75001

int t, n;
vector<pi > arr;
ll stree[SIZE * 4], res;

ll query(int fS, int fE, int node = 1, int s = 1, int e = SIZE) {
    if (s > fE || e < fS) return 0;
    if (s >= fS && e <= fE) return stree[node];
    int mid = (s + e) / 2;
    return query(fS, fE, node * 2, s, mid) + query(fS, fE, node * 2 + 1, mid + 1, e);
}

void update(int idx, int diff, int node = 1, int s = 1, int e = SIZE) {
    if (idx < s || idx > e) return;
    if (s == e) {
        stree[node] += diff;
        return;
    }
    int mid = (s + e) / 2;
    update(idx, diff, node * 2, s, mid);
    update(idx, diff, node * 2 + 1, mid + 1, e);
    stree[node] = stree[node * 2] + stree[node * 2 + 1];
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        res = 0, arr.clear(), arr.resize(n), fill(stree, stree + SIZE * 4, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(), arr.end(), [](pi &a, pi &b) {
            return a.second < b.second;
        });
        int idx = 0, prev = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (prev != arr[i].second) idx++;
            prev = arr[i].second;
            arr[i].second = idx;
        }
        sort(arr.begin(), arr.end(), [](pi &a, pi &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < n; i++) {
            res += query(arr[i].second, SIZE);
            update(arr[i].second, 1);
        }
        cout << res << '\n';
    }
    return 0;
}
