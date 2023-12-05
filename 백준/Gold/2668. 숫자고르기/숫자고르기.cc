#include<bits/stdc++.h>

using namespace std;

#define SIZE 102
int n, arr[SIZE], chk[SIZE], res;

void DFS(int x, int target) {
    for (int i = 1; i <= n; i++) {
        if (x == target) {
            res++;
            chk[x]++;
            return;
        }
        x = arr[x];
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) DFS(arr[i], i);
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        if (chk[i])
            cout << i << '\n';
    return 0;
}