#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[k];
	int h[n+1]={0};
	
	for(int i=0;i<k;i++)
	cin>>a[i];
	
	int m=a[0];
	int cur_min=1;
	stack <int> st;
	st.push(a[0]);
	if(a[0]==cur_min)
	{
	    cur_min++;
	    st.pop();
	}
	
	h[a[0]]=1;
	
	
	
	
	int p;
	
	int flag=0;
	
	for(int i=1;i<k;i++)
	{
	    if(!st.empty())
	    {
	        p=st.top();
	        //st.pop();
	        if(a[i]==cur_min)
	        {
	            cur_min++;
	            while(!st.empty())
	            {
	                if(st.top()==cur_min)
	                {
	                    cur_min++;
	                    st.pop();
	                }
	                else
	                {
	                    break;
	                }
	            }
	        }
	        else
	        {
	            if(a[i]<p)
	            st.push(a[i]);
	            else
	            {
	                flag=-1;
	                break;
	            }
	        }
	    }
	    else
	    st.push(a[i]);
	}
	
	if(flag==-1)
	cout<<"-1";
	else
	{
	    for(int i=0;i<k;i++)
	    cout<<a[i]<<" ";
	    
	    stack <int> r;
	    while(!st.empty() && cur_min<=n)
	    {
	        if(cur_min<st.top())
	        {
	            r.push(cur_min);
	            cur_min++;
	        }
	        else
	        {
	            while(!r.empty())
	            {
	                cout<<r.top()<<" ";
	                r.pop();
	            }
	            //cout<<st.top()<<" ";
	            cur_min++;
	            st.pop();
	        }
	        
	    }
	    while(cur_min<=n)
	    {
	        r.push(cur_min);
	        cur_min++;
	    }
	    
	    while(!r.empty())
	    {
	        cout<<r.top()<<" ";
	        r.pop();
	    }
	}
	return 0;
}
