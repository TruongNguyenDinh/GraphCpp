//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Đề bài: nhập n và m là số lượng đỉnh và cạnh của đồ thị.
các dòng tiếp theo nhập đỉnh đầu và đỉnh cuối ( tức là nhập danh sách cạnh )
Output: xuất ra ma trận kề của đồ thị
*/
int main() {
    freopen("input.txt","r",stdin);
    // Nhập n đỉnh và m cạnh
    int n,m;cin>>n>>m;
    int a[n][n];
    memset(a,0,sizeof(a)); // Cho tất cả các phần tử trong mảng A = 0

    while(m--){
    	int i,j;cin>>i>>j;
    	a[i-1][j-1] = 1;
    }
    cout<<"Đỉnh \t";
    for(int i = 0;i<n;i++) cout<<i+1<<" ";
    cout<<endl;
    //In ma trận kề
    for(int i = 0;i<n;i++){
        cout<<"\t"<<i+1<<"\t";
    	for(int j = 0;j<n;j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
/*
input
5 9
1 2
1 4
2 1
2 5
3 5
4 1
5 1
5 2
5 3
Bài 1 Ma trận kề cho đồ thị như sau:
output:
Đỉnh    1 2 3 4 5
    1   0 1 0 1 0
    2   1 0 0 0 1
    3   0 0 0 0 1
    4   1 0 0 0 0
    5   1 1 1 0 0
*/