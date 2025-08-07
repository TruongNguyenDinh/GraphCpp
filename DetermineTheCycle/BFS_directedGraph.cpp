//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
int n,m; // Số đỉnh và số cạnh của đồ thị
vector<int> adj[1001]; //  danh sách kề (đỉnh kề)
int in_degree[1001];

bool BFS(int u){
	int cnt =0;
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(in_degree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		cout<<v<<" ";
		cnt++;
		for(int x: adj[v]){
			in_degree[x]--;
			if(in_degree[x]==0){
				q.push(x);
			}
		}
	}
	return cnt == n;
}

void input(){
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		adj[i].push_back(j);
		in_degree[j]++;
	}
}

int main() {
    freopen("input.txt","r",stdin);
    input();
    if(BFS(1)){
    	cout<<"Exist the cycle";
    }
    else cout<<"Don't exist the cycle";
    return 0;
}