#include <iostream>
#include <string.h>
 using namespace std;

 #include "ListCustomer.h"

 ListCustomer::ListCustomer()
 {
     head=NULL;
 }

 ListCustomer::~ListCustomer()
 {
customer *ptr=head;
    while (ptr)
    {

        ptr=ptr->getNext();
        delete head;
        head=ptr;
    }
    cout<<"list is deleted"<<endl<<endl<<endl;

 }

int ListCustomer::getnumOfCust()
{
   int cnt = 0;

    customer *curr = head;
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

int ListCustomer::add_Customer(string name,string surname,int IDcard, int salary,int balance)
{
 customer *current=head;
 customer *prev;

    while (current!=NULL)
    {
        if (IDcard ==current->getIDcard())  //check if there is agent with the same id
        {
            cout << "Error: Agent with this id already exists! Agent_id:" << IDcard<< endl << endl;
            return 0;
        }
        current=current->getNext();
    }
    current=head;

    customer *n;
    n=new customer(name,surname,IDcard,salary,balance);

    if (head!=NULL)
    {
        while (current!=NULL)
        {
            if (IDcard<current->getIDcard())  //to add before agent with bigger id
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
void ListCustomer::removeCustomer(int IDcard)
{
    customer *current=head;
    customer *prev=head;
    while (current!=NULL)
    {
        if (IDcard==current->getIDcard())
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

int ListCustomer::modifySalary(int IDcard,int salary)
{
customer *curr;
curr=head;

    while (curr !=NULL)
    {
        if(curr->getIDcard()==IDcard)
        {
        curr->setSalary(salary);
        return 1;

        }
    curr=curr->getNext();
    }
}

void ListCustomer::printListofCustomers()
{
     customer* curr=head;

    if(head==NULL)
        cout<<"list empty"<<endl;
    else
    {
        cout<<"the list of customers is"<<endl;
        while (curr!= NULL)
        {
        curr->print();
        curr=curr->getNext();
        }
    }
}
customer* ListCustomer::findCustomer(const int ID)
{
customer *curr=head;
customer *temp;


    while (curr !=NULL)
    {
        if(curr->getIDcard()==ID)
        {
            return curr;
        }
    curr=curr->getNext();
    }
}

 bool ListCustomer::checkIfCustomerOnList(int ID)
 {
customer *curr=head;
customer *temp;

    while (curr != NULL && curr->getIDcard()!= ID)
    {
        temp=curr;
        curr=curr->getNext();
    }
    if(curr==NULL)
        return false;
     else
        return true;

 }

