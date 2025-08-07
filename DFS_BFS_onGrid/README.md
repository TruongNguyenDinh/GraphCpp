# DFS | BFS on grid

### Bài toán 1: Đếm số thành phần liên thông trên lưới

### Bài toán 2: Kiểm tra đường đi giữa hai điểm trên lưới

### Bài toán 3: Tìm số bước tối thiếu giữa hai ô trên lưới

| C   | 1   | 2   | 3   | 4   | 5   | 6   |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1   | x   | x   | x   | o   | o   | o   |
| 2   | o   | o   | x   | o   | o   | o   |
| 3   | o   | x   | x   | x   | x   | o   |
| 4   | o   | o   | o   | o   | o   | x   |
| 5   | x   | x   | o   | x   | o   | x   |
| 6   | x   | o   | x   | x   | o   | x   |

### Cách làm bài 1:

$$
\begin{bmatrix}
i-1,j-1 & i-1,j & i-1,j+1 \\
i,j-1 & i,j & i,j+1 \\
i+1,j-1 & i+1,j & i+1,j+1
\end{bmatrix}
$$

Với i là hàng, j là cột

Từ trên ta có thể duyệt được các ô cần xét, ở đây ta muốn duyệt các ô chung cạnh thì chúng ta sẽ chỉ lấy phần chữ thập lấy ô i,j làm tâm +.

Từ đó ta có được.

Độ di chuyển theo i : dx = {-1,0,0,1}

Độ di chuyển theo j : dy = {0,-1,1,0}

#### Mã giả:

```cpp
//Với tìm kiếm theo chiều sâu
DFS(i,j){
    //Đánh dấu đã ghé qua
    visited[i][j] = true;
    //Duyệt đường đi 4 phía
    for(k in range(0,4){
        i1 = i + dx[k];
        j1 = j + dy[k];
        //Đặt điều kiện sao cho không đi vượt lưới
        if( 1<= i1 <=n && 1 <= j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1){
            DFS(i1,j1);
        }
    }
}
// Với tìm kiếm theo chiều rộng
BFS(i,j){
    queue<pair<int,int>> q;
    q.push({i,j});
    //Đánh dấu đã ghé thăm
    visited[i][j] = true;
    while(!q.empty()){
        pair top = q.front();q.pop();
        for(k in range(0,4){
            i1 = top.first + dx[k];
            j1 = top.second + dy[k];
            //Kiểm tra điều kiện, thêm vào queue
            if(1 <= i1 <= n && 1 <= j1 <= m && a[i1][j1] =='x' && !visited[i1][j1]){
                q.push({i1,j1});
                visited[i1][j1] = true;
            }
        }
    }
}
ConnectedComponent(){
    count = 0;
    for(i in range(1,n+1){
        for (i in range(1,m+1){
            if(a[i][j]=='x' and !visited[i][j]){
               count ++;
                BFS(i,j) | DFS(i,j);
            }
        }
    }
}
```

### Cách làm bài toán 2 + bài 3:

|     | 1     | 2   | 3   | 4   | 5   | 6   |
|:---:|:-----:|:---:|:---:|:---:|:---:|:---:|
| 1   | Start | o   | o   | x   | o   | o   |
| 2   | o     | x   | o   | o   | o   | o   |
| 3   | o     | x   | o   | o   | o   | o   |
| 4   | o     | o   | o   | o   | x   | x   |
| 5   | Goal  | o   | o   | o   | x   | o   |
| 6   | o     | o   | o   | x   | x   | x   |

- Nguyên tắc :
  
  - o là đường đi
  
  - x là vật cản
  
  - Điểm bắt đầu là được cho
  
  - Điểm mục tiêu là được cho

Sử dụng thuật toán BFS:

- Bài 2 đơn giản là dùng thuật toán DFS hoặc BFS chạy rồi kiếm tra visited tại vị trí goal xem có được ghé qua chưa ? nếu chưa thì là không có đường đi,còn có thì là đã tồn tại đường đi

- Bài 3 tìm đường đi ngắn nhất thì sử dụng BFS để làm, thêm một trace để truy vết lại cha của tọa độ i j đang xét. mã giả bài 3 bên dưới

#### Mã giả:

```cpp
BFS(i,j){
    //Khởi tạo queue q
    q.push({i,j}); // thêm phần tử đầu tiên 
    //lặp cho đến khi queue rỗng
    while(!q.empty()){
        pair top = q.front(); // lấy phần tử đầu tiên ra khỏi queue
        q.pop(); // Xóa nó đi
        for (i in range(0,5)){ // lặp từ 0 đến 4 để tìm đường đi
            i1 = top.first + dx[k];
            j1 = top.second + dy[k];// tìm bốn hướng xuất phát từ i và j
            if(1 <= i1 <= n && 1 <= j1 <= m && a[i1][j1] != 'x' && !visited[i1][j1]){
                trace[i1][j1] = {top.first,top.second} ;// lưu vết 
                visited[i1][j1] = true; //  đánh dấu đã ghé qua
                if(a[i1][j1]== 'B') return ; //Dừng nếu đến đích
                q.push({i1,j1});
            }
        }
    }
}
Path{ // in đường đi và số bước ngắn nhất 
    BFS(start_x,start_y);
    if(!visited[goal_x][goal_y]) cout >>"No Path";
    else{
        //tạo vector lưu đường đi, vì đường đi gồm x và y nên dùng pair
        vector<pair<int,int>> path;
        //Tạo biến tạm thời lưu đường đi
        int u = goal_x; int v = goal_y;
        while(u != start_y || v != start_y){
            path.push_back({u,v});//Thêm vào đường đi
            tie(u,v) = trace[u][v;]
        } 
        path.push_back({start_x,start_y});// thêm điểm xuất phát vào đường đi
        reverse(path.begin(),path.end());
        for each it in path{
            //in ra tạo độ điểm x và y
            cout<< it.first << it.second;
            if(it == *path.rbegin() continue; // nếu là phần tử cuối thì bỏ ->
            cout<<" -> ";
        }
        
    }
}
```
