# Disjoint Set Union (DSU)

Cấu trúc dữ liệu này hỗ trợ hai thao tác đó là **tạo,tìm và gộp**. 

- Giúp gộp hai phần tử vào một tập hợp

- Giúp chỉ ra phần tử nào nằm trong tập hợp nào nhanh chóng

DSU có 3 thao tác chính:

- make_set () // Khởi tạo tập hợp từ các tập con đơn lẻ

- union (a,b) // Gộp hai tập hợp a và b

- find(a) // tìm ra đại diện( nguồn gốc ) của tập hợp mà a nằm trong.

## 1. Make Set

Giả sử ta có mảng `parent` và có n phần tử riêng lẻ.

Make set sẽ giúp các phần tử thứ `i` có `parent` là chính nó. 

Mã giả:

```cpp
make_set(){
    for(int i = 1; i <=n;i++){
       parent[i] = i;
       size[i] = 1;
    }
} 
```

## 2. Union

Đây là thao tác gộp từ tập hợp `a` và tập hợp `b`.

```cpp
void union(a,b){
    a = find(a);
    b = find(b);
    if( a!= b){
        parent[b] = a;// thao tác gộp
    }
//Trong trường hợp a = b thì không cần làm gì vì a và b đã cùng một tập hợp rồi
}
```

Giả sử ta có đồ thị sau:

<img title="" src="https://github.com/TruongNguyenDinh/GraphCpp/blob/main/DSU/graph%20(2).png" alt="Đồ thị ban đầu" data-align="center" width="415">

Khi gọi hàm `union(2,6)` thì ta sẽ có được:

- `find(2)=1`

- `find(6)=6`

Ta thấy `1 !=6` nên ta sẽ được `parent[6] = 1` <img title="" src="https://github.com/TruongNguyenDinh/GraphCpp/blob/main/DSU/graph%20(3).png?msec=1754634165514" alt="Đồ thị sau khi union" data-align="center" width="454">

Lưu ý là : nên chọn đại diện của tập hợp ( cây) có nhiều phần tử hơn làm đại diện của tập hơn gộp để tối ưu hơn. Như trường hợp trên `size(1) = 4 > size(6) = 3` nên chọn `cây 1` làm đại diện.

Mã nguồn tối ưu:

```cpp
union(a,b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
    }
}
```

## 3. Find

Giúp ta tìm ra đại diện của tập hợp 

Từ ví dụ trên ta có mã giả như sau:

```cpp
int find(int v){
    if(v == parrent[v]){
        return v;
    }
}
```

Trong trường hợp `v không đại diện cho chính nó` thì ta cần dùng đệ quy để tìm

```cpp
int find(int v){
    if(v == parent[v]) return v;
    return find(parent[v]);
}
```

Độ phức tạp : `O(n)` vì nó cần gọi lần lượt các đỉnh parent của nó để truy ra được đại diện.

Phương pháp tối ưu ( Paht compression : nén đường)

```cpp
int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
```

Phương pháp này sẽ giúp các node con có chung một đại diện thay vì phải lần lượt tìm kiếm đại diện thông qua các node mở rộng ra nó.

Cây gốc

<img title="" src="https://github.com/TruongNguyenDinh/GraphCpp/blob/main/DSU/graph.png" alt="Cây trước khi nén" data-align="center" width="357">

Cây sau khi nén đường bằng `find` 

<img title="" src="https://github.com/TruongNguyenDinh/GraphCpp/blob/main/DSU/graph (1).png?msec=1754634165514" alt="Cây sau khi nén" data-align="center" width="401">


