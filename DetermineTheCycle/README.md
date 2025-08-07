# Determine the cycle

- Trong đồ thì G = (V,E) có chu trình khi và khi chỉ đồ thị G tồn tại cạnh ngược. Cạnh ngược là cạnh tạo ra vòng tròn khép kín cho đồ thị ở bất cứ nhánh nào.

- Trong ví dụ đồ thị gồm 4 đỉnh 1 2 3 4 thì ta có danh sách cạnh sau: {1,2}{1,4}{2,4}{2,3} thì ta thấy được tồn tại đường đi 1 -> 2 -> 4 -> 1. Có điểm đầu trùng với điểm cuối. Ta gọi đó là chu trình ( vòng lặp ).

## 1.Xác định chu trình trên đồ thị vô hướng bằng thuật toán DFS

#### Mã giả ( cho đồ thị liên thông ):

```cpp
bool DFS(int u,int par){
    visited[u] = true;
    for(v in range adj[u]){ // lặp các danh sách kề của u
       if(!visited[v]){
           if(DFS(v,u)) return true;         
        }
        else if (v != par) return true; // Tồn tại cạnh ngược (v,u)
    }
    return false;
}
```

Giải thích:

Vì đồ thị vô hướng có cạnh hai chiều nên adj[u] chứa **v** và adj[v] cũng chứ **u**.Vậy nên khi duyệt đỉnh **v** đã được **visited** và **v != parent[u]** thì đó là một cạnh ngược, chứng tỏ đồ thị đó có chu kì.Hay được hiểu như là một đỉnh đang xét mà mở rộng ra một đỉnh trước đó đã được thăm rồi mà đỉnh đó cũng không phải **Parent** của đỉnh đang xét thì đó là cạnh ngược. 

#### Mở rộng cho đồ thị vô hướng không liên thông

```cpp
// Hàm sử dụng cho đồ thị vô hướng liên thông hay không liên thông 
// -> hàm tổng quát cho bài
void ConnectedComponent(){
	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			if(DFS1(i)){
				cout<<"Exist the cycle \n";
				int u = start; int v = eNd;
				path.push_back(u);
				while(v != u){
					path.push_back(v);
					v = parent[v];
				}
				path.push_back(u);
				return;
			}
		}
	}
	cout<<"No exist the cycle! ";
}
```

#### Phiên bản cho một đối số

```cpp
int parent[1001]; // mảng lưu parent của đỉnh đang xét
bool DFS1(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			if(DFS1(v)) {
				return true;
			}
		}
		else if( v != parent[u]) {
			start = v;
			eNd = u;
			return true;
		}
	}
	return false;
}
```

## 2.Xác định chu trình cho đồ thị vô hướng bằng BFS

### Mã

```cpp
bool BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                parent[x] = v; // Lưu vết
            }
            else if (x != parent[x]){
                return true; //Có  tồn tạicạnh ngược
            }
        }
    }
    return false;
}
```

#### Mở rộng cho đồ thị vô hướng không liên thông

```cpp
void ConnectedComponent(){
	for(int i = 1;i<= n;i++){
		if(!visited[i]){
			if(BFS(i)){
				cout<<"Exist the cycle\n";
				return ;
			}
		}
	}
	cout<<"No exist the cycle !";
}
```

## 3.Xác định chu trình trên đồ thì có hướng bằng DFS

### Mã giả:

```cpp
bool DFS(int u){
    color[u] = 1; // Màu xám đánh dấu chưa thăm hết
    for(v in range adj[u]){
        if(color[v] == 0){ // Màu trắng đánh dấu chưa thăm
            parent[v] = u;
            if(DFS(v)) return true;
        }    
        else if(color[v] == 1) return true; // Tồn tại cạnh ngược (v,u)    
    }
    color[u] = 2; // màu đen đánh dấu đã thăm xong
    return false;
}
```

Giải thích: Việc sử dụng màu để phân biệt giữa 3 trạng thái trong đồ thị có hướng

- Đỉnh chưa được duyệt qua mang màu trắng ( color = 0 <span style:"color:white>Màu trắng </span>) 

- Đỉnh đang được thăm nhưng chưa xong tức là chưa đi hết các nhánh của đỉnh này ( color = 1 <span style="color:gray">Màu xám</span>)

- Đỉnh đã được thăm xong sẽ là màu đen (color = 2)

**Lí do** : Bởi vì một đỉnh đang mang màu xám tức là nó đang nằm trong stack ( ngăn xếp ) mà sau đó một đỉnh khác khi duyệt lại gặp lại đính màu xám, tức là nó gặp lại tổ tiên của mình thì sẽ được coi là chu trình.

## 4.Xác định chu trình trên đồ thị có hướng bằng thuật toán BFS ( Kahn's algo)

### Mã giả:

```cpp
bool BFS(int u){
    //Khởi tạo queue q
    queue<int> q;
    for(int i = 1;i<=n;i++){ // duyệt các đỉnh
        if(degree[i]==0){ // kiểm tra xem đỉnh nào có bán bậc vào bằng không
            q.push(i); // có thì đẩy vào queue
        }    
    }
    int cnt = 0;
    while(!q.empty()){
        int v = q.front();q.pop();
        ++cnt;
       for(auto x: adj[v]){
           degree[x]--; // giảm số bán bậc vào của các đỉnh kề với đỉnh v
           if(degree[x]==0){
               q.push(x); 
            }
        }
    }
    return cnt == n; 
}
```

Giải thích:

Sử dụng thuật toán Kahn trong BFS ( hay gọi là thuật toán nhấc đỉnh ) để xác định các đỉnh được tìm thấy . Biến **Cnt** được dùng để kiếm tra nếu **cnt**  bằng số đỉnh thì đồ thị không có chu kì còn ngược lại thì có, vì  thuật toán Kahn nó sẽ không đẩy được các đỉnh vào trong hàng đợi khi nó gặp chu trình.


