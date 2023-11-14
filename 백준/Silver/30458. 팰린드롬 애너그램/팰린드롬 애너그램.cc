#include <bits/stdc++.h>

using namespace std;

int n, res;
char ch, s[27], mid;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        s[ch - 'a']++;
        if (i == n / 2) mid = ch;
    }
    for (int i = 0; i < 27; i++) {
        if (i == mid - 'a') continue;
        if (s[i] % 2) res++;
    }
    if (!res) cout << "Yes";
    else cout << "No";
    return 0;
}
