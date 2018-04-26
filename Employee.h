#include <iostream>
#include <vector>
#include<string>
#include<string.h>
using namespace std;


#ifndef EMPLOYEE
#define EMPLOYEE

#include "customer.h"
class customer;
class employee
    {
    private:
         string Name;
         string Surname;
         int cost;
         int ID;

         const int MAX=3;   //max num of customers
		 int numberOfCus;
         vector<customer*> myCust;  //vector of pointers to customers
         void removeALLmyCustomers(); //remove all pointers to employees customers
         employee *next;
    public:

         employee(string Name,string Surname,int cost,int ID); //every employee has unique ID
        ~employee();
        string getName();
        string getSurname();
        int getID();
		int getcost();
        int numberOfmyCus();
        customer* getMyCustomer(int i);     //get i-th customer from employees own list
        employee* getNext();            //get pointer to next employee

        void setNext(employee *next);  //set pointer to next employee



		void addMyCustomer(customer *ptr1); //adding customer to employee owns list by pointing customer by pointer
        bool isLess(); //check if number of employees customers is less than 3

        void removeMyCustomer(int id); //remove pointer to customer of employees list
        void print(); //print employee
        void printMyCustomers(); //print my customers


	};

    #endif

