#include <bits/stdc++.h>
#include "functions.h"
using namespace std;

int main()
{
    functions fnct;

    //opening the 'details.txt' file
    fstream file;
    file.open("details.txt", ios::out | ios::in);
    int c=0,temp;
    while(!file.eof())
    {
        file>>temp;
        c++;
    }
    c/=3;
    fnct.a_create(c+1);
    fnct.p_create(c+1);
    fnct.b_create(c+1);
    int pin, bal, ac;
    file.clear();
    file.seekg(0,ios::beg);

    //importing all the information from the file
    for(int i=0; i<c; i++)
    {
        file>>ac;
        file>>pin;
        file>>bal;
        fnct.a_enqueue(ac);
        fnct.p_enqueue(pin);
        fnct.b_enqueue(bal);
    }

    int choice=0,f=0,z=0;

    //Welcome message
    printf("\n /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$       /$$$$$$$$ /$$$$$$         /$$$$$$  /$$$$$$$$ /$$      /$$   /$$");
    printf("\n| $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/      |__  $$__//$$__  $$       /$$__  $$|__  $$__/| $$$    /$$$  | $$");
    printf("\n| $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$               | $$  | $$  \\ $$      | $$  \\ $$   | $$   | $$$$  /$$$$  | $$");
    printf("\n| $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$            | $$  | $$  | $$      | $$$$$$$$   | $$   | $$ $$/$$ $$  | $$");
    printf("\n| $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/            | $$  | $$  | $$      | $$__  $$   | $$   | $$  $$$| $$  |__/");
    printf("\n| $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$               | $$  | $$  | $$      | $$  | $$   | $$   | $$\\  $ | $$    ");
    printf("\n| $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$         | $$  |  $$$$$$/      | $$  | $$   | $$   | $$ \\/  | $$   /$$");
    printf("\n|__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/         |__/   \\______/       |__/  |__/   |__/   |__/     |__/  |__/");
    printf("\n\n");

l1:
{
    //Initial Menu
    cout << "\n1. Create Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin>>choice;

    //Different operation based on the user's choice
    if(choice==1)
    {
        f=1;
        cout << "Enter 4 digit Acc Number: ";
        cin>>ac;
        cout << "Enter 4 digit Pin: ";
        cin>>pin;
        z = fnct.create_acc(ac,pin);
        if(z==1) goto l1;
        else if(z==2) goto l2;
    }
    else if(choice==2)
    {
        cout << "Enter 4 digit Acc Number: ";
        cin>>ac;
        cout << "Enter 4 digit Pin: ";
        cin>>pin;
        z = fnct.login(ac,pin);
        if(z==1) goto l1;
        else if(z==2) goto l2;
    }
    else if(choice==3)
    {
        cout << "Thank You! Visit Again!" << endl;
        goto l3;
    }
    else
    {
        cout << "Invalid Choice." << endl;
        goto l1;
    }
}
l2:
{
    //Login Menu
    cout << "\n1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Change Pin" << endl;
    cout << "6. Exit" << endl;

    int amt=0;

    //Operation based on the user's choice
    while(choice!=6)
    {
        cout << "\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout << "Enter amount to deposit: ";
            cin>>amt;
            fnct.deposit(amt);
            cout << amt << " deposited successfully." << endl;
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin>>amt;
            amt = fnct.withdraw(amt);
            if(amt!=-1)
                cout << amt << " withdrawn successfully." << endl;
            break;

        case 3:
            int accno;
            cout << "Enter Account No. to transfer to: ";
            cin >> accno;
            amt = fnct.transfer(accno);
            if(amt!=-1)
                cout << amt << " transferred successfully." << endl;
            break;

        case 4:
            cout << "Current Balance = " << fnct.check_bal() << endl;
            break;

        case 5:
            fnct.change_pin();
            break;

        case 6:
            cout << "Thank You! Visit Again!" << endl;
            break;

        default:
            cout << "Enter valid choice." << endl;
            break;
        }
    }
}
l3:
{
    if(f==1) c++;
    file.clear();
    file.seekg(0,ios::beg);
    for(int i=0; i<c; i++)
    {
        file << fnct.a_dequeue() << endl;
        file << fnct.p_dequeue() << endl;
        file << fnct.b_dequeue() << endl;
    }
    file.close();

    return 0;
}
}
