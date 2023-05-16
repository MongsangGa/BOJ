#include <bits/stdc++.h>
using namespace std;


char direction[]={'N','S','W','E'};
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
pair<int, int> start;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x=park.size(), y=park[0].size();
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            if(park[i][j]=='S')
                start.first=i, start.second=j;
    int now_x=start.first, now_y=start.second;
    int r_x=routes.size();
    for(int i=0;i<r_x;i++){
        for(int j=0;j<4;j++){
            char c=routes[i][0];
            int n=routes[i][2]-'0';
            int temp_x=now_x, temp_y=now_y;
            if(c==direction[j]){
                while(n--){
                    int nx=now_x+dx[j], ny=now_y+dy[j];
                    if(nx<0 || ny<0 || nx>=x || ny>=y || park[nx][ny]=='X'){
                        now_x=temp_x, now_y=temp_y;
                        break;
                    }
                    now_x+=dx[j], now_y+=dy[j];
                }
                break;
            }
        }
    }
    answer.push_back(now_x);
    answer.push_back(now_y);
    return answer;
}