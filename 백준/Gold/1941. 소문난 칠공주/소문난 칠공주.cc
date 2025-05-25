#include <bits/stdc++.h>
using namespace std;
string s[5];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},res=0;
bool C[25]={0};
int main(){
    for(int i=0;i<5;i++) cin>>s[i];
    fill(C+7,C+25,true);
    //for(int i=0;i<25;i++) cout<<C[i];
    do{
        int cnt=0,z=0;
        bool check[5][5]={0},visit[5][5]={0};
        queue<pair<int,int> >q;
        for(int i=0;i<25;i++){
            int x=i/5,y=i%5;
            if(!C[i]){
                check[x][y]=true;
                if(q.empty()){q.push({x,y}); visit[x][y]=true;}
            }
        }
        while(!q.empty()){
            int x,y;
            tie(x,y)=q.front();
            q.pop();
            cnt++;
            if(s[x][y]=='S') z++;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=5 || ny>=5 || visit[nx][ny] || !check[nx][ny]) continue;
                q.push({nx,ny});
                visit[nx][ny]=true;
            }
        }
        if(cnt>=7 && z>=4) res++;
    }while(next_permutation(C,C+25));
    cout<<res;
    return 0;
}
