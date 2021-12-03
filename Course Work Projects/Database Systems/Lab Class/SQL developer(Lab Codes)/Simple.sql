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
      
--We create a new table called salary_over20k
CREATE TABLE salary_over20k(
employee_name,classification,salary,date_started)
AS SELECT employee_name,classification,salary,date_started FROM employee
WHERE salary>20000;

SELECT employee_name,classification,salary,date_started FROM employee
WHERE salary>20000;

--delete a table
DROP TABLE salary_over20k;

--create another table
CREATE TABLE salary_over20k_b(
e_name,classification,salary,date_started, dept_address)
AS SELECT employee_name,classification,salary,date_started, department_address FROM employee
NATURAL JOIN department WHERE salary>20000;

--AND another one with salary in USD
CREATE TABLE salary_over20k_c(
e_name,classification,salary_in_usd,date_started, dept_address)
AS SELECT employee_name,classification,ROUND((1.074 * salary), 2) salary_in_usd,date_started, department_address FROM employee
NATURAL JOIN department WHERE salary>20000;

--ADD a new column to the table
ALTER TABLE salary_over20k_c ADD (spouse VARCHAR(50));

--Remove a Column from the table
ALTER TABLE salary_over20k_c DROP COLUMN date_started;

ALTER TABLE salary_over20k_c MODIFY (e_name VARCHAR(90) NOT NULL);

ALTER TABLE salary_over20k_c ADD CONSTRAINT salary_checking CHECK (salary_in_usd > 10000);

--SAlary is not greater than 10k
--wont insert anything
INSERT INTO salary_over20k_c (e_name, classification, salary_in_usd, dept_address, spouse)
VALUES ('JOHN','DBA',9999,'DEBRECEN',NULL);

--name is null 
--wont insert anything
INSERT INTO salary_over20k_c (e_name, classification, salary_in_usd, dept_address, spouse)
VALUES ('NULL','DBA',10001,'DEBRECEN',NULL);

INSERT INTO salary_over20k_c (e_name, classification, salary_in_usd, dept_address, spouse)
VALUES ('JOHN','DBA',10001,'DEBRECEN',NULL);

UPDATE salary_over20k_c
SET spouse ='MARY'
WHERE e_name ='JOHN';--put mary as john wife

UPDATE salary_over20k_c
SET spouse =NULL
WHERE e_name ='JOHN';

UPDATE salary_over20k_c
SET salary_in_usd = 0
WHERE e_name ='JOHN';

CREATE TABLE employee_b{
employee_code NUMBER(4) PRIMARY KEY,
employee_name VARCHAR2(20) NOT NULL UNIQUE,
salary NUMBER(6)
};

INSERT INTO employee_b (employee_code,employee_name,salary)
VALUES (1234, 'STEVE',11000);

DELETE FROM employee_b
WHERE employee_code = 1234;

INSERT INTO employee_b(employee_code,employee_name,salary)
SELECT employee_code, employee_name, salary FROM employee;

DELETE FROM employee_b;

create sequence seq_employee_b_id
increment by 1
start with 1
maxvalue 9999 --no maxvalue
nocycle;--cycle

INSERT INTO employee_b (employee_code,employee_name,salary)
VALUES (seq_employee_b_id.nextval, 'STEVE',11000);

INSERT INTO employee_b (employee_code,employee_name,salary)
VALUES (seq_employee_b_id.nextval, 'JOHN',11000);

INSERT INTO employee_b (employee_code,employee_name,salary)
VALUES (seq_employee_b_id.nextval, 'PETER',11000);

SELECT seq_employee_b_id.currval FROM DUAL;
SELECT seq_employee_b_id.nextval FROM DUAL;

week 10. TOPICS: -- any, all, exist
--ANY and ALL can compare a single value with a list of values

SELECT 'true' AS isittrueOrNot 
FROM dual --is a default table in oracle and you can select things from
WHERE 5 > ANY(1,3,5,7);

SELECT 'true'  AS isittrueOrNot 
FROM dual 
WHERE 5 > ALL(1,3,5,7);

SELECT 'true'  AS isittrueOrNot 
FROM dual 
WHERE (5 > 1) AND (5>3) AND (5>5) AND (5>7);


--employess with the highest salary
SELECT * 
FROM employee
WHERE salary >= ALL (SELECT salary FROM employee);

--select employee with lowest salary
SELECT * 
FROM employee
WHERE salary <= ALL (SELECT salary FROM employee);

SELECT 'anything' FROM dual WHERE 1=1;

SELECT * 
FROM dual
WHERE EXISTS (SELECT 'anything' FROM dual WHERE 1=1);

SELECT 'anything' FROM dual WHERE 1>1;

SELECT * 
FROM dual
WHERE EXISTS (SELECT 'anything' FROM dual WHERE 1>1);
--if the select returns at least one row, then it is true




--select the departments having at least one employee
--with more salary than 12000
SELECT *
FROM department
WHERE EXISTS(
 SELECT * 
 FROM employee
 WHERE (employee.DEPARTMENT_CODE = department.DEPARTMENT_CODE)  
       AND (salary > 12000)
);

-- solve the same problem with joins
SELECT department.department_code, department_address, department_name
FROM department JOIN employee ON (department.DEPARTMENT_CODE=employee.department_code)
WHERE salary > 12000
GROUP BY department.department_code, department_address, department_name --we have to group by every coulumn we selected
HAVING COUNT (*) >= 1;-- it is not really needed

SELECT department.department_code, department_address, department_name
FROM department JOIN employee ON (department.DEPARTMENT_CODE=employee.department_code)
WHERE salary > 12000
GROUP BY department.department_code, department_address, department_name ;--we have to group by every coulumn we selected

-- solve it using nested selects
-- select the employee names and the department names they are working for
SELECT employee_name, ( SELECT department_name
                        FROM department WHERE department_code= employee.department_code  
)  AS DEPARTMENT_I_WORK
FROM employee;

SELECT employee_name, department_name
FROM employee JOIN department ON (employee.DEPARTMENT_CODE = department.DEPARTMENT_CODE);

--select the cars
--and the name of the department they belong to
--and the name of the responsible employee

SELECT license_plate,--1st column
(SELECT department_name 
FROM department
WHERE department_code = cars.department_code)  AS Dep_name,--2nd column
 (SELECT employee_name
  FROM employee
  WHERE employee_code= cars.employee_code) AS EMP_NAME-- 3rd column
  
  FROM cars;
  
--Select the departments
--where there is at least one car
--with more than 100000 km traveled
SELECT *
FROM department
WHERE EXISTS( SELECT * FROM cars
   WHERE (department.DEPARTMENT_CODE = cars.DEPARTMENT_CODE) AND (km_traveled > 100000));
   
--Select the departments
-- Where EVERY car
-- has more than 100000 kilometers traveled

SELECT *
FROM department
WHERE 100000 < ALL (
SELECT km_traveled
FROM cars
WHERE cars.DEPARTMENT_CODE = department.DEPARTMENT_CODE
);

--select the customers
--who have placed at least one order
--with rent fee more than 20000
SELECT *
FROM customers
WHERE EXISTS (
SELECT * FROM orders
WHERE (orders.CUSTOMER_NUMBER = customers.CUSTOMER_NUMBER) AND (orders.RENT_FEE > 20000));

/*We want to select the customers who have at least one order*/
SELECT *
FROM customers t1
WHERE(EXISTS (SELECT * FROM orders t2
              WHERE (t2.CUSTOMER_NUMBER=t1.customer_number)));
              
/*We want to select the customers who have at least one order and thier country is hungary*/
SELECT *
FROM customers t1
WHERE(EXISTS (SELECT * FROM orders t2
              WHERE (t2.CUSTOMER_NUMBER=t1.customer_number))) AND (country ='HUNGARY');
              
/*Select the departments where there is a car with more than 120000 km traveled*/
SELECT *
FROM DEPARTMENT t1
WHERE EXISTS(SELECT * 
              FROM CARS t2
              WHERE (t1.DEPARTMENT_CODE=t2.DEPARTMENT_CODE) AND (t2.KM_TRAVELED > 120000));
              
/*SELECT the departments where every car has more than 120000 km traveled*/
SELECT *
FROM department t1
WHERE (120000 < ALL(SELECT km_traveled --we use the ALL or ANY when we are comparing two statement, like we compare kmtraveled of all cars in t1 department with 120000
                    FROM cars t2
                    WHERE (t1.DEPARTMENT_CODE=t2.DEPARTMENT_CODE)
                    )
                    );
                    
/*SELECT the departments where every car has more than 120000 km traveled*/
SELECT *
FROM department t1 LEFT JOIN cars t3 ON (t1.DEPARTMENT_CODE=t3.DEPARTMENT_CODE)--we found out that the two rows actually had no cars
WHERE (120000 < ALL(SELECT km_traveled --we use the ALL or ANY when we are comparing two statement, like we compare kmtraveled of all cars in t1 department with 120000
                    FROM cars t2
                    WHERE (t1.DEPARTMENT_CODE=t2.DEPARTMENT_CODE)
                    )
                    );
                    
/*SELECT the departments where every car has more than 120000 km traveled*/
SELECT *
FROM department t1
WHERE (10000 < ALL(SELECT km_traveled --we use the ALL or ANY when we are comparing two statement, like we compare kmtraveled of all cars in t1 department with 120000
                    FROM cars t2
                    WHERE (t1.DEPARTMENT_CODE=t2.DEPARTMENT_CODE)
                    )
                    );
              
CREATE VIEW employee_over_20k AS
  SELECT employee_code, employee_name
  FROM employee;
  
SELECT * FROM employee_over_20k;

UPDATE employee
SET employee_name = 'HORVATH'
WHERE employee_name = 'HORVAT';

CREATE TABLE student
{
  student_id NUMBER (8) PRIMARY KEY,
  student_name VARCHAR2(127)
}
;

CREATE SEQUENCE student_seq
START WITH      1
INCREMENT BY    1
NOCYCLE;

DELETE FROM student;

INSERT INTO student (student_id, student_name) VALUES (student_seq.currval, 'BERKIN');
INSERT INTO student (student_id, student_name) VALUES (student_seq.nextval, 'SHAYAN');
INSERT INTO student (student_id, student_name) VALUES (student_seq.nextval, 'STEVE');
INSERT INTO student (student_id, student_name) VALUES (student_seq.nextval, 'OLEG');

INSERT INTO employee (employee_code,...) VALUES (student_seq.nextval,...);

--date type

--This is how you DON'T select dates
SELECT  employee_code, date_started
FROM employee;

--This is how you DO select dates
SELECT employee_code, to_char(date_started, 'YYYY-MM-DD')
FROM employee;

SELECT employee_code, to_char(date_started, 'DD Mon YYYY')
FROM employee;

SELECT employee_code, to_char(date_started, 'DD Mon YYYY')
FROM employee
WHERE employee_name = 'TOTH';

--select the current date
SELECT sysdate from dual;--not good
SELECT to_char(sysdate, 'YYYY-Month-DD') FROM dual;

drop table student;
create table student
(
  student_id NUMBER(8) PRIMARY KEY,
  student_name VARCHAR(127)
  date_of_birth DATE
)
;

INSERT INTO student (student_id, student_name, date_of_birth)
VALUES (student_seq.nextval, 'John', to_date('1990-01-01', 'YYYY-MM-DD'));

--select how many months is there between the sysdate and John's birthdate

SELECT months_between(sysdate, (SELECT date_of_birth FROM student WHERE student_name = 'John'))
FROM dual;

--select the departments where every employee started after 1983-01-01
SELECT *
FROM department t1
WHERE to_date('1993 01 01', 'YYYY MM DD') < ALL(
                SELECT date_started
                FROM employee t2
                WHERE (t1.department_code = t2.department_code)
                );
                
--select the orders that were placed after the last employee joined

SELECT *
FROM orders
WHERE order_date > (SELECT max(date_started) 
                    FROM employee);
              
--Select the departments, and select how many of thier employees
--joined after 1993-01-01
SELECT t1.department_code, (SELECT COUNT(t2.employee_code)
                            FROM employee t2
                            WHERE t2.department_code = t1.department_code) AS emp_after_93
FROM department t1;
