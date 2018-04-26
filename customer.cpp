#include <iostream>
#include<string>
#include<string.h>
using namespace std;

#include "customer.h"

customer::customer(string Name,string Surname,int IDcard,int salary,int balance)
{
    oldEmp=0;
    oldbalnce=0;

    this->salary=salary;
    this->IDcard=IDcard;
    this->balance=balance;
    this->Name=Name;
    this->oldbalnce=oldbalnce;
    this->Surname=Surname;
    this->next=NULL;

}
customer::~customer()
{
    cout<<"delete customer"<<endl;
    this->current=NULL;
}

customer* customer::getNext()
{
    return next;
}

void customer::setNext(customer *n)
{
    next=n;
}
void customer::setCurrent(employee *curr)
{
    current=curr;
}
void customer::setoldeEmp(int n)
{
    oldEmp=n;
}

void customer::setBalance(int n)
{
    balance=n;
}

void customer::setOldbalance(int n)
{
    oldbalnce=n;
}

void customer::setSalary(int n)
{
    salary=n;
}

employee* customer::getCurrent()
{
    return current;
}
int customer::getOldEmp1()
{
    return oldEmp;
}
string customer::getName()
{
 return Name;
}

string customer::getSurname()
{
 return Surname;
}

int customer::getIDcard()
{
return IDcard;
}
int customer::getOldbalance()
{
return oldbalnce;
}


int customer::getSalary()
{
    return salary;
}

int customer::getBalance()
{
    return balance;
}

void customer::modifySalary(Office *Offname,int newSalary)
{
    if(Offname->checkIfCustomerOnList(this->IDcard)==true)
    {

        if(Offname->checkIfCustomerCanModifySalary(this->balance,Offname->findCustomer(this->IDcard)->getSalary(),newSalary)==true)
        {
        setBalance(this->balance+(newSalary-this->salary));
        Offname->modifySalary(this->IDcard,newSalary);
        setSalary(newSalary);
        cout<<"Your salary is modified"<<endl;
        }
        else
        {
        cout<<"You can't afford to be in office: "<<Offname->getofficeName()<<" anymore"<<endl;
        setSalary(newSalary);
        setBalance(getBalance()+Offname->findCustomer(this->getIDcard())->getCurrent()->getcost());
        Offname->removeCustomerFromOffice(this->IDcard);
        }

    }
    else
     cout<<"You are not a client of this office"<<endl;
}

void customer::choseOfficeandEmployee(Office *Offname,int ID)
{
   if(Offname->checkIfEmployeeOnList(ID)==true)
        {
            if(Offname->checkIfCustomerCanAfford(this->balance,Offname->findEmployee(ID)->getcost())==true)
                {
                    if( Offname->checkIFmployeeIsFree(ID)==true)
                    {

                             Offname->add_Customer(this->Name,this->Surname,this-> IDcard,this->salary,this->balance);
                             Offname->addCustomerToEmployye(ID,this->IDcard);
                             setBalance(getBalance()-Offname->findEmployee(ID)->getcost());
                             setOldbalance(Offname->findEmployee(ID)->getcost());
                            cout<<"Welcome!!! You are successfully added to our office."<<endl;
                    }
                    else
                    cout<<"Employee with ID: "<<ID<<" not available "<<endl;
                    }
                  else
                  cout<<"Unfortunately you can't join office becouse you can't afford it"<<endl;
                }
                else
                cout<<"Employee with ID: "<<ID<<" not on the list "<<endl;
}




void customer::leaveOffice(Office *offname)
{
    if(offname->checkIfCustomerOnList(this->getIDcard())==true)
    {
    if(offname->findCustomer(this->IDcard)->getOldEmp1()!=1)
    {
        setBalance(getBalance()+offname->findCustomer(this->getIDcard())->getCurrent()->getcost());
        offname->removeCustomerFromOffice(this->IDcard);
        cout<<"you left the office:"<<offname->getofficeName()<<endl;
    }
    else
    {
        setBalance(getBalance()+oldbalnce);
        offname->removeCustomerFromOffice(this->IDcard);
        cout<<"you left the office:"<<offname->getofficeName()<<endl;
    }
    }
    else
    cout<<"You have no employee in this office"<<endl;

}

void customer::printmyEmployee(Office *offname)
{
if(offname->checkIfCustomerOnList(this->getIDcard())==true)
    {
        if(offname->getOldEmp(this->IDcard)!=1)
     {
         cout<<"Your Employee is: ";
         offname->findCustomer(this->getIDcard())->current->print();
     }
    else
     {
         cout<<"We had to change your Employee. Your new Employee is: ";
         offname->printCustomersEmployee(this->IDcard);
     }

    }
else
cout<<"You have no employee in this office"<<endl;
}

void customer::checkMybalance()
{
 cout <<"Your Balance is: "<<getBalance()<<endl;
}

void customer::checkSalary()
{
 cout <<"Your salary is: "<<getSalary()<<endl;
}


void customer::showMeListoffreeEmployee(Office* Offname)
{
    Offname->printListofFreeEmployee();
}

void customer::print()
{
    cout <<"Customer: "<<this->Name <<" "<<this->Surname<<" "<<this->IDcard<<" "<<this->salary<<" "<<this->balance<<endl;
}
