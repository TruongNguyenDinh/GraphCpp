//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    edge(int _u,int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};
int n,m;
int parent[1001];
vector<pair<int,int>> adj[1001];
vector<edge> MST;
int em[1001];
int res = 0;
bool used[1001];
void input(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        parent[u] = v;
        parent[v] = u;
    }
    for(int i =1;i<=n;i++){
        em[i] = INT_MAX;
    }  
    memset(used,false,sizeof(used)); 
}
void prim(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty()){
        auto top = q.top(); q.pop();
        int u = top.second;
        int w = top.first;
        if(used[u]) continue;
        used[u] = true;
        res += w;
        if(s != u) {
            MST.push_back({u,parent[u],w});
        }
        for(auto it : adj[u]){
            int v= it.first;
            int length = it.second;
            if(!used[v] && length < em[v]){
                q.push({length,v});
                em[v] = length;
                parent[v] = u;
            }
        }
    }
    cout<<res<<endl;
    for(auto x: MST){
        cout<<x.u<<" "<<x.v<<endl;
    }  
}

int main() {
    freopen("input.txt","r",stdin);
    input();
    prim(1);
    return 0;
}