#include <iostream>

#include<string>
#include<string.h>
using namespace std;

#ifndef LISTCUSTOMER
#define LISTCUSTOMER

#include "customer.h"
class customer;
class ListCustomer
    {

    private:

        customer *head;
        int numOfCust;

    public:
         ListCustomer();
        ~ListCustomer();

         int getnumOfCust();  //gets number of customers in the list
         customer* findCustomer(const int ID); //finds pointers to customer we are looking for
         int add_Customer(string name,string surname,int ID, int salary,int balance); //adds customer to the list
         void removeCustomer(int IDcard);		//removes customer from the list
		 int modifySalary (int IDcard,int salary);	//modify the salary of customer if he wanted to change
         bool checkIfCustomerOnList(int ID); //check if customer is already on the list

		void printListofCustomers();//prints list of all customers

    };

    #endif // LISTCUSTOMER
