#include<bits/stdc++.h>

using namespace std;

stack<char> st;
bool is_tag;
string s, res;

void print_stack(stack<char> &st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    std::getline(cin, s);
    for (auto &c: s) {
        if (c == '<') {
            is_tag = true;
            print_stack(st);
            cout << c;
        } else if (c == '>') {
            is_tag = false;
            cout << c;
        } else if (is_tag) cout << c;
        else {
            if (c == ' ') {
                print_stack(st);
                cout << c;
            } else st.push(c);
        }
    }
    print_stack(st);
    return 0;
}
