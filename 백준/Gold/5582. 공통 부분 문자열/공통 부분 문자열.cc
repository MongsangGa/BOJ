#include <bits/stdc++.h>

using namespace std;

#define SIZE 4001
int arr[SIZE][SIZE], res;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                res = max(res, arr[i][j]);
            }
        }
    }
    cout << res;
    return 0;
}
