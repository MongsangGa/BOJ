#include <bits/stdc++.h>

using namespace std;

char alpha[16];

int l, c;

bool is_possible(string s) {
    int mo, ja;
    mo = ja = 0;
    for (char i: s) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            mo++;
        else ja++;
        if (mo >= 1 && ja >= 2) return true;
    }
    return false;
}

void solve(string s, int idx) {
    if (s.length() == l) {
        if (is_possible(s))
            cout << s << '\n';
        return;
    }
    if (idx >= c) return;
    solve(s + alpha[idx], idx + 1);
    solve(s, idx + 1);
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> alpha[i];
    sort(alpha, alpha + c);
    solve("", 0);
    return 0;
}
