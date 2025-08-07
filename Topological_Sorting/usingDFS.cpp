//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001];
vector<vector<int>> edge(1001);
vector<int> res;
queue<int> q;
void DFS(int u){
	visited[u] = true;
	for(int v : edge[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
	res.push_back(u);
}
void input(){
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		edge[i].push_back(j);
	}
}
int main() {
	memset(visited,false,sizeof(visited));
    freopen("input.txt","r",stdin);
    input();
    for(int i = 1;i<= n;i++){
    	// cout<<visited[i]<<" ";
    	if(!visited[i]){
    		// DFS(i); 
    		BFS(i);
    	}
    }
    reverse(res.begin(),res.end());
    for(auto x: res) cout<<x<<" ";
    return 0;
}
/*
input
7 7
1 2
1 6
2 3
2 4
3 5
4 5
7 6
*/