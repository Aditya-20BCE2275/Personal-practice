#include<iostream>
using namespace std;
// checks if the position recieved in the arguments is safe or not
bool safe(int** arr,int x,int y,int n)
{
    if(x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool rat(int** arr,int x,int y,int n,int** sol){
    if(x==n-1 && y==n-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(safe(arr,x,y,n))
    {
        sol[x][y]=1;
        // recursivel checking the positions of the array
        if(rat(arr,x+1,y,n,sol))
        {
            return true;
        }
        if(rat(arr,x,y+1,n,sol))
        {
            return true;
        }
        // if both the positions are blocked then the positions are again set to 0
        sol[x][y]=0; // backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cout<<"enter the order of matrix u want "<<endl;
    cin>>n;
    int** arr = new int* [n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    int** sol = new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j]=0;
        }
    }
    if(rat(arr,0,0,n,sol))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
            
        }
        
    }
    return 0;
}
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 0 1 1