#include <iostream>
#include<string>
#include<string.h>

 #ifndef LISTEMPLOYEE
 #define LISTEMPLOYEE

 #include "Employee.h"

using namespace std;
class employee;
class ListEmployee
    {
    private:
         employee *head;
         const int MAX=5; //maximal number of employees
         int numOfEmployee;

    public:
         ListEmployee();
        ~ListEmployee();

        int  getNumberofAllEmployee(); //returns number of employee on the list
        bool checkNumberOFemp(); //check if number of employee is less than MAX

        int hire_Employee(string name,string surname,int cost, int ID); //adds employee to the list if possible

        void removeEmployee(int ID);    //removes employee from the list

		employee* getFreeEmployee(int cost,int oldID); // finds the employee whose has less than three customers, sorting by the costs of service
		employee* findEmployee(int ID);//finds the pointer to chosen employee

        bool checkIfemployeeOnList(int ID); //checks if employee is on the list

        void printListofFREEemployee(); //prints list of free employees,that has less than free customers
        void printListofEmployee();     //prints list of all employees

    };

    #endif
