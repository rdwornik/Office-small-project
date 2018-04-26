#include <iostream>
#include<string>
#include<string.h>
using namespace std;

 #ifndef CUSTOMER
 #define CUSTOMER

 #include "Employee.h"
 #include "Office.h"
 #include "ListCustomer.h"
 #include "ListEmployee.h"

class Office;
class employee;
class ListCustomer;
class ListEmployee;
class customer
    {
    private:
         string Name;
         string Surname;
         int IDcard;
         int salary;
         int balance;
         int oldEmp;
         int numberOnlist;
         int oldbalnce;
         employee *current;  //points for current employee
         Office *ptr;
         customer *next;
    public:

         customer(string Name,string Surname,int IDcard,int salary,int balance);
        ~customer();

        void printmyEmployee(Office *ptr);  //prints customers employee in specific office
        void leaveOffice(Office *ptr);      //leaves offices and changes balance

        string getName();
        string getSurname();
        int getIDcard();
		int getSalary();
		int getBalance();
		int getOldEmp1();
		int getOldbalance();
		employee* getCurrent();         //get pointer to current employee
		customer* getNext();            //gets pointer to next customer

        void setNext(customer* next);       //sets pointer to next customer
        void setoldeEmp(int n);
        void setSalary(int n);
		void setBalance(int n);
		void setCurrent(employee *curr);
		void setOldbalance(int n);          // set oldbalance for situation when some employee is fired


		void modifySalary(Office *name,int salary); // if user earn more money he can modify it salary in chosen office but if he earned less and can't afford current employee he will be rejected from office
        void showMeListoffreeEmployee(Office *name);  //user can see the list of all employees who are free (by free I mean they are servicing less than 3 people)
        void choseOfficeandEmployee(Office *Offname,int ID); //Customer choose employee who want to work with
        void checkMybalance();   //balance shows how much money customer can still spend on services if it's negative he shouldn't get any services
        void checkSalary();  //checks salary

        void print();//prints customers data
    };

#endif
