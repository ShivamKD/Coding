//Xenny and Alternating Tasks
//CodeChef March17
//Question Link-https://www.codechef.com/MARCH17/problems/XENTASK/ 



import java.util.*;
class TestCase
{
    public static void main(String args[])
    {
        Scanner ob=new Scanner(System.in);
        int t=ob.nextInt();
        while(t-->0)
        {
            int n=ob.nextInt();
            int a;
            int sum1=0,sum2=0;
            for(int i=0;i<n;i++)
            {
                a=ob.nextInt();
                if(i%2==0)
                sum1+=a;
                else
                sum2+=a;
            }
            for(int i=0;i<n;i++)
            {
                a=ob.nextInt();
                if(i%2!=0)
                sum1+=a;
                else
                sum2+=a;
            }
            if(sum1<sum2)
            System.out.println(sum1);
            else
            System.out.println(sum2);
        }
    }
} 