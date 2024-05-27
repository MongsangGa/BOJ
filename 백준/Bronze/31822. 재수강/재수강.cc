#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, res;
string t, s;

int main() {
    fastio;
    cin >> t >> n;
    while (n--) {
        cin >> s;
        if (t.substr(0, 5) == s.substr(0, 5)) 
            res++;
    }
    cout << res;
    return 0;
}
