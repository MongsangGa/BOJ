#include<bits/stdc++.h>

using namespace std;

int n, m, res, arr[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++) {
        int cnt_1, cnt_2, now;
        cnt_1 = cnt_2 = now = 0;
        for (int j = 0; j < m; j++) {
            if (now != arr[i][j]) {
                if (!arr[i][j]) {
                    res += min(cnt_1, cnt_2) + 1;
                    cnt_1 = cnt_2 = 0;
                } else if (arr[i][j] == 1) cnt_1++;
                else if (arr[i][j] == 2) cnt_2++;
                now = arr[i][j];
            }
        }
        if (cnt_1 || cnt_2) res += min(cnt_1, cnt_2) + 1;
    }
    cout << res;
    return 0;
}
