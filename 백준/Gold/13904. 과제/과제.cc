#include<bits/stdc++.h>

using namespace std;

#define MAX 1001

int n, date, score, ndate, nscore, res;
vector<pair<int, int>> v;
bool chk[MAX];

bool compare(pair<int, int> x, pair<int, int> y) {
    if (x.second == y.second) {
        return x.first < y.first;
    }
    return x.second > y.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> date >> score;
        v.push_back({date, score});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        tie(ndate, nscore) = v[i];
        for (int j = ndate; j >= 1; j--) {
            if (!chk[j]) {
                chk[j] = true;
                res += nscore;
                break;
            }
        }
    }
    cout << res;
    return 0;
}
