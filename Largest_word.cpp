#include<iostream>
using namespace std;

int main()
{
    // Finding the largest word in a sentence
    int n;
    cin>>n;
    char a[n+1];
    cin.ignore();
    cin.getline(a,n);
    cout<<a;
    cin.ignore();
    int i=0;
    int curlen=0,maxlen=0;
    int pos;
    // we run the loop until the end of line
    while(a[i]!='\0')
    {
        // if we encounter a space we check for the elements before it and their len also if there is an eof char on i+1th element we check and add its psition according at last we display max lenght and the word present
        if(a[i] == ' ' || a[i+1] == '\0')
        {
            if (a[i+1] == '\0')
            {
                curlen++;
                pos=i+1;
            }
            else{
            pos = i;}
            if(curlen>maxlen)
            maxlen=curlen;
            cout<<"this is curr len = "<<curlen<<endl;
            curlen=0;
        }
        else{
            curlen++;
        }
        i++;
    }
    cout<<maxlen<<endl;
    cout<<pos<<endl;
    for(int i= pos-maxlen;i<pos;i++)
    {
        // cout<<"for loop is running";
        cout<<a[i];
    }
    return 0;
}