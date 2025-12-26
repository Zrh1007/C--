#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
char c[10][10];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[11][11];
void dfs(int x,int y,int ans){
    if(ans>=k){
        cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(vis[nx][1]==0&&vis[1][ny]==0&&c[nx][ny]=='#'){
            vis[nx][1]=1;
            vis[1][ny]=1;
            dfs(nx,ny,ans+1);
            vis[nx][1]=0;
            vis[1][ny]=0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(1){
        cnt=0;
        cin>>n>>k;
        if(n==-1&&k==-1) break;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>c[i][j];
            }
        }
        dfs(0,0,0);
        cout<<cnt<<'\n';
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++) vis[i][j]=0;
        }
    }
    return 0;
}