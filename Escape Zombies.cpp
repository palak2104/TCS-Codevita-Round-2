#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>arr[i][j]; 
           if(arr[i][j]==0){
               a=i;b=j;
           }
        }
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{a,b}});
    int mini=INT_MAX;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vis[a][b]=1;
    while(q.size()!=0){
        auto it=q.front();
        int d=it.first;
        int i=it.second.first;
        int j=it.second.second;
        vis[i][j]=1;
        q.pop();
        if(i==0 || i==n-1||j==0||j==m-1){
            //cout<<d+arr[i][j]<<endl;
            mini=min(mini,d+arr[i][j]);
            continue;
        }
        vector<int>di{-1,-1,-1,0,0,1,1,1};
        vector<int>dj{-1,0,1,-1,1,1-1,0,1};
        for(int k=0;k<8;k++){
        int x=i+di[k];
        int y=j+dj[k];
        if(vis[x][y]==0){
            q.push({arr[i][j]+d,{x,y}});
        }
        }
    }
    cout<<mini;
    return 0;
}
