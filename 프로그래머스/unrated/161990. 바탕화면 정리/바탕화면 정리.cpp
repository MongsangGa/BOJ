#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int w_x=wallpaper.size(), w_y=wallpaper[0].size();
    int x_min=1e9, x_max=0, y_min=1e9, y_max=0;
    for(int i=0;i<w_x;i++){
        for(int j=0;j<w_y;j++){
            if(wallpaper[i][j]=='#'){
                x_min=min(x_min, i);
                y_min=min(y_min, j);
                x_max=max(x_max, i);
                y_max=max(y_max, j);
            }
        }
    }
    answer.push_back(x_min);
    answer.push_back(y_min);
    answer.push_back(x_max+1);
    answer.push_back(y_max+1);
    return answer;
}