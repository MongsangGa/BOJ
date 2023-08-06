#include <bits/stdc++.h>

using namespace std;

int k, len, res;
string n;
set<string> chk[11];

void solve(string str, int cnt) {
    string tmp = str;
    int In = stoi(tmp);
    if (cnt == k) {
        res = max(res, In);
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (i == 0 && tmp[j] == '0') continue;
            swap(tmp[i], tmp[j]);
            if (!chk[cnt].count(tmp)) {
                chk[cnt].insert(tmp);
                solve(tmp, cnt + 1);
            }
            swap(tmp[i], tmp[j]);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    len = n.size();
    if (len == 1 || (n.size() == 2 && n[1] == '0')) cout << "-1";
    else {
        solve(n, 0);
        cout << res;
    }
}