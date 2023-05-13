#include <bits/stdc++.h>
using namespace std;
#define MAX 501
int n,m,arr[MAX][MAX],res;
int tetris[19][4][2]={
    { {0,0}, {0,1}, {1,0}, {1,1} }, // ㅁ
    { {0,0}, {0,1}, {0,2}, {0,3} }, // ㅡ
    { {0,0}, {1,0}, {2,0}, {3,0} },
    { {0,0}, {0,1}, {0,2}, {1,0} }, // ㄴ
    { {0,2}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,2} },
    { {0,0}, {1,0}, {2,0}, {2,1} },
    { {0,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {0,1}, {1,0}, {2,0} },
    { {0,1}, {1,1}, {2,0}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,1} }, // ㄱㄴ
    { {0,1}, {1,0}, {1,1}, {2,0} },
    { {0,1}, {0,2}, {1,0}, {1,1} },
    { {0,0}, {0,1}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,1} }, // ㅗ
    { {0,1}, {1,0}, {1,1}, {1,2} },
    { {0,1}, {1,0}, {1,1}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,0} }
};
int solve(int x, int y){
    int sum=0;
    for(int i=0;i<19;i++){
        int temp=0;
        for(int j=0;j<4;j++){
            int nx=x+tetris[i][j][0], ny=y+tetris[i][j][1];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            temp+=arr[nx][ny];
        }
        sum=max(sum,temp);
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            res=max(res,solve(i,j));
    cout<<res;
    return 0;
}
