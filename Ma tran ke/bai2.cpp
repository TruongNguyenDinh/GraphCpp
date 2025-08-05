//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Đề bài: cho ma trận kề
output: in ra danh sách cạnh tương ứng.
*/
int main() {
    freopen("input.txt","r",stdin);
    int n;cin>>n ;// nhập số lượng đỉnh
    for(int i = 1;i<=n;i++){
    	for(int j = 1;j<=n;j++){
    		int x;cin>>x;
    		if (x == 1) cout<<i<<" "<<j<<endl;
    	}
    }
    return 0;
}