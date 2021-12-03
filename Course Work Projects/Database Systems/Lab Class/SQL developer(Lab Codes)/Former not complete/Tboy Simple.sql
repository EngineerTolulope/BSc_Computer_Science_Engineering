SELECT * FROM cars; 

SELECT km_traveled FROM cars;

SELECT km_traveled AS traveled FROM CARS;

SELECT km_traveled traveled FROM cars;

SELECT km_traveled AS "km traveled" FROM cars;

SELECT customer_name, city || ',' || address  FROM customers;

SELECT customer_name, city || ',' || address AS "CITY AND ADDRESS" FROM customers;--it joins the city and address together separated by ,

SELECT customer_name,contact
FROM customers
WHERE contact is NULL;

SELECT customer_name, NVL(contact, <empty>)--replaces null in the contaCT column with empty 
FROM customers;

SELECT customer_name
FROM customers
WHERE CUSTOMER_NAME LIKE 'PAPP %'; --  pattern matching % and _ --it looks for names starting with PAPP

SELECT km_traveled * 0.621371192 AS mile_traveled
FROM cars;

SELECT ROUND(km_traveled * 0.621371192, 2) AS mile_traveled-- the round function rounds it up to decimal places
FROM cars;

SELECT lower(type_name), 
        upper(type_name),
        initcap(type_name),
        lpad(type_name, 20, '_'),
        rpad(type_name, 20, '_'),
        substr(type_name, 2),
        substr(type_name,3,6)
FROM cars;

SELECT type_name,sum(price), min(price), max(price), round(avg(price),2), count(*)
FROM cars
GROUP BY type_name;

SELECT type_name,sum(price), min(price), max(price), round(avg(price),2), count(*)
FROM cars
WHERE (type_name LIKE 'OPEL %') OR (type_name LIKE 'FORD %')--LIKE checks for all type names that has OPEL or FORD
GROUP BY type_name;

SELECT type_name,sum(price), min(price), max(price), round(avg(price),2), count(*)
FROM cars
--WHERE (type_name LIKE 'OPEL %') OR (type_name LIKE 'FORD %')
GROUP BY type_name
HAVING min(price) >= 1000000;--we only use having when we have groups

SELECT type_name,sum(price), min(price), max(price), round(avg(price),2), count(*)
FROM cars
WHERE (type_name LIKE 'OPEL %') OR (type_name LIKE 'FORD %')
GROUP BY type_name
HAVING min(price) >= 1000000;-- We use HAVING command with Groups

SELECT count(price) --it counts the number of cars prices
FROM cars;

SELECT count(DISTINCT price)--it counts the number of  Unique cars prices
FROM cars;

SELECT condition, count(*)
FROM cars
--WHERE condition in ('A','F','S')
GROUP BY condition;

SELECT condition, count(*) AS "COUNT"
FROM cars
WHERE condition in ('A','F','S')
GROUP BY condition;

SELECT condition, count(*)
FROM cars
--WHERE condition in ('A','F','S')
GROUP BY condition
HAVING count(*) >=5;

/*Joining Tables*/

SELECT * FROM customers, orders;--we paired all the orders with every customer

SELECT * FROM orders;

SELECT * FROM customers, orders
WHERE customers.customer_number= orders.customer_number;--it only lists the pair if the order was placed by the customer

SELECT customers.customer_name,orders.order_number FROM customers, orders--we have only two columns because we selected only two
WHERE customers.customer_number= orders.customer_number;

SELECT * FROM orders inner join customers on (orders.customer_number = customers.CUSTOMER_NUMBER);--instead of using WHERE

SELECT * FROM orders left join customers on (orders.customer_number = customers.CUSTOMER_NUMBER);

SELECT * FROM orders right join customers on (orders.customer_number = customers.CUSTOMER_NUMBER);--the null values are at the end, null values says that the customers haven't placed an order yet

SELECT * FROM orders natural join customers; --the natural join can exempt this previous condition, it does it automatically if the columns have the same name

SELECT * FROM orders full outer join customers on (orders.CUSTOMER_NUMBER=customers.CUSTOMER_NUMBER);--Does the same as the right join

SELECT customers.customer_name,orders.order_number FROM customers JOIN orders ON (customers.customer_number = orders.customer_number);--we have only two columns because we selected only two

SELECT customers.customer_name,orders.order_number FROM orders left join customers on (orders.customer_number = customers.CUSTOMER_NUMBER);--All orders must have a customer that ordered it

SELECT customers.customer_name,orders.order_number FROM orders right join customers on (orders.customer_number = customers.CUSTOMER_NUMBER);--not all customers must place an order

SELECT *
FROM employee,DEPARTMENT;--we pair every employee row with every department row

SELECT employee_code,employee_name, department_name
FROM employee JOIN department ON (department.DEPARTMENT_CODE=employee.DEPARTMENT_CODE);

SELECT department.DEPARTMENT_CODE, department_name, count(employee_code)
FROM employee JOIN department ON (department.DEPARTMENT_CODE = employee.DEPARTMENT_CODE)
GROUP BY DEPARTMENT.DEPARTMENT_CODE, department_name;--in department code 10 we group all in one and count the number in it, instead of writting all over again

SELECT e1.employee_name, e2.employee_name ,e1.salary , e2.salary--we create two object for the employee table so we can get each customer if it earns less money than the other
FROM employee e1, employee e2 --Now we have two tables referrence e1 and e2
WHERE (e1.salary < e2. salary);

SELECT * from CUSTOMERS WHERE contact is null;

SELECT * from CUSTOMERS WHERE contact is not null;

SELECT customer_name, NVL(contact, '<empty>') from CUSTOMERS;

SELECT license_plate, DECODE(condition, 'A','Acceptable', 'S', 'Super', 'X', 'So bad')-- we replace condition A with acceptable, S with Super, X with so bad
FROM cars;


/*select name of employee 
who have the same classification and salary as Bognar*/

SELECT employee_name
FROM employee
WHERE (classification, salary)=(SELECT classification, salary
FROM employee
WHERE employee_name = 'BOGNAR');

-----select the orders, where the ordered car has more km traveled than the average
--Get the averagenkm travelled
SELECT AVG(km_traveled)
FROM cars;
-- How get the cars with more km travelled than the average
SELECT license_plate FROM cars where KM_TRAVELED > (SELECT AVG(km_traveled)
FROM cars);
--Finally we get the orders, where the ordered car
--has one the lincense plate selected above

SELECT *
FROM orders
WHERE license_plate IN (SELECT license_plate FROM cars where KM_TRAVELED > (SELECT AVG(km_traveled)
FROM cars));

/*select the name and classification of employee who have the same classification as herceg*/
--first we get herceg classification
SELECT classification FROM employee
WHERE (employee_name = 'HERCEG');
--so we select the employee's with herceg's classification
SELECT employee_name,classification FROM employee
WHERE classification in (SELECT classification FROM employee
                         WHERE (employee_name = 'HERCEG')
                         )
;

/*SELECT the employee who has more salary than molnar and same classification as toth*/
--first we get molnar salary
SELECT salary FROM employee WHERE employee_name ='MOLNAR';
--we get toth classification
SELECT classification FROM employee where employee_name ='TOTH';
--finally, we put them together
SELECT *
FROM employee
WHERE (salary > (SELECT salary FROM employee WHERE employee_name ='MOLNAR'))AND 
      (classification =(SELECT classification FROM employee where employee_name ='TOTH'));