#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int alpha[27], check = -1;
string s, temp;

int main() {
    fastio;
    cin >> s;
    for (auto c: s) alpha[c - 'A']++;
    for (int i = 0; i < 27; i++) {
        if (alpha[i] % 2) {
            if (check != -1) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
            check = i;
        }
        for (int j = 0; j < alpha[i] / 2; j++)
            temp += i + 'A';
    }
    cout << temp;
    if (check != -1) cout << char(check + 'A');
    reverse(temp.begin(), temp.end());
    cout << temp;
    return 0;
}