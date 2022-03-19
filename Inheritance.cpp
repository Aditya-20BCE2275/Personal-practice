#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    bool gender;
    string name;
    int rollno;

    void setgender(bool a)
    {
        gender = a;
    }

    void getgender()
    {
        cout << "the gender is " << gender << endl;
    }
};

class deri : public student
{
public:
    int ok;
};
main()
{
    student a;
    deri b;
    bool temp;
    cin >> temp;
    b.setgender(temp);
    b.getgender();
    return 0;
}