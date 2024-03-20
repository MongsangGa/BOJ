#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
vector<string> arr;
int t, n;

int Compare(string &a, string &b) {
    if (a.size() >= b.size()) return 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            if (Compare(arr[i], arr[i + 1])) {
                res = 0;
                break;
            }
        }
        if (!res) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
