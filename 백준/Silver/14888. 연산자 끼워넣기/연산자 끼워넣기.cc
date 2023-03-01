#include<iostream>
using namespace std;
int n, max_, min_;
int cnt[5];
void ans(int depth, int* d, int sum)
{
    if(depth == n){
        if(sum < min_) min_ = sum;
        if(sum > max_) max_ = sum;
        return;
    }
    
    for(int i=0;i<4;i++){
        if(cnt[i]>0){
            if(i==0){
                cnt[i]--;
                ans(depth+1,d,sum+d[depth]);
                cnt[i]++;
            }
            else if(i==1){
                cnt[i]--;
                ans(depth+1,d,sum-d[depth]);
                cnt[i]++;
            }
            else if(i==2){
                cnt[i]--;
                ans(depth+1,d,sum*d[depth]);
                cnt[i]++;
            }
            else if(i==3){
                cnt[i]--;
                ans(depth+1,d,sum/d[depth]);
                cnt[i]++;
            }
        }
    }

    return;
}

int main()
{
    int i;
    int* d;

    cin >> n;
    d = new int[n];

    for(i=0;i<n;i++){
        cin >> d[i];
    }
    for(i=0;i<4;i++){
        cin >> cnt[i];
    }
    max_ = -1000000001;
    min_ = 1000000001;
    ans(1,d,d[0]);

    cout << max_ << endl << min_ << endl ;
    delete[] d;

    return 0;
}