#include<iostream>
#include <queue>
using namespace std;

char map[101][101];
int visit[101][101]={0,};

int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(int x,int y, bool color_blind){
    
    queue <pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = 1;

    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx<n && ty<n && tx>-1 && ty>-1 && !visit[tx][ty]){
            if(map[x][y] == map[tx][ty]){
                q.push({tx,ty});
                visit[tx][ty] = 1;
            }
            else if(color_blind && abs(map[tx][ty]-map[x][y]) == abs('R'-'G')){
                q.push({tx,ty});
                visit[tx][ty] = 1;
            }
            }
        }
    }
}

int main()
{
    int i,j, ans=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",map[i]);
    }
    
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				BFS(i, j, false);
				ans++;
			}
		}
	}
    printf("%d\n",ans);

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}

    ans = 0;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				BFS(i, j, true);
				ans++;
			}
		}
	}
    printf("%d\n",ans);

    return 0;
}