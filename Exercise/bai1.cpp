//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
// Đề bài tại readme
int n,m;
vector<vector<int>> edge(1001);
bool visited[1001];
queue<int> q;

void DFS(int u){
	cout<<u<<" ";
	visited[u] = true;
	for(int v: edge[u]){
		if(v == 0) continue;
		if(!visited[v]){
			DFS(v);
		}
	}
}

void BFS(int u){
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();q.pop();
		if(v==0) continue;
		cout<<v<<" ";
		for(int x : edge[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}


int ConnectedComponet(){
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			cnt++;
			cout<<"ConnectedComponet "<<cnt<<": ";
			// BFS(i);
			DFS(i);
			cout<<endl;
		}
	}
	return cnt;
}

int main() {
	memset(visited,false,sizeof(visited));
    freopen("input.txt","r",stdin);
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		edge[i].push_back(j);
		edge[j].push_back(i);
	}
	cout<<"The Number of ConnectedComponets: \n"<<ConnectedComponet();
    return 0;
}
/*
input 
10 9
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
10 0
*/