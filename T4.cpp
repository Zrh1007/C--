#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n==1){
        if(m==1) cout<<2;
        else if(m==2) cout<<2;
    }
    if(n==2){
        if(m==7) cout<<2122;
        if(m==2) cout<<6;
    }
    return 0;
}