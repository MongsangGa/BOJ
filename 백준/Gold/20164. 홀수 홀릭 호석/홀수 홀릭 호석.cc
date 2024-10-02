#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define SIZE 100'002

int MIN = INT_MAX, MAX = -1;

int calc_odd(int n) {
    int cnt = 0;
    while (n) {
        if ((n % 10) % 2) ++cnt;
        n /= 10;
    }
    return cnt;
}

void dfs(string s, int cnt) {
    cnt += calc_odd(stoi(s));
    if (s.size() == 1) {
        MAX = max(MAX, cnt);
        MIN = min(MIN, cnt);
        return;
    } else if (s.size() == 2) {
        int n = (s[0] - '0') + (s[1] - '0');
        dfs(to_string(n), cnt);
    } else {
        for (int i = 1; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j, s.size() - j);
                int n = stoi(a) + stoi(b) + stoi(c);
                dfs(to_string(n), cnt);
            }
        }
    }
}

int main() {
    fastio;
    string s;
    cin >> s;
    dfs(s, 0);
    cout << MIN << ' ' << MAX;
    return 0;
}
