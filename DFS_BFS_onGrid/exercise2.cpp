//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m,x_1,y_1,x_2,y_2; // Số hàng, số cột ma trận, điểm bắt đầu và điểm kết thúc trên tọa độ Oxy

bool visited[1001][1001];
char a[1001][1001];
pair<int,int> trace[1001][1001];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void BFS(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j]= 'o';
	while(!q.empty()){
		pair<int,int> top = q.front();q.pop();
		for(int k=0;k<4;k++){
			int i1 = top.first+dx[k];
			int j1 = top.second+dy[k];
			if(i1 >= 1 && i1 <=n && j1 >=1 && j1 <= m && a[i1][j1] !='x' && !visited[i1][j1]){
					trace[i1][j1] = {top.first,top.second};
					visited[i1][j1] = true;
					if(a[i1][j1]=='B') return;
					q.push({i1,j1});
					a[i1][j1] = 'o';
			}
		}
	}
}
void Path(){
	BFS(x_1,y_1);
    if (!visited[x_2][y_2]){
    	cout << "không có đường đi";
    }
	else{
		vector<pair<int,int>> path;
		int u = x_2, v = y_2;
		while(u != x_1 || v != y_1){
			path.push_back({u,v});
			tie(u,v) = trace[u][v];
		}
		path.push_back({x_1,y_1});
		reverse(path.begin(),path.end());
		cout<<"Số bước đi là "<<path.size()-1<<endl;
		for(auto it:path){
			printf("{%d,%d}",it.first,it.second);
			if(it==*path.rbegin()){
				continue;
			}
			cout<<" -> ";
		}
	}
}
void input(){
	memset(trace,0,sizeof(trace));
	memset(visited,false,sizeof(visited));
	cin >>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j] == 'A'){
				x_1 = i;y_1 = j;
			}
			else if(a[i][j] == 'B'){
				x_2 = i,y_2 = j;
			}
		}
	}
}
int main() {
    freopen("input.txt","r",stdin);
    input();
   	Path();
    return 0;
}