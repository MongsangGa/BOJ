#include <bits/stdc++.h>

using namespace std;
map<string,int> namevalue;


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<name.size();i++) namevalue[name[i]]=yearning[i];
    for(int i=0;i<photo.size();i++){
        int res=0;
        for(auto s:photo[i])
            res+=namevalue[s];
        answer.push_back(res);
    }
    return answer;
}