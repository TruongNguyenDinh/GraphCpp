//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Đề bài: cho danh sách cạnh của đồ thị có hướng.
Nhiệm vụ: Sử dụng BFS để duyệt đồ thị và in ra các đỉnh được duyệt
*/
int n,m;
queue<int> q;
vector<vector<int>> edge(1001);
bool visited[1001];

void BFS(int u){
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front(); // lấy phần tử đầu tiên của hàng đợi
		q.pop() ; // xóa nó đi
		cout<<v<<" "; // In ra đỉnh đã đi qua.
		for(auto x : edge[v]){
			if(!visited[x]){
				q.push(x); // thêm đỉnh chưa được duyệt vào hàng đợi
				visited[x] = true; // đánh dấu đỉnh đã dược duyệt
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
    }
    BFS(1);
    return 0;
}
/*
input
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 9
5 8
6 7
7 3
8 9
output
1 2 3 5 10 4 6 9 8 7
*/