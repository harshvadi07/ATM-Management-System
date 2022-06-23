#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class functions
{
    int *p_arr;
    int *b_arr;
    int *a_arr;
    int p_f,p_r,p_size;
    int b_f,b_r,b_size;
    int a_f,a_r,a_size;
    int index;

public:
    void a_create(int); //to create an array for storing account numbers
    void b_create(int); //to create an array for storing balance ammounts
    void p_create(int); //to create an array for storing pins
    void a_enqueue(int);    //to enqueue account number
    void b_enqueue(int);    //to enqueue balance amount
    void p_enqueue(int);    //to enqueue pin
    int a_dequeue();    //to dequeue account number
    int b_dequeue();    //to dequeue balance amount
    int p_dequeue();    //to dequeue pin
    int create_acc(int, int);   //to create account
    int login(int, int);    //login function
    void deposit(int);  //to deposit money
    int withdraw(int);  //to withdraw money
    int transfer(int);  //to transfer money
    int check_bal();    //to check balance
    void change_pin();  //to change the current pin
};

#endif // FUNCTIONS_H
