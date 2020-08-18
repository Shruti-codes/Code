
#include<iostream>
#include<vector>
#include<iterator>
#include<set>
using namespace std;

    vector<int> res;
    
   int dfs(int N, int num, int K)
    {
        if(N==0)
        {
            res.push_back(num);
            return 0;
        }
        
        set<int> s{(num%10)+K,(num%10)-K };
        set <int, greater <int> > :: iterator i;
        int newn;
        for(i=s.begin(); i!=s.end(); i++)
        {
            if(*i>=0 && *i<=9)
            {
                newn = num*10+(*i);
                dfs(N-1, newn, K);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) 
    {
        for(int i=1; i<=9; i++)
            dfs(N-1, i, K);
        return res;
    }

    int main()
    {
        int N=3, K=7;
        if(N==1)
        {
            cout<<"0,1,2,3,4,5,6,7,8,9";
            exit(1);
        }
        

        res = numsSameConsecDiff(N,K);

        for(int i=0; i!=res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return 0;
    }