#include <bits/stdc++.h>

using namespace std;

int n;
string s, alpha = "abcdefghijklmnopqrstuvwxyz", sentence[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> n;
    for (int i = 0; i < n; i++) cin >> sentence[i];
    for (int i = 0; i < 26; i++) {
        alpha = alpha.substr(1, 25) + alpha[0];
        string temp = s;
        for (int j = 0; j < temp.size(); j++)
            temp[j] = alpha[temp[j] - 'a'];
        for (int j = 0; j < n; j++) {
            if (temp.find(sentence[j]) != std::string::npos) {
                cout << temp;
                exit(0);
            }
        }
    }
    return 0;
}
