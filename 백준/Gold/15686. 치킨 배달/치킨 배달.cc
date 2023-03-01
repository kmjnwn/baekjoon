#include<stdio.h>
int chi[101][2], house[101][2], selected[101]; // 0 : y, 1 : x 
int n, m, hos, chs, min = 2100000000;

int cal_dist()
{
	int i, j, minn, rdis=0;
	for(i=1;i<=hos;i++){
		minn = 100000000;
		for(j=1;j<=m;j++){
			int dist = 0;
			for(int k = 0; k<=1; k++){
				if(house[i][k] > chi[selected[j]][k]){
					dist += house[i][k] - chi[selected[j]][k];
				}
				else{
					dist += chi[selected[j]][k] - house[i][k];
				}
			}
			if(minn > dist) minn = dist;
		}
		rdis += minn;
	}
	
	return rdis;
}
void ans(int c, int last)
{
	int i;
	
	if(c != m){
		for(i=last+1;i<=chs;i++){
			selected[c+1] = i;
			ans(c+1, i);
		}
	}
	else{
		int data = cal_dist();
		if( min > data) min = data;
	}
}
int main()
{
	int i, j, a;
	
	scanf("%d %d",&n, &m);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a);
			if(a == 1){
				house[++hos][0] = i;
				house[hos][1] = j;
			}
			else if(a == 2){
				chi[++chs][0] = i;
				chi[chs][1] = j;
			}
		}
	}
	ans(0, 0);
	printf("%d\n",min);
	
	return 0;
}