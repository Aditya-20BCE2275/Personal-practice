#include <iostream>
#include <vector>
using namespace std;

// Delete a element from a vector

void Removeelement(vector<int> &v, int num)
{
    vector<int>::iterator it;
    int temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != num)
        {
            v[temp] = v[i];
            temp++;
        }
    }

    for (int i = 0; i < temp; i++)
    {
        cout << v[i] << "  ";
    }
}

int main()
{
    vector<int> v;
    cout << "enter the number of elements u wanna enter" << endl;
    int n, in;
    cin >> n;
    cout << "enter the elements in the vector " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        v.push_back(in);
    }
    cout << "enter the number u wanna delete from the vector" << endl;
    int del;
    cin >> del;
    cout << endl;

    Removeelement(v, del);

    return 0;
}