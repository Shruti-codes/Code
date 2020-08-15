#include<iostream>
#include<vector>
using namespace std;

bool compare(vector<int>& f, vector<int>& s)
    {
        return (f[1] < s[1]);    
    }

    int main()
    {
        vector<vector<int> > intervals{ {1,2},
                                        {2,3},
                                        {1,3} }; 

        if(intervals.empty())
            return 0;
        
        int r=0, prev=0;
        sort(intervals.begin(), intervals.end(), compare);
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[prev][1] > intervals[i][0])
                r++;
            else
                prev = i;
        }
        
       cout<<r<<endl;
       return 0;
    }