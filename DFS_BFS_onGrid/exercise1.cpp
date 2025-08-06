//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m; // Số hàng, số cột của lưới 
char a[1001][1001]; // lưu lưới
bool visited[1001][1001]; // Mảng đánh dấu đã thăm chưa ?
queue<pair<int,int>> q;
int dx[4]= {-1,0,0,1}; // Lưu sự di chuyển của i
int dy[4]= {0,-1,1,0}; // lưu sự di chuyển của j

void DFS(int i,int j){
	visited[i][j] = true;
	//Duyệt các đỉnh kề
	for(int k = 0;k<4;k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <=n && j1>=1 && j1 <=m && a[i1][j1]=='x' && !visited[i1][j1]){
			DFS(i1,j1);
		}
	}
}
void BFS(int i,int j){
	q.push({i,j});
	visited[i][j] = true;
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		for(int k = 0; k < 4;k++){
			int i1 = p.first + dx[k];
			int j1 = p.second + dy[k];
			if(i1 >= 1 && i1 <=n && j1>=1 && j1 <=m && a[i1][j1]=='x' && !visited[i1][j1]){
				q.push({i1,j1});
				visited[i1][j1] = true;
			}
		}
	}
}
int main() {
	memset(visited,false,sizeof(visited));
    freopen("input.txt","r",stdin);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		for(int j = 1;j<=m;j++){
 			cin>>a[i][j];
 		}
 	}
 	int cnt = 0;
 	for(int i = 1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			if(a[i][j]=='x' && !visited[i][j]){
 				cnt++;
 				BFS(i,j);
 			}
 		}
 	}
 	cout<<cnt;
    return 0;
}
/*
input
6 6
x x x o o o
o o x o o o
o x x x x o
o o o o o x
x x o x o x
x o x x o x
output
4
*/