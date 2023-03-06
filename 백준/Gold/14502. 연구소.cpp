#include<iostream>
#include <queue>
using namespace std;

int map[9][9], map2[9][9];

int n, m, ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(int i,int j){
    
    queue <pair<int, int>> q;
    q.push({i,j});

    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int tx = x+dx[i];
            int ty = y+dy[i];

            if(tx<=n && ty<=m && tx>0 && ty>0){
                if(map2[tx][ty] == 0){
                    q.push({tx,ty});
                    map2[tx][ty] = 2;
                }
            }
        }
    }
}

int main()
{
    int i,j, x,y, vp=0;
    int virus[100][2];

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
            map2[i][j] = map[i][j];
            if(map[i][j] == 2){
                virus[vp][0] = i;
                virus[vp][1] = j;
                vp++;
            }
        }
    }

    for(int i=0;i<n*m;i++){
		int x1=i/m+1;
        int y1=i%m+1;
		if(!map2[x1][y1]){
		for(int j=i+1;j<n*m;j++){
			int x2=j/m+1;
            int y2=j%m+1;
			if(!map2[x2][y2]){
			for(int k=j+1;k<n*m;k++){
				int x3=k/m+1;
                int y3=k%m+1;
				if(!map2[x3][y3]){
					map2[x1][y1] = 1;
					map2[x2][y2] = 1;
					map2[x3][y3] = 1;
					
					for(int p=0;p<vp;p++)
						BFS(virus[p][0],virus[p][1]);
					
					int cnt = 0;
					
					for(int p=1;p<=n;p++)
						for(int q=1;q<=m;q++)
							if(map2[p][q] == 0) cnt++;
					
					if(ans<cnt)
						ans = cnt;
					
					for(int p=1;p<=n;p++)
						for(int q=1;q<=m;q++)
							map2[p][q] = map[p][q];
				}
			}
            }
		}
        }
	}

    printf("%d\n",ans);

    return 0;
}
