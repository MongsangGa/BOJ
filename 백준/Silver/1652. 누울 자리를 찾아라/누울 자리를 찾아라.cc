#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n,xcnt=0,ycnt=0,cnt=0;
    char arr[101][101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",arr[i]);
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i][j]=='.')cnt++;
            else if(arr[i][j]=='X'){
                if(cnt>=2)xcnt++;
                cnt=0;
            }
        }
        if(cnt>=2) xcnt++;
    }
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j][i]=='.')cnt++;
            else if(arr[j][i]=='X'){
                if(cnt>=2)ycnt++;
                cnt=0;
            }
        }
        if(cnt>=2)ycnt++;
    }
    printf("%d %d",xcnt,ycnt);
    return 0;
}
