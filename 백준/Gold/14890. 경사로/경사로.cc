#include<iostream>
using namespace std;

int n, m;
bool check_(int map[][101], int x, int y)
{
    int i;
    for(i=1;i<m;i++){
        if(map[x][y] != map[x][y+i]){
            return false;
        }
    }

    return true;
}
int go(int map[][101])
{
    int i, j, tmp, ans = 0;

    for(i=1;i<=n;i++){
        int cnt = 1;
        tmp = 1;
        for(j=2;j<=n;j++){
            if(map[i][j-1] == map[i][j]) cnt++;
            else if(map[i][j] == map[i][j-1] + 1){
                if(cnt >= m){
                    cnt = 1;
                }
                else{
                    tmp = 0;
                    break;
                }
            }
            else if(map[i][j]+1 == map[i][j-1]){
                bool t = check_(map,i,j);
                if(t == false){
                    tmp = 0;
                    break;
                }
                else{
                    j += (m-1);
                    cnt = 0;
                }
            }
            else if(abs(map[i][j] - map[i][j-1]) > 1){
                tmp = 0;
                break;
            }
        }
        ans += tmp;
    }

    return ans;
}
int main()
{
    int i,j;
    int map1[101][101], map2[101][101];

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&map1[i][j]);
            map2[j][i] = map1[i][j];
        }
    }

    printf("%d\n",go(map1)+go(map2));

    return 0;
}