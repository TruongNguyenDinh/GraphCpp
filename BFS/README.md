# BFS : Breadth First Search

## Thuật toán:

- Thuật toán tìm kiếm theo chiều rộng BFS là thuật toán tìm kiếm ưu tiên theo chiều rộng,có thể hiểu như là nó sẽ tìm kiếm các đỉnh kề của đỉnh u rồi mới tìm kiếm tiếp các đỉnh kề của v.( có thể gọi là vết dầu loang )

## Mã giả:

```cpp
// Bước 1: Khởi tạo
queue = rỗng; // Khởi tạo một hàng đợi rỗng
push(queue,u); // Đẩy đỉnh u vào hàng đợi
visited[u] = true; // Đánh dấu là đã duyệt đỉnh u
// Bước 2 : Lặp khi hàng đợi vẫn còn phần tử
while(queue != queue.empty(){
    v = q.front(); // Lấy phần tử đầu tiền của hàng đợi
    q.pop(); // Xóa phần tử đó khỏi đầu hàng đợi
    <Thăm Đỉnh v>;
    for(auto x:adj[v]){ // Duyệt các đỉnh kề của v
        if(!visited[x]){ // Kiểm tra xem đỉnh x đã được duyệt chưa ?
            push(queue,x); // Đẩy đỉnh kề của v vào tiếp hàng đợi
            visited[x] = true;
        }
    }
}
```

Với đồ thị G = (V,E)

Độ phức tạp thuật toán:

- Biểu diễn thông qua ma trận kề : O(V * V)

- Biểu diễn thông qua danh sách cạnh: O(V * E)

- Biểu diễn thông qua danh sách kề : O(V + E)

Trong đó:

```bash
V : là số đỉnh của đồ thị
E : là số cạnh của đồ thị
```
