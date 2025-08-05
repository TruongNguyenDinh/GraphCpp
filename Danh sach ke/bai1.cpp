//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Đề bài: cho danh sách cạnh 
từ danh sách cạnh tạo ra danh sách kề
*/
int main() {
    freopen("input.txt","r",stdin);
    int n,m;cin>>n>>m; // nhập n đỉnh và m cạnh
    vector<vector<int>> adj(n); // vector lưu danh sách kề
    while(m--){
    	int i,j;cin>>i>>j;
    	adj[i-1].push_back(j-1);
    	adj[j-1].push_back(i-1);
    }
    for(int i = 0;i<n;i++){
    	cout<<"Đỉnh "<<i+1<<" kề với: ";
    	for(int j = 0;j<adj[i].size();j++){
    		cout<<adj[i][j]+1<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
/*
5 9
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
*/