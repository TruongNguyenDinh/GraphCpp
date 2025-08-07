//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> edge(1001);
vector<int> topo;
int in[1001]; // bán bậc vào của các đỉnh
void Kahn(){
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();q.pop(); // rút đỉnh u khỏi hàng đợi
		topo.push_back(u); // Thêm đỉnh đã có bán bậc vào bằng 0 vào topo
		for(int v : edge[u]){
			in[v]--;
			if(in[v]==0) { // nếu bán bậc vào bằng không thì đẩy tiếp vào hàng đợi
				q.push(v);
			}
		}
	}
	for(auto x: topo)cout<<x<<" ";	
}
void input(){
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		edge[i].push_back(j);
		in[j]++; // tăng bán bậc vào cho các đỉnh kề với đỉnh i
	}
}
int main() {
    freopen("input.txt","r",stdin);
    input();
    Kahn();
    return 0;
}