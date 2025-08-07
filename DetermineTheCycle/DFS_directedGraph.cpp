//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m;
int color[1001];
vector<int> adj[1001];
bool DFS(int u){
	color[u] = 1;
	for(int v : adj[u]){
		if(color[v]==0){
			if(DFS(v)) return true;
		}
		// Nếu từ một đỉnh đang thăm (màu xám) mà gặp một đỉnh khác cũng đang thăm (màu xám),
		// tức là tồn tại chu trình (đã quay lại một đỉnh tổ tiên trong ngăn xếp đệ quy).

		//Hay nói cách khác một đỉnh màu xám chỉ có thể đi đến một đỉnh màu trắng thì đồ thì mới không có chu trình hoặc 
		// bản thân nó phải thành màu đen
		else if( color[v]==1){
			return true	;
		}
	}
	color[u] = 2;
	return false;
}

void ConnectedComponent(){
	for(int i = 1;i<=n;i++){

	}
}

void input(){
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		adj[i].push_back(j);
	}
}

int main() {
    freopen("input.txt","r",stdin);
    input();
    if(DFS(1)){
    	cout<<"Exist the cycle";
    }
    else{
    	cout<<"Don't exist the cycle";
    }
    return 0;
}
/*
input 
7 7
1 2
1 5
2 3
3 6
4 2
6 7
3 7
*/