#include<iostream>
using namespace std;

int m;
void ans(int n, int count, bool* vis, int p, int** power)
{
    if(count == n/2){
        int sum=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(vis[i] && vis[j]){
                    sum += (power[i][j]+power[j][i]);
                }
                else if(vis[i] != true && vis[j] != true){
                    sum -= (power[i][j]+power[j][i]);
                }
            }
        }
        if(abs(sum) < m) m = abs(sum);
        
        return;
    }
    if(p == n) return;

    vis[p] = true;
    ans(n,count+1,vis,p+1,power);
    vis[p] = false;
    ans(n,count,vis,p+1,power);

    return;
}

int main()
{
    int n, i;
    bool* vis;
    int** power;
    scanf("%d",&n);
    
    vis = new bool[n/2];
    
    power = new int*[n];
    for(i=0;i<n;i++){
        power[i] = new int[n];
        for(int j=0;j<n;j++){
            scanf("%d",&power[i][j]);
        }
    }

    m = 1000000000;

    ans(n,0,vis,0,power);
    cout << m << endl;

    delete [] vis;
    for(i=0;i<n;i++){
        delete[] power[i];
    }
    delete[] power;
    
    return 0;
}