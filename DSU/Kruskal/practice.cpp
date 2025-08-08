//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
// Tạo cạnh gồm đỉnh và trọng số
struct denode{
	int u,v,w; // Đỉnh đầu, đỉnh cuối và trọng số
	denode(int _u,int _v,int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

int n,m; // đỉnh, cạnh
int parent[1001];// nguồn gốc
int siz[1001]; // kích thước cây
vector<denode> edge; // lưu cạnh

// Dejoint set union
//Tạo các đỉnh nhỏ lẻ mang thông tin cha và kích thước ( Khởi nguyên )
void Make_set(){
	for(int i = 1;i<=n;i++){
		parent[i] = i; 
		siz[i] = 1;
	}
}
int Find(int v){ // Trả về tổ tiên của một node
	if(v == parent[v]) return v;
	return parent[v] = Find(parent[v]); // Vạn vật quy về một mối ( đều có parent là tổ tiên )
}
bool Union(int a, int b){
	int u = Find(a); // tìm tổ tiên đỉnh a
	int v = Find(b); // tìm tổ tiên đỉnh b
	if( u!=v){
		if(siz[u]<siz[v]) swap(u,v); // Lấy cây có số node nhiều nhất làm tổ tiên
		parent[v] = u; // kết hợp node/cây
		siz[u] += siz[v]; // Tăng kích thước cây
		return true; 
	}
	return false; // Nếu không hợp đươc thì trả về false
}
void input(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int u,v,w; cin>>u>>v>>w;
		denode dn = denode(u,v,w); 
		edge.push_back(dn); // Thêm cạnh vào vector
	}
}
bool comparator(const denode &a, const denode &b){
	return a.w < b.w; // điều kiện so sánh là trọng số
}
//Kruskal
void Kruskal(){
	//Bước 1 khởi tạo khung cây rỗng
	vector<denode> MST;
	int dMST = 0;
	// Bước 2 sắp xếp theo độ dài tăng dần
	sort(edge.begin(),edge.end(),comparator);
	// Bước 3 Lặp 
	for(int i = 0;i<m;i++){
		if(MST.size() == n - 1) break; // nếu số cạnh bằng số đỉnh - 1 thì dừng
		denode e = edge[i];
		if(Union(e.u,e.v)){
			MST.push_back(e);
			dMST+= e.w;
		}
	}
	cout<<dMST;
}
int main() {
    freopen("input.txt","r",stdin);
    input();
    Make_set();
    Kruskal();
    return 0;
}