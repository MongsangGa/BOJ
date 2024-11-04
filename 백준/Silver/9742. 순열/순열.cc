#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n;
string s;

int main() {
    fastio;
    while (cin >> s >> n) {
        sort(s.begin(), s.end());
        vector<char> v;
        for (auto c: s)
            v.push_back(c);
        int cnt = 0;
        bool flag = 0;
        do {
            ++cnt;
            if (cnt == n) {
                cout << s << ' ' << n << " = ";
                for (auto i: v) cout << i;
                cout << '\n';
                flag = 1;
            }
        } while (next_permutation(v.begin(), v.end()));
        if (!flag)
            cout << s << ' ' << n << " = No permutation\n";
    }
    return 0;
}
