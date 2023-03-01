#include<iostream>
using namespace std;

int main()
{
    int n,i;
    int cost[17], ret[17], ans[17] = {0,};

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&cost[i],&ret[i]);
    }

    for(i=n;i>=1;i--){
        if(i+cost[i] > n+1){
            ans[i] = ans[i+1];
        }
        else{
            ans[i] = max(ans[i+1], ret[i]+ans[i+cost[i]]);
        }
    }

    printf("%d\n",ans[1]);

    return 0;
}