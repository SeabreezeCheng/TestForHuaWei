#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

//////////////////////////////全排队问题///////////////////////////
//int out[101] = { 0 }, check[101] = {0}, n;
//void print()
//{
//	int i;
//	for (i = 1; i <= n; i++)
//	{
//		cout << out[i] << ' ';
//	}
//	cout << endl;
//}
//inline void dfs(int i)
//{
//	int j;
//	if (i == n + 1)
//	{
//		print();
//		return;
//	}
//	for (j = 1; j <= n; j++)
//	{
//		if (check[j] == 0)
//		{
//			out[i] = j;
//			check[j] = 1;
//			dfs(i + 1);
//			check[j] = 0;
//		}
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin >> n;
//	dfs(1);
//	return 0;
//}




///////////////////////////迷宫问题/////////////////////////////////
//bool across[101][101] = { 0 };
//char map[101][101];   //存放迷宫 
//int flag = 0;     //如果能走出去就标记为1，反之为0
//
////下，左，上，右
//int xx[4] = { 0,-1,0,1 }, yy[4] = { -1,0,1,0 };
//int n, kx, ky;   //n是迷宫的边长，kx是x进行加减之后的值，同理ky。 
//void dfs(int x, int y) {
//	for (int i = 0; i <= 3; i++) {
//		kx = x + xx[i];
//		ky = y + yy[i];
//		//判断向周围走一步是否会遇到墙且在边界内且没有回溯
//		if ((map[kx][ky] == '.' || map[kx][ky] == 'e') && kx >= 0 && ky >= 0 && kx < n && ky < n && across[kx][ky] == 0) 
//		{
//			//能走就标记走过
//			across[kx][ky] = 1;
//			if (map[kx][ky] == 'e') {
//				flag = 1;
//			}
//			else {
//				dfs(kx, ky);
//			}
//		}
//	}
//}
//
//int main() {
//	int k = 1, sum;
//	cin >> sum;
//	while (k <= sum) {
//		memset(across, 0, sizeof(across)); //将标记数组a全部记为 0，表示这个点未走过 
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) 
//				cin >> map[i][j];
//		}
//		//判断起始位置进行开始DFS
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (map[i][j] == 's')
//					dfs(i, j);
//			}
//
//		}
//		if (flag == 1) {
//			cout << "YES" << endl;
//		}
//		else {
//			cout << "NO" << endl;
//		}
//		k++;
//	}
//	return 0;
//}

/////////////////////////////////迷宫最短路径问题///////////////////////////////////

char mapp[1030][1030];
int n, sx, sy, ex, ey; //sx，sy为起始位置，ex，ey为终点位置 

struct node {
	int x, y, step;  // 用结构体记录每个点的最短步数（用于递推） 
};

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };//控制移动的数组 

int bfs() {
	queue<node> q;
	node z;
	z.step = 0;//状态初始化，z即为第一个拓展点 
	z.x = sx;
	z.y = sy;
	mapp[sx][sy] = '1';//标记 
	q.push(z);
	while (!q.empty())
	{
		z = q.front();
		for (int i = 0; i < 4; ++i)//拓展过程，往四个方向拓展 
		{
			int xx = z.x + dx[i];
			int yy = z.y + dy[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && mapp[xx][yy] == '0')//拓展点处理 
			{
				node d;
				d.step = z.step + 1;
				d.x = xx;
				d.y = yy;
				q.push(d);
				mapp[xx][yy] = '1';
				if (xx == ex && yy == ey) return d.step;
			}
		}
		q.pop();
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mapp[i][j];
	cin >> sx >> sy >> ex >> ey;
	cout << bfs();
	return 0;
}