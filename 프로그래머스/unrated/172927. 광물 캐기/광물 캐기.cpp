#include <bits/stdc++.h>
using namespace std;

map<string, int> piro[3];
vector<int> p;
vector<string> m;

int solve(int index, int pick){
    if(index>=m.size()) return 0;
    int temp=0;
    for(int i=index;i<index+5;i++){
        if(i>=m.size()) continue;
        temp+=piro[pick][m[i]];
    }
    int next=1e9;
    for(int i=0;i<3;i++){
        if(p[i]){
            p[i]--;
            next=min(next, solve(index+5, i));
            p[i]++;
        }
    }
    if(next>=1e9) return temp;
    return temp+next;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 1e9;
    p=picks; m=minerals;
    piro[0]["diamond"]=piro[0]["iron"]=piro[0]["stone"]=1;
    piro[1]["diamond"]=5; piro[1]["iron"]=1; piro[1]["stone"]=1;
    piro[2]["diamond"]=25; piro[2]["iron"]=5; piro[2]["stone"]=1;
    for(int i=0;i<3;i++){
        if(p[i]){
            p[i]--;
            answer=min(answer,solve(0, i));
            p[i]++;
        }
    }
    return answer;
}