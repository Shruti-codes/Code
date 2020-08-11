#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int l1 = arr1.size();
        int l2 = arr2.size();
        int co=0, flag =0;
        
        for(int i=0; i<l1; i++)
        {
            for(int j=0; j<l2; j++)
            {
                if(abs(arr1[i] - arr2[j]) <= d)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                co++;
            else
                flag = 0;
        }
        
        return (co);
    }

    int main()
    {
        int arr1[] ={4,5,8};
        int arr2[] = {10,9,1,8};
        vector<int> v1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
        vector<int> v2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
        cout<<findTheDistanceValue(v1, v2, 2)<<endl;
        return 0;
    }
