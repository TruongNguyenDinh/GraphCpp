//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
int n,m; // Số đỉnh và số cạnh của đồ thị
bool visited[1001]; // mảng kiếm tra đã thăm đỉnh đang xét hay chưa ?
vector<vector<int>> adj(1001); // danh sách kề
int parent[1001];
bool BFS(int u){
	queue<int> q; q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x); visited[x] = true;
				parent[x] = v;
			}
			else if(x != parent[v]){
				return true; // tồn tại một cạnh ngược
			}
		}
	}
	return false;
}

void ConnectedComponent(){
	for(int i = 1;i<= n;i++){
		if(!visited[i]){
			if(BFS(i)){
				cout<<"Exist the cycle\n";
				return ;
			}
		}
	}
	cout<<"Don't exist the cycle !";
}

void input(){
	cin>>n>>m; // nhập số đỉnh, số cạnh của đồ thị
	while(m--){
		int u,v;// cạnh (u,v) tức là từ đình u đến đỉnh v
		cin>>u>>v;
		// vì đây là đồ thị vô hướng nên là 1 cạnh (u,v) cũng được gọi là (v,u)
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited,false,sizeof(visited)); 
}

int main() {
    freopen("input.txt","r",stdin);
    input();
    ConnectedComponent();
    return 0;
}
/*
input
8 6
1 2
2 3
3 4
4 5
4 6
5 6
5 7
*/