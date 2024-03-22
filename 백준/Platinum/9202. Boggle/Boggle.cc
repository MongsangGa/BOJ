#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, t, dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}, score[] = {0, 0, 0, 1, 1, 2,
                                                                                             3, 5,
                                                                                             11};
char sentence[10], board[5][5];
set<string> res;
bool vis[5][5];

bool Out(int x, int y) {
    if (x < 0 || y < 0 || x >= 4 || y >= 4 || vis[x][y]) return true;
    return false;
}

struct Trie {
    Trie() {}

    map<char, Trie *> m;

    bool finish = false;

    void insert(const char *s) {
        if (!*s) {
            finish = true;
            return;
        }
        if (m.find(*s) == m.end())
            m.insert({*s, new Trie()});
        m[*s]->insert(s + 1);
    }

    void query(int i, int j, string cur) {
        if (Out(i, j) || cur.size() >= 8) return;
        cur += board[i][j];
        vis[i][j] = true;
        if (m.find(board[i][j]) == m.end()) {
            vis[i][j] = false;
            return;
        }
        if (m[board[i][j]]->finish)
            res.insert(cur);
        for (int k = 0; k < 8; k++)
            m[board[i][j]]->query(i + dx[k], j + dy[k], cur);
        vis[i][j] = false;
    }
};


int main() {
    fastio;
    cin >> n;
    Trie *root = new Trie();
    for (int i = 0; i < n; i++) {
        cin >> sentence;
        root->insert(sentence);
    }
    cin >> t;
    while (t--) {
        res.clear();
        for (int i = 0; i < 4; i++)
            cin >> board[i];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                root->query(i, j, "");
        string Lsentece;
        int Tscore = 0;
        for (auto i: res) {
            if (Lsentece.size() < i.size())
                Lsentece = i;
            Tscore += score[i.size()];
        }
        cout << Tscore << ' ' << Lsentece << ' ' << res.size() << '\n';
    }
    return 0;
}