#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

string s, match;
stack<pair<char, int>> st;

int main() {
    fastio;
    cin >> s >> match;
    int l = 0, mL = match.size();
    for (auto c: s) {
        if (c == match[l]) l++;
        else if (c == match[0]) l = 1;
        else l = 0;
        st.push({c, l});
        if (l == mL) {
            for (int i = 0; i < mL; i++) st.pop();
            if (!st.empty()) l = st.top().second;
            else l = 0;
        }
    }
    string res;
    while (!st.empty()) {
        res += st.top().first;
        st.pop();
    }
    reverse(res.begin(), res.end());
    if (!res.size()) cout << "FRULA";
    else cout << res;
    return 0;
}
