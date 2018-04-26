#include <iostream>
#include<string>
#include<string.h>
#include<list>
using namespace std;

#include "ListEmployee.h"

 ListEmployee::ListEmployee()
 {
     head=NULL;
 }

 ListEmployee::~ListEmployee()
 {
   employee *ptr=head;
    while (ptr)
    {

        ptr=ptr->getNext();
        delete head;
        head=ptr;
    }
    cout<<"list is deleted"<<endl<<endl<<endl;
 }

 int  ListEmployee::getNumberofAllEmployee()
 {
    int cnt=0;

    employee *curr = head;
    if(curr==NULL)
        return cnt;
    else
    {
        while (curr != NULL)
    {
       cnt++;
       curr=curr->getNext();
    }
    return cnt;
    }
 }


 int ListEmployee::hire_Employee(string name,string surname,int cost, int ID)
 {

    employee *current=head;
    employee *prev;

    employee *n;
    n=new employee(name,surname,cost,ID);

    if (head!=NULL)
    {
        while (current!=NULL)
        {
            if (ID<current->getID())  //to add before agent with bigger id
            {
                if (current==head)  //if it is before head
                {
                    n->setNext(head);
                    head=n;
                    return 1;
                }
                else
                {
                    n->setNext(current);
                    prev->setNext(n);
                    return 1;
                }
            }
            if (current->getNext()==NULL)    //to add if it is last element
            {
                current->setNext(n);
                n->setNext(NULL);
                return 1;
            }
            prev=current;
            current=current->getNext();
        }
    }
    else if (head==NULL)  //to add first element
    {
        n->setNext(head);
        head=n;
        return 1;
    }
    return 0;
}


  void ListEmployee::removeEmployee(int ID)
 {
    employee *current=head;
    employee *prev=head;
    while (current!=NULL)
    {
        if (ID==current->getID())
        {
            if (current==head)
            {
                head=current->getNext();
                delete current;
                return;
            }
            else
            {
                prev->setNext(current->getNext());
                delete current;
                return;
            }
        }
        prev=current;
        current=current->getNext();
    }
 }


  void ListEmployee::printListofEmployee()
 {
      employee* curr=head;

    if(head==NULL)
        cout<<"No employee hired"<<endl;
    else
    {
        cout<<"The list of employees is:"<<endl;
        while (curr!= NULL)
        {

        curr->print();
        curr=curr->getNext();
        }
    }
  }

  void ListEmployee::printListofFREEemployee()
  {
    employee* curr=head;

    if(head==NULL)
        cout<<"No Free Employee (empty list)"<<endl;
    else
    {
        cout<<"The list of FREE employees is:"<<endl;
        while (curr!= NULL)
        {
            if(curr->isLess()==true)
            curr->print();

        curr=curr->getNext();
        }
    }
  }

  employee* ListEmployee::getFreeEmployee(int cost,int ID)
  {
      employee *curr=head;
      employee *temp;
      employee *free;


            do{

            if(curr->getID()!=ID && curr->getcost()==cost && curr->isLess()==true)
            return curr;
            else
            curr=curr->getNext();
            }while(curr!=NULL);
                if(curr==NULL)
                    {
                            curr=head;
                            do{
                                 if(curr->getID()!=ID && curr->getcost()>cost && curr->isLess()==true)
                                    return curr;
                                    else
                                    curr=curr->getNext();
                            }while(curr!=NULL);
                            if(curr==NULL)
                            {
                                curr=head;
                                do{
                                    if(curr->getID()!=ID && curr->isLess()==true)
                                    return curr;
                                    else
                                    curr=curr->getNext();
                                    }while(curr!=NULL);
                                return curr;
                            }
                            else
                            return curr;
                    }
                else
                    return curr;
  }

  employee* ListEmployee::findEmployee(int ID)
  {
    employee *curr=head;
    while (curr !=NULL)
    {
        if(curr->getID()==ID)
        {
            return curr;
        }
    curr=curr->getNext();
    }
  }

  bool ListEmployee::checkIfemployeeOnList(int ID)
{
employee *curr=head;
employee *temp;

    while (curr != NULL && curr->getID()!= ID)
    {
        temp=curr;
        curr=curr->getNext();
    }
    if(curr==NULL)
        return false;
     else
        return true;

}

bool ListEmployee::checkNumberOFemp()
{
    if(getNumberofAllEmployee()<MAX)
        return true;
    else
        return false;
}







