#include <iostream>
#include<string>
#include<string.h>



#include "Office.h"
#include "customer.h"
#include "ListCustomer.h"
#include "ListEmployee.h"
#include "Employee.h"

using namespace std;
int main()
{

//FULL TESTING ON OFFICE LIST AND CUSTOMER CLASS


Office *Off1=new Office("Office One");
Office *Off2=new Office("Office Two");

customer *cus1=new customer("Jan","Nowak",1,2000,2000);

customer *cus2=new customer("Piotr","Kowalski",3,5000,500);
customer *cus3=new customer("Tomasz","Matejko",2,1000,100);
customer *cus4=new customer("Brad","Pitt",7,15000,-100);
customer *cus5=new customer("Anna","Arbuz",55,3000,1000);

cus1->print();
cus1->printmyEmployee(Off1);           //add to office that doesn't belongs
cus1->leaveOffice(Off1);               //leave office doesnt' belongs
cus1->showMeListoffreeEmployee(Off1);   //show empty list
cus1->modifySalary(Off1,1000);          //modify salary in office that doeasn't belongs

cout<<"-----------"<<endl;
Off1->fire_Employee(2);             //fire employee from empty list
Off1->printListofEmployee();        //print empty list
Off1->removeCustomerFromOffice(2); //remove customer from empty office

cout<<"-----------"<<endl;
Off1->hire_Employee("Adam","Mickiewicz",500,11);  //hire Employee with the same code
Off1->hire_Employee("Adam","Mickiewicz",500,11);

cout<<"-----------"<<endl;
Off1->hire_Employee("Pawel","Zarzeczny",100,12);
Off1->hire_Employee("Michal","Aniol",3000,13);
Off1->hire_Employee("Lukas","Guy",2000,7);
Off1->hire_Employee("Tomasz","Chrobry",100,47);
Off1->hire_Employee("Michal","Aniol",3000,70); //hire more than 5 employee

cout<<"-----------"<<endl;
Off1->printListofEmployee();            //print list of employees

cout<<"-----------"<<endl;
cus4->choseOfficeandEmployee(Off1,12); //choose employee with negative balance

cout<<"-----------"<<endl;
cus1->choseOfficeandEmployee(Off1,14); //check if i can choose employee thats not in the office should be rejected
cus1->choseOfficeandEmployee(Off1,13); //check if i can choose employee i can't afford should be rejected
cus1->choseOfficeandEmployee(Off1,12); //check if i can choose employee i can afford should be added to list
cus1->choseOfficeandEmployee(Off1,11); //chec if i can choose another employee from the same office, should be rejected

cout<<"-----------"<<endl;
cus1->printmyEmployee(Off1);          //print who is my employee
cus2->choseOfficeandEmployee(Off1,12);
cus2->printmyEmployee(Off1);
cus3->choseOfficeandEmployee(Off1,12);
cus3->printmyEmployee(Off1);

cout<<"-----------"<<endl;
cus5->choseOfficeandEmployee(Off1,12); //choose employee that has 3 customers

cout<<"-----------"<<endl;
cus5->showMeListoffreeEmployee(Off1);  //show list of employee check it if they are really free
cus5->choseOfficeandEmployee(Off1,47); //check if they are free
cus5->printmyEmployee(Off1);            //check who is my employee
cus5->checkMybalance();                 //check my balance did it changed

cout<<"-----------"<<endl;
Off1->printListofCustomers();      //print list of customers
Off1->fire_Employee(12);            //fire employee that had 3 customers

cout<<"-----------"<<endl;
Off1->printListofCustomers();       //check if customers still on list
Off1->printListOfEmployeesCustomers(12); //check if fired employee has no customers
Off1->printCustomersEmployee(1);    //office prints customers employee
cus1->printmyEmployee(Off1);        //print my employee who was fired, check if i was informed about it

cout<<"-----------"<<endl;
cus1->leaveOffice(Off1);        //leave office
cus1->checkMybalance();         //check my balance after leaving office and after fired employee
Off1->printListofCustomers();      //print list of customers after leaving one of customers


cout<<"-----------"<<endl;
cus5->printmyEmployee(Off1);       //print  customer of fired employee

cout<<"-----------"<<endl;
Off1->fire_Employee(47);            //fire employee again
Off1->printListofCustomers();       //print list of customers if everything ok
cus5->leaveOffice(Off1);            //leave office check if was informed about fired employee
Off1->printListofCustomers();       //print list of customers check everything ok

cout<<"-----------"<<endl;
cus3->modifySalary(Off1,100);       //modify salary you should be rejected from office becouse you can't afford it anymore
cus3->checkMybalance();             //check balance
cus3->checkSalary();            //check salary is it modified

cout<<"-----------"<<endl;
cus2->modifySalary(Off1,8000);      //modify salary
cus2->checkMybalance();         //check balance did it changed
cus2->checkSalary();            //check salary did it changed

cout<<"-----------"<<endl;
cus3->setSalary(7000);
cus3->choseOfficeandEmployee(Off1,12);

cout<<"-----------"<<endl;
Off1->printListOfEmployeesCustomers(12);  //check if can choose employee which was fired

cout<<"-----------"<<endl;
Off2->hire_Employee("Adam","Mickiewicz",500,11);  //hire second office
cus1->choseOfficeandEmployee(Off2,11);           //check if can go to other offices

cout<<"-----------"<<endl;
cus1->checkMybalance();                  //control balance

cout<<"-----------"<<endl;
Off2->fire_Employee(11);            //fire employee check if there is enough employee

delete Off1;
delete Off2;

}
