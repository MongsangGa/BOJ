#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n;
vector<int> res;

int main() {
    fastio
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        temp.push_back(n), temp.push_back(i);
        while (temp[temp.size() - 2] - temp[temp.size() - 1] >= 0)
            temp.push_back(temp[temp.size() - 2] - temp[temp.size() - 1]);
        if (res.size() < temp.size())
            res.clear(), res = temp;
    }
    cout << res.size() << '\n';
    for (auto &i: res) cout << i << ' ';
    return 0;
}
