#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int t;

int P(string s, int cnt) {
    int st = 0, en = s.length() - 1, res = 0;
    while (st <= en) {
        if (s[st] == s[en]) st++, en--;
        else {
            res++;
            if (cnt == 1) {
                if (s[st + 1] == s[en]) st++;
                else {
                    res++;
                    break;
                }
            } else {
                if (s[st] == s[en - 1]) en--;
                else {
                    res++;
                    break;
                }
            }
        }
    }
    return res;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int first = P(s, 1), second = P(s, 2);
        int res = min(first, second);
        if (!res) cout << "0\n";
        else if (res == 1)cout << "1\n";
        else cout << "2\n";

    }
    return 0;
}
