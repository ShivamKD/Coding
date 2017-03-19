//CodeChef
//Bear and Extra Number
//Question Link-https://www.codechef.com/MARCH17/problems/EXTRAN/


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
            long arr[]=new long[n];
            
            for (int i=0;i<n ;i++ )
            {
                arr[i]=ob.nextLong();
                
            }
            boolean b[]=new boolean[n];
            //System.out.println(b[0]);
            Arrays.sort(arr);
            for(int i=0;i<n-1;i++)
            {
                if(arr[i]+1!=arr[i+1])
                {
                    if(arr[i]==arr[i+1])
                    System.out.println(arr[i]);
                    else
                    {
                        if(i>0)
                        {
                            if(arr[i]-1!=arr[i-1])
                            System.out.println(arr[i]);
                            else
                            System.out.println(arr[i+1]);
                        }
                        else
                        {
                            if(arr[i+1]+1!=arr[i+2])
                            System.out.println(arr[i+1]);
                            else
                            System.out.println(arr[i]);
                        }
                    }
                    break;
                }
            }
        }
    }
} 