#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

   int main()
    {
        int rowIndex = 6;
        long int d,p=0, el=1;
        vector<int> v;
        while(p<=rowIndex)
        {
            v.push_back(el);
            p++;
            el = el*( rowIndex+1-p)/p;
        }
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<", " ;
    
        cout<<endl;
    }