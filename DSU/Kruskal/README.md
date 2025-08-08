# Kruskal

Thuật toán `Kruskal` tìm cây khung cực tiểu

## 1. Khái niệm

Cây khung :

- kết nối các node ( đỉnh ) trong đồ thị ( mọi đỉnh đều có đường đi đến nhau)

- Không chứa chu trình ( không có vòng)

- Bao gồm đúng `n-1 cạnh` nếu đồ thị nó có `n đỉnh`

`MST: Minimum spanning tree` : cây  khung cực tiểu

## 2. Thuật toán

### Mã giả:

```bash
Kruskal(){
    // Bước 1: khởi tạo một cây khung rỗng
    MST = Rỗng; 
    d(MST) = 0; //Trọng số bằng 0
    // Bước 2 : sắp xếp các cạnh theo độ dài tăng dần
    // Bươc 3 : Lặp
    while(|MST| < n-1 && E != empty()){
        e = <cạnh ngắn nhất thuộc E>;
        E = E \ {e};
        if(MST U (e) không tạo thành chu trình){
            MST = MST U e;
            d(MST)+= d(e);
        }
    }
}
```

Có đồ thị như sau:

<img title="" src="https://github.com/TruongNguyenDinh/GraphCpp/blob/main/DSU/Kruskal/graph%20(4).png" alt="Đồ thị" data-align="center" width="365">

Đầu tiên sort các cạnh có độ dài tăng dần:

- (2,3): 1

- (3,5): 2

- (2,5): 3

- (4,5): 3

- (1,3): 4

- (2,4): 5

- (5,6): 8

- (4,6): 10

- (1,2): 12

```cpp
struct edge{
    int u,v,w;
}
```

`MST = Rong` `d(MST) = 0` 

| Loop No.  | Edge  | Weight | Cycle | Parent      | MST      | d(MST) |
| --------- | ----- | ------ | -----:| ----------- | -------- | ------ |
| Loop(1)   | (2,3) | 1      | No    | 3 \| 3 -> 2 | 1        | 1      |
| Loop(2)   | (3,5) | 2      | No    | 5 \| 5 -> 2 | 2        | 3      |
| Loop(3)   | (2,5) | 3      | Yes   | ~~~~        | 2        | 3      |
| Loop(4)   | (4,5) | 3      | No    | 4 \| 4 -> 2 | 3        | 6      |
| Loop(5)   | (1,3) | 4      | No    | 1 \| 1 -> 2 | 4        | 10     |
| Loop(6)   | (2,4) | 5      | Yes   | ~~~~        | 4        | 10     |
| Loop(7)   | (5,6) | 8      | No    | 6 \| 6 -> 2 | 5 = n -1 | 18     |
| Don't Run | (4,6) | 10     |       |             | stop     |        |
| Don't Run | (1,2) | 12     |       |             |          |        |

Trong đó `1 | 1 -> 2 tức là 1 có parent là 1 chuyển sang thành 2`
