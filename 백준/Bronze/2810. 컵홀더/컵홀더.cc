#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, res;
string s;

int main() {
    fastio;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') res++;
        else i++, res++;
    }
    cout << min(n, res + 1);
    return 0;
}
