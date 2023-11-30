#include<bits/stdc++.h>

using namespace std;

string s, t;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = t.size() - 1; i >= 0; i--) {
        if (s == t) {
            cout << "1";
            exit(0);
        } else if (t[i] == 'A') t.pop_back();
        else {
            t.pop_back();
            std::reverse(t.begin(), t.end());
        }
    }
    cout << "0";
    return 0;
}
