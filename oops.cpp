#include <iostream>
#include <string>
using namespace std;

class student
{

    string name;

public:
    void getname(string s)
    {
        name = s;
    }

    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }

    student(string s, int a, int b)
    {
        name = s;
        age = a;
        gender = b;
    } // parametrised constructor

    student()
    {
        cout << "default constructor" << endl;
    } // default constructor;

    student(student &a)
    {
        cout << "copy constructor" << endl;
        name = a.name;
        gender = a.gender;
        age = a.age;
    } // copy constructor

    ~student()
    {
        cout << "destructor called" << endl;
    }
    void printinfo()
    {
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
    }
    int gender;
    int age;
};

int main()
{
    // student a[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     string t;
    //     cin >> t;
    //     a[i].getname(t);
    //     cin >> a[i].age;
    //     cin >> a[i].gender;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     a[i].printinfo();
    //     cout << endl;
    // }
    student c("Aditya", 20, 1);
    c.printinfo();
    student b = c;
    if (c == b)
    {
        cout << "same" << endl;
    }
    return 0;
}