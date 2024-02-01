#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 1002

string s;

int main() {
    fastio;
    cin >> s;
    s = regex_replace(s, regex("XXXX"), "AAAA");
    s = regex_replace(s, regex("XX"), "BB");
    for (auto c: s) {
        if (c == 'X') {
            cout << -1;
            exit(0);
        }
    }
    cout << s;
    return 0;
}
