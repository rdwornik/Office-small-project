### Office-small-project

## Description of the project

The main task of the project was to design the program which could allow user to manage the office.

* Project consists 4 classes: Office, ListCustomer, ListEmployee, Employee, and Customer. Office is
overriding class, which has bigger access than user to the rest of classes . The aim of Office is to manage
the employees and customers. Class Office is the interface where we can use whole office just by
recalling to that object.Class Employee and Customer are independent so removing any of them will not
provide deleting anything else.

* Office can do variable operations like adding, removing, finding and changing, coping and deleting

* Office can’t hire more than 5 employees. Employee can’t service more than 3 customers. Customer
can’t use service only from one employee from whole office.

* Office can’t add customer who has negative balance. (Balance is amount of money which user earn
subtracted by money he spend for services in other offices). Office have to check if he can add customer.
If it can add the customer it have to modify his balance by subtracting it by costs of the service.

* Customer can view the list of free employees and the one choose to service him. He can has only one
employee in one office. Office can reject his request because he can’t afford it.

* Customer can check his current balance. He can also change his salary if he started to earn more but
he have to inform every office which services he use that he earn more. He balance should be change
automatically.

* Customer can quit office in any time.

* Office can also fire his employees, but it can’t fire the employee if there is no other employees to take
his customers. If he can fire the employee it should search for employee which costs the same amount
of money if he will not find such one it should allocate the customer to more expensive employee of
course not decreasing the customers balance otherwise he allocate him in cheaper one.

* Customer can check who is his current employee from the given office.

* If customer want check who is his employee, but employee was already fired, customer should be
informed about that and know who is his new employee.

## Memory Map

![memorymap](https://user-images.githubusercontent.com/36505769/39305344-173151d0-495d-11e8-9964-cd040214c318.JPG)

## Testing

# Restrictions
# Class customer
* Customer can’t be added to the office with the same IDcard.
* Customer can’t be added to the office with negative balance.
* Customer can’t be added to the office if doesn’t afford chosen employee.
* Customer can’t be added to the employee who doesn’t exist.
* Customer can’t quit office that he not belongs to.
# Class Office
* Office cant’ add customer to employee that has more than 3 customers.
* Office can’t hire more than 5 employee.
* Office can’t fire employee if there is not enough employee take customers from fired employee.
* Office can’t hire two employees with the same ID.
* Office can’t fire employee that doesn’t exist.

# Testing scenarios
# Customer
* Show the list of free employers and check if they are really free.
* Choose employee from the office.
* Choose employee from the office that customer can’t afford. Program should inform customer
that he can’t afford the employee.
* Choose any employee in the office that customer already belongs to. Request should be
rejected.
* Check who is his employee in the chosen office.
* Check if customers was informed about some changes to employee.
* Modify salary and check the balance.
* Quit the office
* Quit the office that customer doesn’t belongs to.
# Office
* Hire employee.
* Hire two employee with the same ID.
* Hire more than 6 employee.
* Fire employee that not exist.
* Fire employee when there are no free employees.
* Fire employee that has customers and check every employee’s customers and see if there were
reallocated. Check if number of employees changed.

## Author
# Robert Dwornik
