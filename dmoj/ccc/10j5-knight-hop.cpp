#include <cstdio>
#include <utility>
using namespace std;
int v[8] = { -1, 2, 1, 2, -1, -2, 1, -2 };
bool vis[9][9];
pair<int, int> q[64];
int pre[9][9][2];
int main()
{
	int x1, y1, x2, y2, upx1=0, upx2=0, upy1=0, upy2=0;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int f = 0, b = 0, curr_x, curr_y;
	q[++b] = make_pair(x1, y1);
	vis[x1][y1] = 1;
	while (f != b) {
		curr_x = q[++f].first;
		curr_y = q[f].second;
		for (int i = 0; i < 7; i += 2) {
			upx1 = curr_x + v[i], upx2 = curr_x + v[i + 1], upy1 = curr_y + v[i + 1], upy2 = curr_y + v[i];
			if (upx1 <= 8 && upy1 <= 8 && upx1 >= 1 && upy1 >= 1 &&
				!vis[upx1][upy1]) {
				q[++b] = make_pair(upx1, upy1);
				vis[upx1][upy1] = 1;
				pre[upx1][upy1][0] = curr_x;
				pre[upx1][upy1][1] = curr_y;
			}
			if (upx2 <= 8 && upy2 <= 8 && upx2 >= 1 && upy2 >= 1 &&
				!vis[upx2][upy2]) {
				q[++b] = make_pair(upx2, upy2);
				vis[upx2][upy2] = 1;
				pre[upx2][upy2][0] = curr_x;
				pre[upx2][upy2][1] = curr_y;
			}
			if (vis[x2][y2])
				break;
		}
	}
	int count = 0, temp=0;
	while (x2 != x1 || y2 != y1) {
		temp = x2;
		x2 = pre[x2][y2][0];
		y2 = pre[temp][y2][1];
		count++;
	}
	printf("%d\n", count);
	return 0;
}