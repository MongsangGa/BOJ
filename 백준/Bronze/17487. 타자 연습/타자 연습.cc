#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

string s, ls = "qwertyasdfgzxcvb";
int l, r, upper;

int main() {
    fastio;
    getline(cin, s);
    for (auto c: s) if (isupper(c) || isspace(c)) ++upper;
    for (auto &c: s) c = tolower(c);
    for (auto c: s) {
        if (!isalpha(c)) continue;
        bool flag = 0;
        for (auto fc: ls)
            if (c == fc)
                ++l, flag = 1;
        if (!flag) ++r;
    }
    while (upper--) {
        if (l > r) ++r;
        else ++l;
    }
    cout << l << ' ' << r;
    return 0;
}
