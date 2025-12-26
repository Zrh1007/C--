#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}f[200];
int x[15],y[15],z[15],idx,h[5],res;
bool vis[300];
int n,k,r;
bool check(int xi,int yi,int nx,int ny,int res){
    int dx=xi-nx;
    int dy=yi-ny;
    return dx*dx+dy*dy<=(res+r)*(res+r);
}
void dfs(int step){
    if(step>k){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int nx=f[h[j]].x,ny=f[h[j]].y;
                if(check(x[i],y[i],nx,ny,z[i])){
                    cnt++;
                    break;
                }
            }
        }
        res=max(cnt,res);
        return;
    }
    for(int i=1;i<=idx;i++){
        if(!vis[i]){
            vis[i]=1;
            h[step]=i;
            dfs(step+1);
            vis[i]=0;
        }
    }
}
int main(){
    cin>>n>>k>>r;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=-5;i<=5;i++){
        for(int j=-5;j<=5;j++){
            f[++idx]={i,j};
        }
    }
    dfs(1);
    cout<<res;
    return 0;
}

/*
# T715077 dfs-二维选和不选-2

## 题目描述

在一个二维平面上有n个敌人，第i个敌人可以描述为一个以$(x_i, y_i)$ 为圆心，$r_i$ 为半径的圆。你每次可以对一个半径为R的圆的范围内进行攻击(圆心自选，但是圆心的横纵坐标必须为整数)，对于与你攻击范围有交点的敌人都会被消灭，你总共可以发动 $k$ 次攻击，问最多可以消灭多少敌人。

坐标系中 $2$ 点的距离公式：`sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))`

## 输入格式

第一行以空格分隔的三个整数n、k、R

接下来n行每行输入三个整数xi、yi、ri

## 输出格式

输出一个正整数代表答案

## 输入输出样例 #1

### 输入 #1

```
3 1 1
0 0 1
5 5 1
-2 0 1
```

### 输出 #1

```
2
```

## 说明/提示

$10pts: 1 <= n <= 10, k == 2, 1 <= ri,R <= 5, 0 <= xi,yi <= 5$

$30pts: 1 <= n <= 10, 1 <= k <= 3, 1 <= ri,R <= 5, 0 <= xi,yi <= 5$

$100pts: 1 <= n <= 10, 1 <= k <= 3, 1 <= ri,R <= 5, 0 <= |xi|,|yi| <= 5 $
*/