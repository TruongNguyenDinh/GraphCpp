//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m,s,t; // Nhập số đỉnh, số cạnh, đỉnh bắt đầu, đỉnh kết thúc.
vector<vector<int>> edge(1001);
bool visited[1001];
int trace[1001];
queue<int> q;

void DFS(int u){
	visited[u] = true;
	cout<<u;
	for(int v : edge[u]){
		if(!visited[v]){
			// Ghi lại vết cũ
			trace[v] = u;
			DFS(v);
		}
	}
}

void BFS(int u){
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int x : edge[v]){
			if(!visited[x]){
				// Vết của x là v
				trace[x] = v;
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

void Path(int s, int t){
	DFS(s);
	if(!visited[t]){
		cout<<"No Path ";
	}
	else{
		//Truy vết đường đi
		vector<int> path;
		while(t != s){
			//Thêm đích vào đường đi
			path.push_back(t);
			// Truy vết lại cha của t
			t = trace[t];
		}
		// Thêm điểm khởi đầu
		path.push_back(s);
		// Nghịch đảo vector
		reverse(path.begin(),path.end());
		for(auto x:path) {
			cout<<x;
			if(x == *path.rbegin()) continue;
			cout<<" -> ";
		}
	}
}
int main() {
	memset(visited,false,sizeof(visited));
	memset(trace,0,sizeof(trace));
    freopen("input.txt","r",stdin);
    cin>>n>>m>>s>>t;
    while(m--){
		int i,j;cin>>i>>j;
		edge[i].push_back(j);
		edge[j].push_back(i);
	}
    Path(s,t);
    return 0;
}