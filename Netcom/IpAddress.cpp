#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ip = "192.100.000.000";
    int cidr = 16;
    vector<vector<int>> no_of_address;
    int Nocust;
    while (Nocust != -1)
    {
        cout << "enter the number of customers followed by the addresses required by each customer" << endl;
        cout << "enter -1 to end the group creation" << endl;
        cin >> Nocust;
        if (Nocust > 0)
        {
            vector<int> temp;
            int no;
            cin >> no;
            for (int i = 0; i < Nocust; i++)
            {
                int p = 0;
                int j = 0;
                while (p < no)
                {
                    j++;
                    p = pow(2, j);
                }
                temp.push_back(p);
            }
            no_of_address.push_back(temp);
        }
    }
    cout << endl;

    // show the created groups
    for (auto x : no_of_address)
    {
        cout << x.size() << " are the no of customers with each requiring address: "<<endl;
        // for (auto y : x)
        // {
            cout << x[0] << " ";
        // }
        cout << endl;
        // cout << endl;
        // cout << endl;
    }

    int start = -1;
    int cidri;
    int g = 1, c = 1;
    int cal = 0;
    int start_cnt = 0;
    int addi = 10;
    for (auto x : no_of_address)
    {
        for (auto y : x)
        {
            cal += y;
            // cout<<" the ip addresses are ";
            int p = 0;
            int i = 0;
            while (p < y)
            {
                i++;
                p = pow(2, i);
            }
            cidri = 32 - i;
            start += y;
            cout << "G" << g << "C" << c++ << " start : " << ip << " End : " << ip.substr(0, 12) << start << " CIDR : " << cidri << endl;
            ip = ip.substr(0, 12) + to_string(start + 1);
            if(start == 255)
            {
                if(start_cnt == 10 ||start_cnt == 100)
                {
                    addi--;
                }
                start_cnt++;
                string add = to_string(start_cnt);
                ip = ip.substr(0, addi) + add + "." + "000";
                // addi--;
                start = -1;
            }
        }
        g++;
        c = 1;
    }
    cout<<"Numer of balance addresses : "<<(pow(2,16)-cal)<<endl;
    cout<<"Total Numer of addresses : "<<pow(2,16)<<endl;
    return 0;
}