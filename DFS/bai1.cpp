//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m; // nhập số lượng đỉnh, số lượng cạnh
bool visited[1001];
vector<vector<int>> adj(1001);

void DFS(int u){
	cout<<u<<" ";
	visited[u] = true;
	for(int v:adj[u]){
		if(!visited[v]) DFS(v);
	}
}

int main() {
	memset(visited,false,sizeof(visited)); //  cho toàn bộ mảng visited  = false
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    while(m--){
    	int i,j;cin>>i>>j;
    	adj[i].push_back(j);
    	// Trong đồ thị có hướng thì không dùng dòng dưới này
    	adj[j].push_back(i);
    }
    DFS(1);
    return 0;
}
/*
input
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9

*/