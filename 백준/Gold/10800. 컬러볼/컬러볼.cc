#include<bits/stdc++.h>

using namespace std;

#define SIZE 200'002

int n, c, s, color[SIZE], res[SIZE], total;
vector<tuple<int, int, int>> v; // color, size, idx

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> s;
        v.push_back({s, c, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0, j = 0; i < n; i++) {
        for (; get<0>(v[i]) > get<0>(v[j]); j++) {
            total += get<0>(v[j]);
            color[get<1>(v[j])] += get<0>(v[j]);
        }
        res[get<2>(v[i])] = total - color[get<1>(v[i])];
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << '\n';
    return 0;
}
