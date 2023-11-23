#include<bits/stdc++.h>

using namespace std;

int arr[2], res;
string s;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[i - 1])
            arr[s[i] - '0']++;
    res = min(arr[0], arr[1]);
    cout << res;
    return 0;
}
