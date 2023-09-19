#include<bits/stdc++.h>

using namespace std;
#define MAX 1'003'003

vector<int> is_prime(MAX);
int n;

int main() {
    cin >> n;
    for (int i = 2; i < MAX; i++) is_prime[i] = i;
    for (int i = 2; i < sqrt(MAX); i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j < MAX; j += i)
            is_prime[j] = 0;
    }
    for (int i = n; i < MAX; i++) {
        if (is_prime[i]) {
            string s, rs;
            s = to_string(i);
            rs = s;
            std::reverse(rs.begin(), rs.end());
            if (s == rs) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}
