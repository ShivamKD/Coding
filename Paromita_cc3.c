//Dynamic problem.
//Choosing subsequence of the array such that you choose no two consecutive number 
//of the array and the resulting sum be maximum.


#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
     while(t-->0)
        {
            int n;
            scanf("%d",&n);
            int arr[100000];
            int i;
            int max;
            int dp[100000];
            ;
            ;
            ;
            for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
            if(n==1)
            printf("%d\n",arr[0]);
            else if(n==2)
            {
                max=arr[0]>arr[1]?arr[0]:arr[1];
                printf("%d\n",max);
            }
            else
            {
                dp[0]=arr[0];
                dp[1]=arr[1];
                dp[2]=arr[2]+arr[0];
                max=dp[1];
                ;
                if(dp[2]>max)
                max=dp[2];
                for(i=3;i<n;i++)
                {
                    int x=dp[i-3]+arr[i];
                    int y=dp[i-2]+arr[i];
                    dp[i]=x>y?x:y;
                    if(dp[i]>max)
                    max=dp[i];
                }
                printf("%d\n",max);
                //System.out.println(max);
            }
        }
    return 0;
}
