#include <iostream>
#include<string.h>
#include<vector>
#include <algorithm>

using namespace std;

#include "Employee.h"
#include "ListCustomer.h"
employee::employee(string name, string surname,int cost,int ID)
{
    this->cost=cost;
    this->ID=ID;
    this->Name=name;
    this->Surname=surname;
    this->next=NULL;
}

employee::~employee()
{
    cout<<"delete employee"<<endl;
    this->removeALLmyCustomers();
}

employee* employee::getNext()
{
    return next;
}

void employee::setNext(employee *n)
{
    next=n;
}

string employee::getName()
{
    return Name;
}

string employee::getSurname()
{
    return Surname;
}

int employee::getID()
{
    return ID;
}

int employee::getcost()
{
    return cost;
}

int employee::numberOfmyCus()
{
    numberOfCus=myCust.size();
    return numberOfCus;
}


void employee::addMyCustomer(customer *ptr)
{
myCust.push_back(ptr);
}

void employee::removeMyCustomer(int id)
{
for (int y=0;y<myCust.size();y++)
{
    if(myCust[y]->getIDcard()==id)
    {
    myCust.erase(myCust.begin()+y);
    }
}
}

customer* employee::getMyCustomer(int i)
{
    return myCust[i];
}

void employee::printMyCustomers()
{
 int i;
 if(myCust.size()!=0)
 {
 cout<<"your customers are:"<<endl;
 for(i=0;i<myCust.size();i++)
    myCust[i]->print();
 }
 else
  cout<<"you have no customers"<<endl;

}

void employee::removeALLmyCustomers()
{

  myCust.clear();
  cout<<"you have no customers"<<endl;
}

bool employee::isLess()
{
    if(myCust.size()<MAX)
        return true;
    else
        return false;
}

void employee::print()
{
    cout <<this->Name <<" "<<this->Surname<<" "<<this->cost<<" "<<this->ID<<endl;
}
