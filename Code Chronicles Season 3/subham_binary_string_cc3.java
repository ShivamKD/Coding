//Subham and Binary String
//Code Chronicles Season 3

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
            String s=ob.next();
            int count=0;
            for(int i=0;i<n;i++)
            if(s.charAt(i)=='0')
            count++;
            System.out.println(count);
        }
    }
}