#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s[8];

int solution(int N, int number) {
    int answer = -1;
    
    int num = 0;
    for(int i=0;i<8;i++) {
        num = 10 * num + N;
        s[i].insert(num);
    }
    for(int i=1;i<8;i++) {
        for(int j=0;j<i;j++) {
            for(int a:s[j]) {
                for(int b:s[i-j-1]) { 
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b) s[i].insert(a/b);
                }
            }
        }
    }
    for(int i=0;i<8;i++) {
        if(s[i].find(number) != s[i].end()) {
            answer = i+1;
            break;
        }
    }
    return answer;

}