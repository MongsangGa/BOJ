#include<bits/stdc++.h>
using namespace std;
bool arr[20][20][20][20][4];
int N,res,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
string str[21];
pair<int,int> cango(int x, int y, int dir){
    int nx=x+dx[dir], ny=y+dy[dir];
    if(nx<0 || nx>=N || ny<0 || ny>=N || str[nx][ny]=='H') return {x, y};
    return {nx, ny};
}
struct node{
    int x1,y1,x2,y2,dir;
    node left(){
        return {x1,y1,x2,y2,(dir+3)%4};
    }
    node right(){
        return {x1,y1,x2,y2,(dir+1)%4};
    }
    node go(){
        node temp;
        if(x1==0 && y1==N-1) temp.x1=x1, temp.y1=y1;
        else tie(temp.x1, temp.y1) = cango(x1, y1, dir);
        if(x2==0 && y2==N-1) temp.x2=x2, temp.y2=y2;
        else tie(temp.x2, temp.y2) = cango(x2, y2, (dir+1)%4);
        temp.dir=dir;
        return temp;
    }
};
queue<node> q;
void visit(node n){
    auto &x = arr[n.x1][n.y1][n.x2][n.y2][n.dir];
    if(x || str[n.x1][n.y1]=='H' || str[n.x2][n.y2]=='H') return;
    x=true;
    q.push(n);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) cin>>str[i];
    q.push({N-1,0,N-1,0,0});
    arr[N-1][0][N-1][0][0]=0;
    while(true){
        ++res;
        int qsize=q.size();
        for(int i=0;i<qsize;i++){
            auto x=q.front();
            q.pop();
            visit(x.left());
            visit(x.right());
            visit(x.go());
        }
        for(int i=0;i<4;i++){
            if(arr[0][N-1][0][N-1][i]){
                printf("%d",res);
                exit(0);
            }
        }
    }
    return 0;
}
