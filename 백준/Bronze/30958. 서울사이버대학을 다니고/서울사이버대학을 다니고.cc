#include <bits/stdc++.h>

using namespace std;

int n, arr[27], res;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for (auto &c: s)
        if (c >= 'a' && c <= 'z')
            arr[c - 'a']++;
    for (int i = 0; i < 27; i++)
        res = max(res, arr[i]);
    cout << res;
    return 0;
}
