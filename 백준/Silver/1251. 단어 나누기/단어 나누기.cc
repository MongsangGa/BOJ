#include<bits/stdc++.h>

using namespace std;

int len;
string s, res = "~";

int main() {
    cin >> s;
    len = s.size();
    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            string temp;
            for (int x = i; x >= 0; x--) temp += s[x];
            for (int y = j; y > i; y--) temp += s[y];
            for (int z = len - 1; z > j; z--) temp += s[z];
            if (res > temp) res = temp;
        }
    }
    cout << res;
    return 0;
}
