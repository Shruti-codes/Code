#include<iostream>
#include<vector>
using namespace std;

int hIndex(vector<int>& );

    int main()
    {
        int arr[] ={3,0,6,1,5};
        vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
        cout<<hIndex(v)<<endl;
        return 0;
    }
    
    int hIndex(vector<int>& citations)
    {
        
        sort(citations.begin(), citations.end(), greater<int>());
       
        for(int i=0; i<citations.size(); i++)
        {
            if(i>=citations[i])
                return i;
              
        }
        return citations.size();
       
    }