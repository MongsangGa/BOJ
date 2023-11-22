#include<bits/stdc++.h>

using namespace std;

int n, MAX, m, from, to, box, weight[2002], res;
vector<tuple<int, int, int>> v;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> MAX >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> box;
        v.push_back({to, from, box});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        int temp = 0;
        auto &[t, f, b] = v[i];
        for (int j = f; j < t; j++)
            temp = max(temp, weight[j]);
        int able_weight = min(b, MAX - temp);
        res += able_weight;
        for (int j = f; j < t; j++)
            weight[j] += able_weight;
    }
    cout << res;
    return 0;
}
