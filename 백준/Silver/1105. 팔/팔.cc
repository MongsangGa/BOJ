#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define INF 1e9
#define SIZE 51

int res;
string a, b;

int main() {
    fastio;
    cin >> a >> b;
    if (a.length() != b.length()) cout << 0;
    else {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '8' && a[i] == b[i]) res++;
            else if (a[i] != b[i]) break;
        }
        cout << res;
    }
    return 0;
}
