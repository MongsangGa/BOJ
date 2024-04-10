#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

string s, res;
stack<char> st;

int main() {
    fastio;
    cin >> s;
    for (auto c: s) {
        if (isalpha(c)) {
            res += c;
            continue;
        } else if (c == '(') {
            st.push(c);
            continue;
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(')
                res += st.top(), st.pop();
            st.pop();
            continue;
        } else if (c == '*' || c == '/')
            while (!st.empty() && (st.top() == '*' || st.top() == '/'))
                res += st.top(), st.pop();
        else if (c == '+' || c == '-')
            while (!st.empty() && st.top() != '(')
                res += st.top(), st.pop();
        st.push(c);
    }
    while (!st.empty()) res += st.top(), st.pop();
    cout << res;
    return 0;
}
