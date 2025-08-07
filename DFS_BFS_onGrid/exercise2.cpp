//Author: Nguyễn Đình Trường
#include <bits/stdc++.h>
using namespace std;

int n,m,x_1,y_1,x_2,y_2; // Số hàng, số cột ma trận, điểm bắt đầu và điểm kết thúc trên tọa độ Oxy

bool visited[1001][1001];
char a[1001][1001];
pair<int,int> trace[1001][1001];
// Bốn hướng lần lượt của tọa độ i j
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void BFS(int i,int j){
	// tạo queue để chạy
	queue<pair<int,int>> q;
	// đẩy phần tử đầu tiên
	q.push({i,j});
	// lặp cho đến khi queue rỗng
	while(!q.empty()){
		// lấy phần tử đầu tiên ra lưu vào top và xóa phần tử đầu tiên đó đi
		pair<int,int> top = q.front();q.pop();
		// duyệt 4 hướng 
		for(int k=0;k<4;k++){
			int i1 = top.first+dx[k];
			int j1 = top.second+dy[k];
			// điều kiện kiểm tra xem tọa độ có vượt ngoài lưới hay không và check visited và đường đi
			if(i1 >= 1 && i1 <=n && j1 >=1 && j1 <= m && a[i1][j1] !='x' && !visited[i1][j1]){
					// lưu vết cha cho tọa độ hiện tại
					trace[i1][j1] = {top.first,top.second};
					visited[i1][j1] = true;
					if(a[i1][j1]=='B') return; // dừng cho đến khi thấy được B
					q.push({i1,j1});
					// a[i1][j1] = 'o';
			}
		}
	}
}
void Path(){
	// Khởi chạy để tạo đường đi
	BFS(x_1,y_1);
	// Kiểm tra có đường đi hay không ?
    if (!visited[x_2][y_2]){
    	cout << "không có đường đi";
    }
	else{
		// Tạo vector lưu đường
		vector<pair<int,int>> path;
		// sử dụng hai biến tạm thời để lấy vết ( đường )
		int u = x_2, v = y_2;
		while(u != x_1 || v != y_1){ // lặp liên tục khi mà u != start_x hoặc v khác start_y
			// đẩy đường đi vào path
			path.push_back({u,v});
			// lấy lại cha của u và v thông qua trace
			tie(u,v) = trace[u][v];
		}
		// đẩy phần tử start vào path
		path.push_back({x_1,y_1});
		// đảo ngược path
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