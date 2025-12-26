#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y;
}f[200];
long long x[1500],y[1500],z[1500],idx,h[1500],res;
bool vis[3000];
long long n,k,r;
bool check(long long xi,long long yi,long long nx,long long ny,long long res){
    long long dx=xi-nx;
    long long dy=yi-ny;
    return dx*dx+dy*dy<=(res+r)*(res+r);
}
void dfs(long long step){
    if(step>k){
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=k;j++){
                long long nx=f[h[j]].x,ny=f[h[j]].y;
                if( sqrt((x[i] - nx) * (x[i] - nx) + (y[i] - ny) * (y[i] - ny)) <= z[i] + r){
                    cnt++;
                    break;
                }
            }
        }
        res=max(cnt,res);
        return;
    }
    for(long long i=1;i<=idx;i++){
        if(!vis[i]){
            vis[i]=1;
            h[step]=i;
            dfs(step+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    cin>>n>>k>>r;
    for(long long i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for(long long i=-5;i<=5;i++){
        for(long long j=-5;j<=5;j++){
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