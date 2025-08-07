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
    color[u] = 1;
    for(v in range adj[u]){
        if(color[v] == 0){
            parent[v] = u;
            if(DFS(v)) return true;
        }
        else if(color[v] == 1) return true; // Tồn tại cạnh ngược (v,u)    
    }
    color[u] = 2;
    return false;
}
```
