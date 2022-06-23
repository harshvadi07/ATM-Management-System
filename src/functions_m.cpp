#include <bits/stdc++.h>
#include "functions.h"
using namespace std;

void functions::p_create(int n)
{
    p_arr = new int[n];
    p_f = -1;
    p_r = -1;
    p_size=n;
}

void functions::p_enqueue(int x)
{
    if(p_f==-1)
    {
        p_f=0;
        p_arr[p_f]=x;
        p_r=0;
    }
    else if(p_r==p_size)
    {
        cout<<"Queue Overflow."<<endl;
    }
    else
    {
        p_arr[++p_r]=x;
    }
}

int functions::p_dequeue()
{
    if(p_f==-1)
        return 0;

    int x=p_arr[p_f];
    if(p_r==p_f)
        p_f=p_r=-1;
    else
    {
        p_f++;
    }

    return x;
}

void functions::b_create(int n)
{
    b_arr = new int[n];
    b_f = -1;
    b_r = -1;
    b_size=n;
}

void functions::b_enqueue(int x)
{
    if(b_f==-1)
    {
        b_f=0;
        b_arr[b_f]=x;
        b_r=0;
    }
    else if(b_r==b_size)
    {
        cout<<"Queue Overflow."<<endl;
    }
    else
    {
        b_arr[++b_r]=x;
    }
}

int functions::b_dequeue()
{
    if(b_f==-1)
        return 0;

    int x=b_arr[b_f];
    if(b_r==b_f)
        b_f=b_r=-1;
    else
    {
        b_f++;
    }

    return x;
}

void functions::a_create(int n)
{
    a_arr = new int[n];
    a_f = -1;
    a_r = -1;
    a_size=n;
}

void functions::a_enqueue(int x)
{
    if(a_f==-1)
    {
        a_f=0;
        a_arr[a_f]=x;
        a_r=0;
    }
    else if(a_r==a_size)
    {
        cout<<"Queue Overflow."<<endl;
    }
    else
    {
        a_arr[++a_r]=x;
    }
}

int functions::a_dequeue()
{
    if(a_f==-1)
        return 0;

    int x = a_arr[a_f];
    if(a_r==a_f)
        a_f=a_r=-1;
    else
    {
        a_f++;
    }

    return x;
}

int functions::create_acc(int ac, int pin)
{
    if(ac/10000==0 && ac/1000!=0 && pin/10000==0 && pin/1000!=0)
    {
        for(int i=0;i<a_size-1;i++)
        {
            if(a_arr[i]==ac)
            {
                cout << "Account already exists." << endl;
                return 1;
            }
        }
        index = a_size-1;
        a_enqueue(ac);
        p_enqueue(pin);
        b_enqueue(0);
        return 2;
    }
    else
    {
        cout << "Enter correct details." << endl;
        return 1;
    }
}

int functions::login(int ac, int pin)
{
    if(ac/10000==0 && ac/1000!=0 && pin/10000==0 && pin/1000!=0)
    {
        for(int i=0; i<=a_size; i++)
        {
            if(a_arr[i]==ac)
            {
                index = i;
                cout << "Logged in Successfully." << endl;
                return 2;
            }
            else if(i == a_size)
            {
                cout << "Account does not exist." << endl;
                return 1;
            }
        }
    }
    else
    {
        cout << "Enter correct details." << endl;
        return 1;
    }
}

void functions::deposit(int amt)
{
    b_arr[index] += amt;
}

int functions::withdraw(int amt)
{
    if(b_arr[index]>=amt)
    {
        b_arr[index] -= amt;
        return amt;
    }
    else
    {
        cout << "Insufficient Balance." << endl;
        return -1;
    }
}

int functions::transfer(int accno)
{
    int ind=-1,amt;
    if(accno/10000==0 && accno/1000!=0)
    {
        for(int i=0;i<=a_size;i++)
        {
            if(a_arr[i]==accno)
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
        {
            cout << "Account does not exist." << endl;
            return -1;
        }
        else
        {
            cout << "Enter amount to transfer: ";
            cin>>amt;
            if(b_arr[index]>=amt)
            {
                b_arr[index] -= amt;
                b_arr[ind] += amt;
                return amt;
            }
            else
            {
                cout << "Insufficient Balance." << endl;
                return -1;
            }
        }
    }
    else
    {
        cout << "Enter correct details." << endl;
        return -1;
    }
}

int functions::check_bal()
{
    return b_arr[index];
}

void functions::change_pin()
{
    int pin;
    cout << "Enter Old Pin: ";
    cin>>pin;
    if(pin==p_arr[index])
    {
        cout << "Enter New Pin: ";
        cin>>pin;
        p_arr[index] = pin;
        cout << "Pin Changed Successfully." << endl;
    }
    else
        cout << "Incorrect Pin." << endl;
}
