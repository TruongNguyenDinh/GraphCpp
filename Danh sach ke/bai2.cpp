//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;
/*
Cho ma trận kề nhiệm vụ in ra danh sách kề
*/
int main() {
    freopen("input.txt","r",stdin);
    int n;cin>>n;
    vector<pair<int,int>> edge;
    int a[100][100];
    //cách 1
    cout<<"Cách 1 \n";
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            //cách 1
            int x;cin>>x;
            if(x == 1){
                cout<<"{"<<i<<" "<<j<<"}"<<endl;
            }
            //cách 2
            a[i][j] = x;
        }
    }
    //Cách 2
    for(int i =1 ;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(a[i][j]==1 && i<j){
                edge.push_back({i,j});
            }
        }
    }
    cout<<"Cách 2 \n";
    for(auto x:edge) printf("{%d,%d}\n",x.first,x.second);
    return 0;
}
