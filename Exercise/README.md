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
