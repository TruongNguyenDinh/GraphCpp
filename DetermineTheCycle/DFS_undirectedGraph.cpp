//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m; // số đỉnh, cạnh của đồ thị.
int start,eNd; // lấy điểm đầu và kết thúc để truy vết
bool visited[1001]; // mảng thăm
vector<int> path; // vector đường đi
vector<vector<int>> adj(1001); // danh sách kề
int parent[1001]; // mảng lưu parent của đỉnh đang xét
//Phiên bản hai đối số
bool DFS(int u, int par){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			if(DFS(v,u)) return true;
		}
		else if(v != par){
			return true;
		}
	}
	return false;
}
//Phiên bản 1 đối số
bool DFS1(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			if(DFS1(v)) {
				return true;
			}
		}
		else if( v != parent[u]) {
			start = v; // Điểm khởi đầu cũng là điểm kết thúc của chu trình ( 1 - 2 - 3 - 1)
			eNd = u; // u lúc này chính là điểm trước khi trởi lại điểm khởi đầu
			return true;
		}
	}
	return false;
}
void input(){
	cin>>n>>m;
	while(m--){
		int i,j;
		cin>>i>>j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	memset(visited,false,sizeof(visited));
}
// Hàm sử dụng cho đồ thị vô hướng liên thông hay không liên thông 
// -> hàm tổng quát cho bài
void ConnectedComponent(){
	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			if(DFS1(i)){
				cout<<"Exist the cycle \n";
				// Tạo biến tạm thời u và v
				int u = start; int v = eNd;
				// Thêm điểm khởi đầu chu trình
				path.push_back(u);
				while(v != u){ // Kiểm tra xem u có khác v không
					path.push_back(v); 
					v = parent[v];// truy vết lai parent của v
				}
				path.push_back(u);// đẩy lại điểm đầu cũng là điểm cuối
				return;
			}
		}
	}
	cout<<"Don't exist the cycle! ";
}
int main() {
    freopen("input.txt","r",stdin);
    input();
    ConnectedComponent();
    reverse(path.begin(),path.end());
    for(auto x: path) {
    	cout<<x<<" ";
    }
    return 0;
}
/* 
input
7 6
1 2
2 3
2 4
3 6
3 7
6 7
*/