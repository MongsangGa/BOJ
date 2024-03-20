#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n;
char c[100002][82];

struct Trie {
    int child = 0;
    map<char, Trie *> m;
    bool end = false;

    Trie() {}

    void insert(const char *s) {
        if (!*s) {
            end = true;
            return;
        }
        if (m.find(*s) == m.end())
            m.insert({*s, new Trie()}), child++;
        m[*s]->insert(s + 1);
    }

    int query(const char *s) {
        if (!*s) return 0;
        if (child > 1 || (child == 1 && end)) return m[*s]->query(s + 1) + 1;
        return m[*s]->query(s + 1);
    }
};

int main() {
    fastio;
    while (cin >> n) {
        Trie *root = new Trie();
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            root->insert(c[i]);
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += root->query(c[i]);
            if (root->child == 1) res += 1;
        }
        res /= double(n);
        printf("%.2lf\n", res);
    }
    return 0;
}
