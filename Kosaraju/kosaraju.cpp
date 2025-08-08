//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m; // số lượng đỉnh, số lượng cạnh
vector<int> adj[1001]; // danh sách kề
vector<int> tg[1001]; // transpose graph: đảo chiều cung
bool visited[1001]; // Thăm 
stack<int> st; // ngăn xếp



void DFS(int u){ // DFS duyệt đồ thị G = (V,E)
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
	st.push(u); // Tại các phần tử không mở rộng được nữa sẽ được đẩy vào stack
}
void DFS_TG(int u){ // duyệt đồ thị Transpose của G với BFS cơ bản
	visited[u] = true;
	cout<<u<<" ";
	for(int v : tg[u]){
		if(!visited[v]){
			DFS_TG(v);
		}
	}
}

int Korasaju(){
	//Duyệt các đỉnh của G
	memset(visited,false,sizeof(visited));
	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			DFS(i);
		}
	}
	// Duyệt các đỉnh của TG và đếm số thành phần liên thông mạnh (strong connected component)
	int cnt = 0;
	memset(visited,false,sizeof(visited));
	while(!st.empty()){
		int u = st.top(); st.pop();
		if(!visited[u]){
			cout<<"Thành phần liên thông mạnh thứ "<<++cnt<<" :"; 
			DFS_TG(u);
			cout<<endl;
		}
	}
	return cnt;
}

void input(){
	cin>>n>>m;
	while(m--){
		int i,j; cin>>i>>j;
		adj[i].push_back(j); // danh sách kề cho đồ thị G
		tg[j].push_back(i); //  danh sách kề cho đồ thị TG
	}
}


int main() {
    freopen("input.txt","r",stdin);
    input();
    cout<<"SCC: \n"<<Korasaju();
    return 0;
}