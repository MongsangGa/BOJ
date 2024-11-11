#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

int w, n, arr[5001];
bool chk[800'000];

int main() {
    fastio;
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] > w) continue;
            if (chk[w - arr[i] - arr[j]]) {
                cout << "YES";
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
            chk[arr[i] + arr[j]] = 1;
    }
    cout << "NO";
    return 0;
}
