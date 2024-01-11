#include <bits/stdc++.h>

using namespace std;

int n;
string s, res, arr[] = {"000000",
                        "001111",
                        "010011",
                        "011100",
                        "100110",
                        "101001",
                        "110101",
                        "111010"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int chk = 0;
        string temp = s.substr(i * 6, 6);
        for (int j = 0; j < 8; j++) {
            int cnt = 0;
            for (int k = 0; k < 6; k++)
                if (temp[k] != arr[j][k])
                    cnt++;
            if (cnt <= 1) {
                res += 'A' + j;
                chk = 1;
                break;
            }
        }
        if (!chk) {
            cout << i + 1;
            return 0;
        }
    }
    cout << res;
    return 0;
}
