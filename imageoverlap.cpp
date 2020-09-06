 #include<iostream>
 #include<vector>
 #include<map>
using namespace std;
int largestOverlap(vector<vector<int> >&, vector<vector<int> >&);

int main()
{
    vector<vector<int> > A{ {1,1,0}, {0,1,0}, {0,1,0} };
    vector<vector<int> > B{ {0,0,0}, {0,1,1}, {0,0,1} };

    int res = largestOverlap(A, B);
    cout<<res;


}
 int largestOverlap(vector<vector<int> >& A, vector<vector<int> >& B)
    {
        vector<int> a, b;
        int n=A.size();
        int res=0;
        map<int, int> co;
        for(int i=0; i<n*n; i++)
        {
            if(A[i/n][i%n] == 1)
                a.push_back((i/n)*100+(i%n));
            if(B[i/n][i%n] == 1)
                b.push_back((i/n)*100+(i%n));
        }
        
        for(auto i:a)
            for(auto j:b)
                co[i-j]++;

        for(auto v:co)
            res=max(res, v.second);
        
        return res;
        
    }