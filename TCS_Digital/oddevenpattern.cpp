#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> ans;
    
    for(int i=0;i<n;i++)
    {
        if(i % 2 == 0)
        ans.push_back(i);
        else{
            ans.push_back(ans[i-1]/2);
        }
    }

    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}