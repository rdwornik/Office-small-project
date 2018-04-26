#include <iostream>
 using namespace std;
#include<string>
#include<string.h>

#include "Office.h"

Office::Office(string name)
{
    allcustomers=new ListCustomer();
    allemployees=new ListEmployee();
    this->officeName=name;
}

Office::~Office()
{
delete allemployees;
delete allcustomers;
}

string Office::getofficeName()
{
    return officeName;
}

int Office::add_Customer(string name,string surname,int IDcard, int salary,int balance)
{
   if(checkIfCustomerOnList(IDcard)==false)
   {
        allcustomers->add_Customer(name,surname,IDcard,salary,balance);
        return 1;
   }
   else
    {
        cout<<"Customer with the same ID wasn't added to the list"<<endl;
        return 0;
    }
}

int Office::hire_Employee(string name,string surname,int cost, int ID)
{


   if(checkIfEmployeeOnList(ID)==false)
   {
      if(allemployees->checkNumberOFemp()==true)
      {
            allemployees->hire_Employee(name,surname,cost,ID);
            return 1;
      }
      else
      {
          cout<<"You have max number of employee can't add more"<<endl;
          return 0;
      }
   }
   else
    {
        cout<<"Employee with the same ID wasn't added to the list"<<endl;
        return 0;
    }

}

bool Office::checkIfCustomerOnList(int ID)
{
   return allcustomers->checkIfCustomerOnList(ID);
}

void Office::fire_Employee(int ID)
{
   if(allemployees->getNumberofAllEmployee()!=0)
    {
      if(allemployees->checkIfemployeeOnList(ID)==true)
        {
            if(enoughFREEemployee(allcustomers->getnumOfCust(),allemployees->getNumberofAllEmployee(),allemployees->findEmployee(ID)->numberOfmyCus())==true)
            {
             employee *toFire= allemployees->findEmployee(ID);
                for(int i=0;i<toFire->numberOfmyCus();i++)
                {

                employee *toAdd=  allemployees->getFreeEmployee(toFire->getcost(),ID);

                toAdd->addMyCustomer(toFire->getMyCustomer(i));
                toFire->getMyCustomer(i)->setCurrent(toAdd);
                findCustomer(toFire->getMyCustomer(i)->getIDcard())->setCurrent(toAdd);
                setEmp(toFire->getMyCustomer(i)->getIDcard());
                }

            allemployees->removeEmployee(ID);
            }
            else
            cout<<"not enough employee to fire"<<endl;
        }
       else
        cout<<"There is no such a employee with ID: "<<ID<<endl;
    }
   else
       cout<<"You have zero employee"<<endl;

}

int Office::modifySalary(int IDcard,int salary)
{
    if(checkIfCustomerOnList(IDcard)==true)
    {
    allcustomers->modifySalary(IDcard,salary);
    return 1;
    }
    else
    return 0;
}

employee* Office::findEmployee(int ID)
{
if(checkIfEmployeeOnList(ID)==true)
return allemployees->findEmployee(ID);

}

customer* Office::findCustomer(int IDcard)
{
if(checkIfCustomerOnList(IDcard)==true)
return allcustomers->findCustomer(IDcard);
}

void Office::printListofCustomers()
{
    allcustomers->printListofCustomers();
}
void Office::printListofFreeEmployee()
{
    allemployees->printListofFREEemployee();
}

void Office::printListofEmployee()
{
    allemployees->printListofEmployee();
}
bool Office::enoughFREEemployee(int cust,int emp,int num)
{
  int a;
  a=3*(emp-1)-cust;
  if(a>=num)
   return true;
  else
   return false;
}


bool Office::checkIfEmployeeOnList(int ID)
{
    return allemployees->checkIfemployeeOnList(ID);
}

bool Office::checkIfCustomerCanAfford(int balance, int cost)
{
    if((balance-cost>=0))
        return true;
    else
        return false;
}

bool Office::checkIfCustomerCanModifySalary(int balance,int salary,int newsalary)
{
    int a;
    a=balance-(salary-newsalary);
    if(a<0)
        return false;
    else
        return true;
}

void Office::setEmp(int id)
{
    if(checkIfCustomerOnList(id)==true)
    allcustomers->findCustomer(id)->setoldeEmp(1);
}

void Office::removeCustomerFromOffice(int id)
{
    if(checkIfCustomerOnList(id)==true)
    {
        customer *ptr2=allcustomers->findCustomer(id);
        employee *ptr3=allemployees->findEmployee(ptr2->getCurrent()->getID());
        ptr3->removeMyCustomer(id);
        allcustomers->removeCustomer(id);
    }
}

int Office::addCustomerToEmployye(int empID,int IDcard)
{
    if(checkIfCustomerOnList(IDcard)==true && checkIfEmployeeOnList(empID)==true)
     {
         employee *ptr1= allemployees->findEmployee(empID);
         customer *ptr2= allcustomers->findCustomer(IDcard);
         ptr2->setCurrent(ptr1);
         ptr1->addMyCustomer(ptr2);
         return 1;
     }
     else
        return 0;
}

bool Office::checkIFmployeeIsFree(int ID)
{
    if(checkIfEmployeeOnList(ID)==true)
        return allemployees->findEmployee(ID)->isLess();
    else
        return false;
}

void Office::printListOfEmployeesCustomers(int Id)
{
     if(checkIfEmployeeOnList(Id)==true)
     allemployees->findEmployee(Id)->printMyCustomers();
     else
     cout<<"this employee has no customers"<<endl;
}

 int Office::getOldEmp(int id)
 {
     if(checkIfCustomerOnList(id)==true)
     return allcustomers->findCustomer(id)->getOldEmp1();
     else
     return 0;
 }
 void Office::printCustomersEmployee(int id)
 {
     if(checkIfCustomerOnList(id)==true)
     allcustomers->findCustomer(id)->getCurrent()->print();
     else
     cout<<"no such employee on list"<<endl;

 }

 void Office::printNumberOfemployee()
 {
     cout<<"Number of employees "<<allemployees->getNumberofAllEmployee()<<endl;
 }



