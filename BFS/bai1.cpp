//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Đề bài: cho danh sách cạnh của đồ thị vô hướng.
Nhiệm vụ: Sử dụng BFS để duyệt đồ thị và in ra các đỉnh được duyệt
*/

int n,m; // số đỉnh và cạnh của đồ thị
bool visited[1001]; // mảng đánh dấu các đỉnh đã được duyệt
queue<int> q;
vector<vector<int>> edge(1001);
void BFS(int u){
	q.push(u); visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout<<v<<" ";
		for(auto x:edge[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}

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
    BFS(1);
    return 0;
}
/*
input
10 10
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
5 8
6 7
output
1 2 3 5 10 4 6 7 9 8
*/