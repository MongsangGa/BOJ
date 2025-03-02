#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string s) {
    stack<char> st;
    for(auto c:s) {
        if(c == '(') st.push(c);
        else if(!st.empty()) st.pop();
    }
    if(st.empty()) return true;
    else return false;
}

string deleteReverse(string s) {
    s.erase(s.begin()), s.erase(s.end()-1);
    for(int i=0;i<s.size();i++)
        s[i] = (s[i] == '(') ? ')' : '(';
    return s;
}

string divide(string s) {
    if(s.empty()) return s;
    int open = 0, close = 0, idx = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') ++open;
        else ++close;
        if(open == close) {
            idx = i+1;
            break;
        }
    }
    string res = "";
    string u = s.substr(0,idx), v = s.substr(idx);
    if(isCorrect(u)) 
        res = u + divide(v);
    else
        res = '(' + divide(v) + ')' + deleteReverse(u);
    return res;
}

string solution(string p) {
    string answer = divide(p);
    return answer;
}