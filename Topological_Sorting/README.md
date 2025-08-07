# Topological Sorting

( sắp xếp topo dành cho đồ thị có hướng )

## Lý thuyết:

- Trong đồ thị G = (V,E), nếu có đường đi từ u với v thì khi sắp xếp topo sẽ cho ra kết quả là u phải đứng trước v. Tức là cái nào đứng trước thì sẽ phải thực hiện trước. 

**Lưu ý**: không thể dùng cho đồ thị có chu trình (đồ thị  tạo thành vòng kín)

## Thuật toán

- Sử dụng thuật toán BFS hoặc DFS

#### DFS

- Sử dụng stack 

- Duyệt cho đến khi một đỉnh nào nó không còn đường đi nữa thì đẩy khỏi stack và thêm vào topo 

```cpp
void DFS(int u){
	visited[u] = true;
	for(int v : edge[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
	topo.push_back(u); // chỉ cần hàm này
}
int main() {
	memset(visited,false,sizeof(visited));
    input();
    for(int i = 1;i<= n;i++){
    	if(!visited[i]){
    		DFS(i);
    	}
    }
    reverse(topo.begin(),topo.end());
    for(auto x: topo) cout<<x<<" ";
    return 0;
}
```

#### BFS ( thuật toán Kahn - xóa dần đỉnh)

- Phải tính được bán bậc vào của các đỉnh

- Đỉnh nào có bán bậc vào bằng không thì cho vào hàng đợi và xóa đỉnh đó khỏi đồ thị. Các đỉnh kề của đỉnh nó sẽ có bán bậc vào giảm đi một

- Lặp lại cho đến khi hàng đợi không còn phần tử nào thì chương trình kết thúc

```cpp

void input(){
	cin>>n>>m;
	while(m--){
		int i,j;cin>>i>>j;
		edge[i].push_back(j);
		in[j]++; // Tăng bán bậc vào cho đỉnh kề với đỉnh i
	}
}Kain(){
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();// rút đỉnh u ra khỏi hàng đợi
        topo.push_back(u); // thêm vào topo vì đỉnh này đã có in-degree = 0
        for(int v : edge[u]){
            in[v]--; // Giảm các bán bậc vào của các đỉnh kề với u
            if(in[v]==0){ // nếu bán bậc bào bằng 0 thì lại đẩy vào hàng đợi
                q.push(v); 
            }
        }        
    }
}
```


