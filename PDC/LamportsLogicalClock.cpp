#include <bits/stdc++.h>
using namespace std;

// Aditya Mohite 20BCE2275

int max1(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void display(int ex1, int ex2, int p1[5], int p2[3])
{
    int i;
    cout << "\nThe time stamps of events in P1:\n";

    for (i = 0; i < ex1; i++)
    {
        cout << p1[i] << " ";
    }

    cout << "\nThe time stamps of events in P2:\n";

    // Print the array p2[]
    for (i = 0; i < ex2; i++)
        cout << p2[i] << " ";
}

// Function to find the timestamp of events
void lamportLogicalClock(int ex1, int ex2, int m[5][3])
{
    int i, j, k, p1[ex1], p2[ex2];

    for (i = 0; i < ex1; i++)
        p1[i] = i + 1;

    for (i = 0; i < ex2; i++)
        p2[i] = i + 1;

    cout << "\t";

    for (i = 0; i < ex2; i++)
        cout << "\tex2" << i + 1;

    for (i = 0; i < ex1; i++)
    {

        cout << "\n ex1" << i + 1 << "\t";

        for (j = 0; j < ex2; j++)
            cout << m[i][j] << "\t";
    }

    for (i = 0; i < ex1; i++)
    {
        for (j = 0; j < ex2; j++)
        {

            // Change the timestamp if the
            // message is sent
            if (m[i][j] == 1)
            {
                p2[j] = max1(p2[j], p1[i] + 1);
                for (k = j + 1; k < ex2; k++)
                    p2[k] = p2[k - 1] + 1;
            }

            // Change the timestamp if the
            // message is received
            if (m[i][j] == -1)
            {
                p1[i] = max1(p1[i], p2[j] + 1);
                for (k = i + 1; k < ex1; k++)
                    p1[k] = p1[k - 1] + 1;
            }
        }
    }

    display(ex1, ex2, p1, p2);
}

int main()
{
    int ex1 = 5, ex2 = 3, clck[5][3];
    clck[0][0] = 0;
    clck[0][1] = 0;
    clck[0][2] = 0;
    clck[1][0] = 0;
    clck[1][1] = 0;
    clck[1][2] = 1;
    clck[2][0] = 0;
    clck[2][1] = 0;
    clck[2][2] = 0;
    clck[3][0] = 0;
    clck[3][1] = 0;
    clck[3][2] = 0;
    clck[4][0] = 0;
    clck[4][1] = -1;
    clck[4][2] = 0;

    lamportLogicalClock(ex1, ex2, clck);

    return 0;
}
