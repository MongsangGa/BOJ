#include <bits/stdc++.h>
using namespace std;

string board[20];

string f(int n,int s){
    
    string result = "";
    while(n > 0) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    
    if(result.size() != s)
        for(int i = 0; s - result.size(); i++)
            result = '0' + result;

    for(int i = 0; i<result.size(); i++) {
        if(result[i] == '1') 
            result[i] = '#';
        else if(result[i] == '0') 
            result[i] = ' ';
    }
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0;i<arr1.size(); i++)
        answer.push_back(f(arr1[i] | arr2[i], n));
    return answer;
}