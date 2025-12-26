#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
char c[10][10];
int vis[10];
void dfs(int x,int y){
    if(y==k){
        cnt++;
        return;
    }
    if(x>n)return;
    for(int j=1;j<=n;j++){
        if(c[x][j]=='#'&& !vis[j]){
            vis[j]=1;
            dfs(x+1,y+1);
            vis[j]=0;
        }
    }
    dfs(x+1,y);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cnt=0;
        cin>>n>>k;
        if(n==-1&&k==-1)break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>c[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(1,0);
        cout<<cnt<<'\n';
    }
    return 0;
}