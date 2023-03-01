#include<stdio.h>
int d[4][2] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};
bool map[51][51], check[51][51];
int main()
{
	int n, m, x, y, dir, i, j, ans = 0;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&y,&x,&dir);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	int f, dirr;
	check[y][x] = 1; ans++;
	while(1){
		f = 0;
		for(i=1;i<=4;i++){
			dirr = (dir-i+4)%4;
			if(map[ y + d[dirr][0] ][ x + d[dirr][1] ] == 0 && check[ y + d[dirr][0] ][ x + d[dirr][1] ] == 0 ){
				dir = dirr;
				y += d[dir][0];
				x += d[dir][1];
				f = 1;
				check[y][x] = 1; ans++;
				break;
			}
		}
		if(f == 0){
			if(map[y - d[dir][0] ][x - d[dir][1] ] == 0){
				y -= d[dir][0];
				x -= d[dir][1];
			}
			else{
				printf("%d\n",ans);
				return 0;
			}
		}
	}
		
	return 0;
}
//(y + d[dirr][0]) >= 0 && (y + d[dirr][0]) < n && (x + d[dirr][1]) >= 0 && (x + d[dirr][1]) < m && 