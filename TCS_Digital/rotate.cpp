#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    for(int i=1;i<=5;i++)
    {
        arr.push_back(i*10);
    }
    int k;
    cin>>k;
    k=k%arr.size();
    int count=0;
    int i=arr.size()-1;
    while(count<k)
    {
        int a=arr[i];
        arr.erase(arr.begin()+i,arr.end());
        arr.insert(arr.begin(),a);
        count++;
    }
    for(auto it:arr)
    cout<<it<<" ";

}

// 10 20 30 40 50
// 50 10 20 30 40 first rotate
// 40 50 10 20 30 second rotate