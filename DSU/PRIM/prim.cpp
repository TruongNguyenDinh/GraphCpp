//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
	edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

int n,m;
vector<pair<int,int>> adj[1001];
bool used[1001]; // mảng đã được dùng hay chưa ?
vector<edge> MST; // cây khung
void prim(int u){
	int d = 0 ; //chiều dài cây khung
	used[u] = true; // đưa u vào tập V_MST
	while(MST.size() < n-1){
		int min_w = INT_MAX;
		int x,y;
		for(int i = 1;i<=n;i++){
			if(used[i]){ // Nếu đỉnh [i] thuộc tậ V_mst
				for(auto j : adj[i]){
					int v = j.first;
					int w = j.second;
					if(!used[v] &&  w < min_w){
						min_w = w;
						x = i; y = v;
					}
				}
			}
		}
		MST.push_back({x,y,min_w});
		d += min_w;
		used[y] = true; // cho x vào V_MST
	}
	cout<<"Chiều dài cây khung là: "<<d<<endl;
	cout<<"Các cạnh: ";
	for(auto x : MST){
		printf("{u=%d,v=%d|w=%d} ",x.u,x.v,x.w);
	}
}

void input(){
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	memset(used,false,sizeof(used));
}
int main() {
    freopen("input.txt","r",stdin);
    input();
    prim(1);
    
    return 0;
}