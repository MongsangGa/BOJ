#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

vector<int> pi;
string s, p;

void failure() {
    pi.resize(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = ++j;
    }
}

int main() {
    fastio;
    string input;
    cin >> input >> p;
    for (auto i: input)
        if (!isdigit(i))
            s += i;
    failure();
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) ++j;
        if (j == p.size()) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
