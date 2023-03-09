#include<iostream>
#include<math.h>
using namespace std;

long long int f(long long int a)
{
    int digit;
    long long int cnt = 0, ans = 0;
    digit = (int)log2(a);

    while(digit>=0){
        cnt = (long long int)1 << digit;
//        printf("%d %lld\n",digit,cnt);
        if((int)log2(a) == (int)log2(cnt)){
            ans += ( (cnt>>1)*digit + a-cnt+1 );
            a -= cnt;
        }
        digit --;
    }

    return ans;
}

int main()
{
    long long int n, m;

    scanf("%lld %lld",&n,&m);
    printf("%lld\n",f(m)-f(n-1));

    return 0;
}

// 1099511627776
