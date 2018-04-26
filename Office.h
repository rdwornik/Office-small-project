#include <iostream>
 using namespace std;
#include<string>
#include<string.h>


 #ifndef OFFICE
 #define OFFICE

 #include "ListCustomer.h"
 #include "ListEmployee.h"
 #include "Employee.h"

 class ListCustomer;
 class ListEmployee;
 class employee;
 class Office
    {
    private:
         string officeName;
        ListEmployee *allemployees;
        ListCustomer *allcustomers;

    public:

        Office(string name);
        ~Office();
        string getofficeName();
        int  getnumOfCust();     //gets number of customers in the list
        int  getNumberofAllEmployee(); //returns number of employee on the list


        int add_Customer(string name,string surname,int IDcard, int salary,int balance); //adds customer to the list
        int addCustomerToEmployye(int empID,int IDcard); //add customers to specific employee

        void removeMyCustomer(int ID);  //removes customer of specific employee
        void removeCustomerFromOffice(int ID);  //remove customer from office completely

        int hire_Employee(string name,string surname,int cost, int IDcard); //adds employee to the list
        void fire_Employee(int ID); //methods which not only fires  the employee but also have to move customers to other employees
		int modifySalary (int IDcard ,int salary);//modifies the salary of customer
        void showEmployeeToCustomer(int IDcard); //shows customers employee

        employee* findEmployee(int ID);   //finds pointers to customer we are looking for
        customer* findCustomer(int IDcard); //finds the pointer to chosen employee

        bool checkIfCustomerCanAfford(int balance, int cost); //checks if customer can afford the employee
        bool checkIfCustomerCanModifySalary(int balance,int salary,int newsalary); //checks if customers can still be in office after changing salary
        bool checkIfCustomerOnList(int ID); //checks if customer is on the list also returns false if empty
        bool checkIfEmployeeOnList(int ID); //checks if employee is on the list also returns false if empty
        bool checkIFmployeeIsFree(int ID); //checks if employee has less than 3 customers

        bool enoughFREEemployee(int numOfcust,int numOfemp,int numberOfEmpCust); //checks if there is enough free employees to fire some employee

        void printListofFreeEmployee(); //the list of all employees who are free (by free I mean they are servicing less than 3 people)
        void printListofCustomers(); //prints list of all customers
        void printListofEmployee(); //prints list of all employees
        void printListOfEmployeesCustomers(int ID); //prints list of customers of specific employee
        void printCustomersEmployee(int Id);  //prints employee of specific customer
        void printNumberOfemployee();  //prints number of employee in the office

        void setEmp(int Id);  //set "Emp" this value changes if employee was fired, it helps to inform user that his employee is changed
        int getOldEmp(int Id);





    };


#endif
