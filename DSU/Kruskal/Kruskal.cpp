//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
 
struct denode{
	int u,v,w;// đỉnh đầu, đỉnh cuối và trọng số.
	denode(int _u,int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

int n,m;// Số đỉnh và số cạnh
int sz[1001];
int parent[1001];
vector<denode> edge;

void Make_set(){
	for(int i = 1;i<=n;i++){
		parent[i]= i;
		sz[i] = 1;
	}
}

int Find(int v){
	if(v == parent[v]) return v;
	return parent[v]  = Find(parent[v]);
}

bool Union(int a, int b){
	int u = Find(a);
	int v = Find(b);
	if( u!= v){
		if(sz[u] < sz[v]){
			swap(u,v);
		}
		parent[v] = u;
		return true;
	}
	return false;
}

void input(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int x,y,z; cin>>x>>y>>z;
		denode dn = denode(x,y,z);
		edge.push_back(dn);
	}
}
bool comparator(const denode &a, const denode &b){
	return a.w < b.w;
}
void Kruskal(){
	// Bước 1: Khởi tạo khung cây rỗng
	vector<denode> MST;
	// Tổng trọng số
	int dMST = 0;
	// Bước 2: sắp xếp theo trọng số 
	sort(edge.begin(),edge.end(), comparator);
	for(int i = 0;i<m;i++){
		if(MST.size() == n - 1) break;
		denode dn = edge[i];
		if(Union(dn.u,dn.v)){
			MST.push_back(dn);
			dMST += dn.w;
		}
	}
	cout<<"d(MST) :"<<dMST<<endl;
	for(auto x : MST){
		cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
	}
}

int main() {
    freopen("input.txt","r",stdin);
    input();
    Make_set();
    Kruskal();
    return 0;
}
/*
input
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8
*/