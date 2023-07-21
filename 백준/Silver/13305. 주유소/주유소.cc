#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
#define pMAX 1000000001

int n, dist[MAX], price[MAX];
long long int res;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> dist[i];
    for (int i = 0; i < n; i++) cin >> price[i];
    st.push(pMAX);
    for (int i = 0; i < n - 1; i++) {
        if (st.top() > price[i]) {
            st.pop();
            st.push(price[i]);
        }
        res += st.top() * dist[i];
    }
    cout << res;
    return 0;
}