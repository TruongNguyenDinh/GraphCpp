# DFS : Depth First Search

## Thuật toán

- Ưu tiên duyệt xuống dưới nhất có thể trước khi quay lại, tức là sẽ duyệt xuống sâu nhất của một nhánh trước khi quay lại chuyển sang nhánh khác của cây

## Mã giả

```cpp
DFS(u){
    <Tham Dinh u >;
    visited[u] = true;
    //Duyệt các đỉnh kề với đỉnh u
    for(v : adj[u]) { // Nếu v chưa được thăm
        if (!visited[v]) DFS(v);
    }
}
```

*Độ phức tạp của thuật toán DFS phụ thuộc vào các biểu diễn ma trận:*

- Biểu diễn thông qua ma trận kề : O(V * V)

- Biểu diễn thông qua danh sách cạnh: O(V * E)

- Biểu diễn thông qua danh sách kề : O(V + E)

Tại đồ thị G = (V,E) với:

```bash
V: là số lượng đỉnh. 
E là số lượng cạnh.
```


