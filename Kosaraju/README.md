# Kosaraju

Bài toán thành phần liên thông mạnh của đồ thị có hướng

Liên thông mạnh là giữa hai đỉnh (u,v) bất kì sẽ luôn có đường đi.

Các bước:

- Bước 1: DFS trên G sau đó lưu vào stack

- Bước 2: Xây dựng TG (Transpose Graph)

- Bước 3: pop các trình trong stack của bước 1 và gọi DFS trên TG

Giải thích:

- DFS trên G : Để tính thứ tự kết thúc. Điều này giúp ta biết được đỉnh nào duyệt trước

- Tạo Transpose G : Đảo hướng các cạnh để ngăn đi ngược giữa các SCC (Strong Connected Component )

- DFS trên Transpose G theo thứ tự giảm dần : Tách riêng từng SCC một cách chính xác

### Mã tham khảo:

```cpp
// chuyển danh sách cạnh cho đồ thị G sang đồ thị transpose G
tg[j].push_back(i); //  danh sách kề cho đồ thị TG
// DFS cho đồ thị G
void DFS(int u){ // DFS duyệt đồ thị G = (V,E)
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
	st.push(u); // Tại các phần tử không mở rộng được nữa sẽ được đẩy vào 


stack
}
```

```cpp
void DFS_TG(int u){ // duyệt đồ thị Transpose của G với BFS cơ bản
	visited[u] = true;
	for(int v : tg[u]){
		if(!visited[v]){
			DFS_TG(v);
		}
	}
}
```

```cpp
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
			DFS_TG(u);
			cnt++;
		}
	}
	return cnt;
}
```


