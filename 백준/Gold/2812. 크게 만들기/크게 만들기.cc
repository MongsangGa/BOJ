#include<bits/stdc++.h>

using namespace std;

int N, K, KK, num;
string s, res;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> s;
    KK = K;
    for (int i = 0; i < N; i++) {
        num = s[i] - '0';
        while (!st.empty() && K > 0 && st.top() < num) {
            st.pop();
            K--;
        }
        st.push(num);
    }
    while (!st.empty()) {
        res += st.top() + '0';
        st.pop();
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < N - KK; i++)
        printf("%c", res[i]);
    return 0;
}
