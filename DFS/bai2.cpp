//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
// Tương tự như bài 1 nhưng dùng cho đồ thị có hướng
int n,m;
bool visited[1001];
vector<vector<int>> adj(1001);

void DFS(int u){
	cout<<u<<" ";
	visited[u] = true;
	for(auto v:adj[u]){
		if(!visited[v]) DFS(v);
	}
}

int main() {
	memset(visited,false,sizeof(visited));
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    while (m--){
    	int i,j;cin>>i>>j;
    	// Đồ thị có hướng nên cần push cung đã cho và không push ngược lại như bên đồ thị vô hướng
    	adj[i].push_back(j);
    }
    DFS(1);
    return 0;
}