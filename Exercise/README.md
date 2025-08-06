# Bài tập

## Bài 1: Đếm số thành phần liên thông trên đồ thị vô hướng

### Thuật toán:

- Sử dụng BFS hoặc DFS

### Mã giả:

```cpp
ConnectedComponent{
    //Khởi tạo số thành phần liên thông ban đầu của đồ thị là 0
    int cnt = 0;
    //Chạy vòng lặp
    for(i in range(1,n+1){ // duyệt i từ 1 cho tới n
        if(!visited[i]){
            cnt++; // tăng số thành phần liên thông
            dfs(i) || bsf(i); // Duyệt tiếp
        } 
    }
    return cnt;  
}
```

Giải thích: 

- Một đồ thị vô hướng liên thông tức là từ đỉnh u đến đỉnh v bất kì đều sẽ có đường đi vậy nên nếu đồ thị không liên thông thì sẽ có một số đỉnh chưa được gọi trong thuật toán BFS hoặc DFS. Chính vì vậy nên số thành phần liên thông bằng số lần gọi thuật toán BFS hoặc DFS cho đồ thị vô hướng. Đơn giản hơn có thể hiểu đồ thị không liên thông thì một số đỉnh sẽ không được thăm ( visited = false) nên khi đó còn đỉnh nào thì gọi lại hết.

## Bài 2: Tìm đường đi giữa hai đỉnh trên đồ thị ( có hướng và vô hướng )

### Thuật toán:

- Sử dụng thuật toán DFS và BFS.

- Sử dụng thêm một mảng để truy vết đường đi ( trace ) 

### Mã giả:

```cpp
// Đối với DFS
DFS{
    //Đánh dấu đã ghé qua đỉnh u
    visited[u] = true;
    // Lặp các đỉnh kề của u
    for each v in edge[u]{
        //Kiểm tra đã ghé qua chưa ?
        if(!visited[v]){
            // Để lại dấu vết là vết của v là u hay ( parent của v là u)
            trace[v] = u;
            DFS(v);
        }
    }
}
// Đối với BFS
BFS{
    //Thêm đỉnh u vào hàng đợi
    push(queue,u);
    // Đánh dấu đã ghé qua
    visited[u]= true;
    while(!q.empty(){
        // Lấy phần tử đầu hàng đợi ra
        v = q.front();
        for each x in edge[v]{ // duyệt các đỉnh kề của đỉnh v
            if(!visited[x]){ // Kiểm tra đỉnh đã được duyệt hay chưa
                trace[x] = v; // Lưu vết lại cho biết viết của x là v
                push(queue,x);
                visited[x] = true;
            }    
        }
    }
}
// Đưa ra đường đi
Path{
    // Gọi thuật toán BFS hoặc DFS để tạo đường và truy vết
    BFS || DFS
    // Kiểm tra xem điểm cần tới có đường đi không ?
    if(!visited[goal]){ // Nếu mục tiêu chưa được đi qua khi đã chạy BFS || DFS
        // in ra không có đường đi 
    }
    else{
        //Tạo vector path
        vetor path
        // Lặp cho đến khi điểm cuối trùng với điểm đầu
        while(start != goal){
            path.push_back(goal); // thêm vào đường đi
            goal = trace[goal]; // Truy vết được lại
        }
        // Đẩy điểm đầu vào path
        path.push_back(start);
        //Đảo lại đường
        reverse(path.begin(),path.end());
    }
}
```

Giải thích:

Cho đầu vào:

10 9 1 7  // đỉnh - cạnh - start - goal

1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
10 0

Ví dụ sau khi dùng DFS ta có được các đỉnh duyệt theo thứ tự sau:

 1 -> 2 -> 3 -> 6 -> 7 -> 4 ( đang chỉ tính thành phần liên thông thứ nhất )

Từ đó ta sẽ được bảng bên dưới

| Vertex | 1   | 2   | 3   | 4   | 6   | 7 (goal) |
| ------ | --- | --- | --- | --- | --- | -------- |
| Trace  | 0   | 1   | 2   | 2   | 3   | 6        |

Từ đó ta sẽ dịch lại được dòng sau:

```bash
 while(start != goal){
    path.push_back(goal); // thêm vào đường đi
    goal = trace[goal]; // Truy vết được lại
}
```

Đoạn mã hoạt động với cả hai đồ thị, tuy nhiên khi dùng đồ thị có hướng thì nên cẩn trọng xử lý danh sách kề.
