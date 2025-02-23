#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); i++) {
        stack<char> st;
        bool flag = false;
        for(auto c:s) {
            if (c == '[' || c == '{' || c == '(') {
                flag = true;
                st.push(c);
            }
            else {
                if (c == ']' && st.top() == '[') st.pop();
                if (c == '}' && st.top() == '{') st.pop();
                if (c == ')' && st.top() == '(') st.pop();
            }
        }
        if (st.empty() && flag) answer++;

        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }
    return answer;
}