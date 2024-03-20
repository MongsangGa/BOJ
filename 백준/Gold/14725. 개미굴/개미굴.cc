#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
int t, n;

struct Trie {
    map<string, Trie *> m;

    Trie() {}

    ~Trie() {
        for (map<string, Trie *>::iterator iter = m.begin(); iter != m.end(); iter++)
            delete (*iter).second;
    }

    void INSERT(vector<string> &s, int idx) {
        if (idx == s.size()) return;
        if (m.find(s[idx]) == m.end()) {
            m.insert({s[idx], new Trie()});
            m[s[idx]]->INSERT(s, idx + 1);
        } else m[s[idx]]->INSERT(s, idx + 1);
    }

    void FIND(int dep) {
        for (map<string, Trie *>::iterator iter = m.begin(); iter != m.end(); iter++) {
            for (int i = 0; i < dep; i++) cout << "--";
            cout << (*iter).first << '\n';
            (*iter).second->FIND(dep + 1);
        }
    }
};

int main() {
    fastio;
    cin >> t;
    Trie *root = new Trie();
    while (t--) {
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        root->INSERT(s, 0);
    }
    root->FIND(0);
    delete root;
    return 0;
}
