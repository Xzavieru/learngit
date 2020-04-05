#include<bits/stdc++.h>
using namespace std;


using namespace std;

const int N= 10000;
int a[N], dp[N], maxsum, maxstart, maxend;

void dpsum(int n)
{
    int sum, sumstart;

    maxsum = maxstart = maxend = a[0];
    sum = 0;
    for(int i = 0; i<n; i++) {
        if(sum < 0)  {
            sum = a[i];
            sumstart = a[i];
        } else
            sum += a[i];
        if(sum > maxsum) {
            maxsum = sum;
            maxstart = sumstart;
            maxend = a[i];
        }
    }
}

int main()
{
    int n;

    while(scanf("%d", &n) != EOF && n) {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

        dpsum(n);

        if(maxsum < 0)
            printf("0 %d %d\n", a[0], a[n-1]);
        else
            printf("%d %d %d\n", maxsum, maxstart, maxend);
    }

    return 0;
}


