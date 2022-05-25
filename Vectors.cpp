// Vectors are also called dynamic arrays
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // declaring a vector
    // v.size() -> gives the size of the vector
    vector<int> v;
    int n;
    cin >> n;
    int e;
    // in this loop we push elemnets into the vector using pushback function
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }

    // printing the vector
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    // We can also traverse the vector using an iterator
    vector<int>::iterator it;
    // here iterator acts as an looping element in the for loop we use .
    for (it = v.begin(); it != v.end(); it++)
    {
        // here we dereffernce it as it's a pointer
        cout << *it << " ";
    } cout<<endl;

    // This method deletes the specific element position in the vector through the iterator method

    v.erase(v.begin()+2);

    // Traversing a vector using auto
    for (auto element : v)
    {
        cout << element << endl;
    }

    // to pop the last element from the vector we use
    v.pop_back();

    // we can also pre intialise a vector with a particular int and frequency
    vector<int> v2(3, 50); // 50 50 50

    // this function swaps the value of v and v2
    swap(v, v2);
    // sorting the vector is similar as sorting an array
    sort(v.begin(), v.end());
}