#include <bits/stdc++.h>

using namespace std;

int len,sum,r,l;
vector<tuple<int,int,int>> res;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    sum=0, l=0, r=-1;
    len=sequence.size();
    while(l<len && r<len){
        if(sum==k){
            res.push_back({r-l, l, r});
            r++;
            sum+=sequence[r];
        }
        else if(sum<k){
            r++;
            sum+=sequence[r];
        }
        else if(sum>k){
            sum-=sequence[l];
            l++;
        }
    }
    sort(res.begin(),res.end());
    answer.push_back(get<1>(res[0]));
    answer.push_back(get<2>(res[0]));
    return answer;
}