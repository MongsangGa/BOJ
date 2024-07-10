#include<bits/stdc++.h>

using namespace std;

stack<int> st;
string s;
int vis[52];

int f(int start, int end) {
    int res = 0;
    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            int K = s[i - 1] - '0';
            res += K * f(i + 1, vis[i]) - 1;
            i = vis[i];
        } else ++res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') vis[st.top()] = i, st.pop();
    }
    cout << f(0, s.size());
    return 0;
}
