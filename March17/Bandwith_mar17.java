//March_Challenge 2017
//BandWidth of the Matrix


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
            int count=0;
            for(int i=0;i<n*n;i++)
            {
                a=ob.nextInt();
                if(a==1)
                count++;
            }
            if(count<=n)
            {
                System.out.println("0");
                continue;
            }
            int flag=0;
            int temp=n;
            for(int k=1;k<n;k++)
            {
                temp+=2*(n-k);
                if (temp>=count)
                {
                    System.out.println(k);
                    break;
                }
                
            }
            //if(flag==0)
            //System.out.println(n-1);
        }
    }
}  