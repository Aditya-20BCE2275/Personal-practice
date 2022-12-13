#include <bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    int arr[] = {1, 4, 62, 32, 54, 8, 7};
    priority_queue<int , vector<int>,greater<int>> pq;
    for (auto x : arr)
    {
        pq.push(x);
    }
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}