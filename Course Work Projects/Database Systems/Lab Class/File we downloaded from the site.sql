

/**************************
AUTO_CSOP tabla letrehozasa
**************************/
drop table CAR_CLASS;
-- 
create table CAR_CLASS(
car_class_name varchar2(6) not null,
km_fee number(3),
daily_fee number(5)
);
/**************************
AUTO_CSOP tabla feltoltese
**************************/
insert into CAR_CLASS values ('NORMAL','80','5000');
insert into CAR_CLASS values ('EXTRA','120','7500');
insert into CAR_CLASS values ('LUXURY','300','15000');
/*************************/
/*************************/

/**************************
TIPUSOK tabla letrehozasa
**************************/
drop table TYPES;
-- 
create table TYPES(
type_name varchar2(15) not null,
car_class_name varchar2(6),
descr varchar2(30),
service_km number(5)
);
/**************************
TIPUSOK tabla feltoltese
**************************/
insert into TYPES values ('FORD ESCORT','EXTRA','CL 1.8 DSL 5-A','15000');
insert into TYPES values ('RENAULT 19','EXTRA','RL 1.4 L KAT 3-A','5000');
insert into TYPES values ('RENAULT NEVADA','EXTRA','RTD 2.1 L KAT 5-','75000');
insert into TYPES values ('RENAULT LAGUNA','EXTRA','RT 2.0 L KAT 5-A','15000');
insert into TYPES values ('SKODA LX','NORMAL','FAVORIT 1.3 L KAT','5000');
insert into TYPES values ('SKODA CL','NORMAL','FAVORIT 1.3 L KAT COMFORT LINE','5000');
insert into TYPES values ('OPEL ASTRA','EXTRA','CL 1.6 I 5-A','10000');
insert into TYPES values ('OPEL VECTRA','LUXURY','TURBO 2.0 I 4-A','10000');
insert into TYPES values ('W VENTO CL','EXTRA','TD 1.9 L KAT','15000');
insert into TYPES values ('OPEL CORSA','NORMAL','CITY 1.2 I 3-A','10000');
insert into TYPES values ('RENAULT TWINGO','NORMAL','1.2 L KAT 3-A','75000');
insert into TYPES values ('RENAULT ESPACE','LUXURY','RN DT 2.1 L KAT','15000');
/*************************/
/*************************/

/**************************
AUTOK tabla letrehozasa
**************************/
drop table CARS;
-- 
create table CARS(
license_plate varchar2(7) not null,
type_name varchar2(15),
car_class_name varchar2(6),
buyiog_date date,
price number(10,2),
km_traveled number(6),
latest_service_km number(6),
condition varchar2(1),
department_code number(2),
employee_code number(4)
);
/**************************
AUTOK tabla feltoltese
**************************/
insert into CARS values ('ABR-047','FORD ESCORT','EXTRA',to_date('19930102','yyyymmdd'),'1300000','151003','141410','F',30,1236);
insert into CARS values ('ABR-115','RENAULT 19','EXTRA',to_date('19930102','yyyymmdd'),'1200000','145097','139600','X',20,1234);
insert into CARS values ('CDE-324','RENAULT NEVADA','EXTRA',to_date('19930601','yyyymmdd'),'2473000','42040','15901','F',20,1234);
insert into CARS values ('DHV-123','RENAULT LAGUNA','EXTRA',to_date('19930605','yyyymmdd'),'2346000','73621','53600','A',20,1245);
insert into CARS values ('PHD-100','RENAULT 19','EXTRA',to_date('19930630','yyyymmdd'),'1329000','151441','140507','X',20,1249);
insert into CARS values ('PHD-610','RENAULT NEVADA','EXTRA',to_date('19930720','yyyymmdd'),'2473000','39066','30009','F',20,1249);
insert into CARS values ('ABC-021','SKODA LX','NORMAL',to_date('19931001','yyyymmdd'),'827000','123212','120509','F',30,1236);
insert into CARS values ('ABC-022','SKODA CL','NORMAL',to_date('19931001','yyyymmdd'),'917000','97081','95310','S',30,1236);
insert into CARS values ('ABC-123','OPEL ASTRA','EXTRA',to_date('19931111','yyyymmdd'),'1239000','101978','93710','A',30,1236);
insert into CARS values ('BAH-115','OPEL VECTRA','LUXURY',to_date('19931011','yyyymmdd'),'3977000','51007','49620','A',50,1246);
insert into CARS values ('CIC-312','W VENTO CL','EXTRA',to_date('19931201','yyyymmdd'),'1650000','100021','83701','F',60,1241);
insert into CARS values ('COD-705','W VENTO CL','EXTRA',to_date('19931201','yyyymmdd'),'1650000','91970','79600','S',60,1241);
insert into CARS values ('CBN-301','OPEL CORSA','NORMAL',to_date('19931201','yyyymmdd'),'917000','28001','25444','A',60,1241);
insert into CARS values ('CBN-302','OPEL ASTRA','EXTRA',to_date('19931201','yyyymmdd'),'1239000','87111','80001','S',60,1241);
insert into CARS values ('CDD-115','FORD ESCORT','EXTRA',to_date('19940102','yyyymmdd'),'1400000','15901','15501','A',30,1236);
insert into CARS values ('DCD-324','RENAULT LAGUNA','EXTRA',to_date('19940102','yyyymmdd'),'2346000','41061','28861','A',20,1245);
insert into CARS values ('PDP-101','RENAULT ESPACE','LUXURY',to_date('19940102','yyyymmdd'),'3530000','7911',NULL,'S',20,1249);
insert into CARS values ('CBN-001','W VENTO CL','EXTRA',to_date('19940102','yyyymmdd'),'1999000','152311','150600','F',60,1241);
insert into CARS values ('CDD-115','RENAULT TWINGO','NORMAL',to_date('19940103','yyyymmdd'),'955000','8307',NULL,'S',20,1234);
/*************************/
/*************************/

/**************************
RENDELES tabla letrehozasa
**************************/
drop table ORDERS;
-- 
create table ORDERS
(
order_number varchar2(5) not null,
customer_number varchar2(3),
order_date date,
person_ordered varchar2(12),
rent_start date,
days number(3),
license_plate varchar2(7),
class_name varchar2(15),
km_start number(6),
km_finish number(6),
rent_fee number(8),
paid varchar2(1)
);
/**************************
RENDELES tabla feltoltese
**************************/
insert into ORDERS values ('12334','348',to_date('19931201','yyyymmdd'),'NAGY TIBORNE',to_date('19940401','yyyymmdd'),'5','ABC-123','OPEL ASTRA','95308','101978','558600','Y');
insert into ORDERS values ('12335','342',to_date('19940202','yyyymmdd'),'HOTEL CIVIS',to_date('19940305','yyyymmdd'),'2','ABR-115','RENAULT 19','144102','145097','134400','Y');
insert into ORDERS values ('12336','342',to_date('19940202','yyyymmdd'),'HOTEL CIVIS',to_date('19940202','yyyymmdd'),'21','PHD-100','RENAULT 19','150871','151441','225900','Y');
insert into ORDERS values ('12337','344',to_date('19940330','yyyymmdd'),'HILTON',to_date('19940405','yyyymmdd'),'30','ABR-047','FORD ESCORT','141413','151003','1375800','N');
insert into ORDERS values ('12338','343',to_date('19940330','yyyymmdd'),'MATAV IG.',to_date('19940405','yyyymmdd'),'5','ABC-123','OPEL ASTRA','101978','104965','395940','N');
insert into ORDERS values ('12339','348',to_date('19940402','yyyymmdd'),'APEH IG.',to_date('19940410','yyyymmdd'),'1','BAH-115','OPEL VECTRA','50609','51007','55260','N');
insert into ORDERS values ('12340','345',to_date('19940203','yyyymmdd'),'HOTEL CIVIS',to_date('19940501','yyyymmdd'),'5','ABR-047','FORD ESCORT','151003',NULL,NULL,'Y');
insert into ORDERS values ('12341','349',to_date('19940404','yyyymmdd'),'IBUSZ IG.',to_date('19940501','yyyymmdd'),'10','ABC-123','W VENTO CL','152311',NULL,NULL,'Y');
insert into ORDERS values ('12342','344',to_date('19940404','yyyymmdd'),'HILTON',to_date('19940502','yyyymmdd'),'5','PHD-610','RENAULT NEVADA','39066',NULL,NULL,'Y');
insert into ORDERS values ('12343','348',to_date('19940504','yyyymmdd'),'NAGY TIBORNE',to_date('19940410','yyyymmdd'),'7','CDE-324','RENAULT NEVADA','42040',NULL,NULL,'N');
insert into ORDERS values ('12344','343',to_date('19940420','yyyymmdd'),'KOOS TIBOR',to_date('19940503','yyyymmdd'),'10','ABC-123','SKODA LX','123212',NULL,NULL,'N');
insert into ORDERS values ('12345','342',to_date('19940421','yyyymmdd'),'HILTON',to_date('19940503','yyyymmdd'),'3','CIC-312','W VENTO CL','100021',NULL,NULL,'Y');
/*************************/
/*************************/

/**************************
UGYFELEK tabla letrehozasa
**************************/
drop table CUSTOMERS;
-- 
create table CUSTOMERS(
customer_number varchar2(3) not null,
customer_name varchar2(20),
address varchar2(15),
city varchar2(10),
country varchar2(10),
post_code varchar2(6),
contact varchar2(15),
payment_method varchar2(1)
);
/**************************
UGYFELEK tabla feltoltese
**************************/
insert into CUSTOMERS values ('342','MOLNAR PETER','HILTON PRK. 1.','NEW YORK','USA','49928','HILTON','K');
insert into CUSTOMERS values ('343','PAPP ROBERT','PIAC U. 10.','DEBRECEN','HUNGARY','4027','PINTER ATTILA','K');
insert into CUSTOMERS values ('344','ABEL ANETT','WIESZ STR 5','VIENNA','AUSTRIA','20800','HILTON','K');
insert into CUSTOMERS values ('345','TIBOR SMITH','LIGNOUN 15.','PARIS','FRANCE','140010','HOTEL CIVIS','A');
insert into CUSTOMERS values ('346','PAPP AGNES','VEZER U. 19.','DEBRECEN','HUNGARY','4032',NULL,'A');
insert into CUSTOMERS values ('347','BIRO KATALIN','TESSEDIK U. 6.','DEBRECEN','HUNGARY','4032',NULL,'A');
insert into CUSTOMERS values ('348','KISS VIKTORIA','FO U. 8.','BUDAPEST','HUNGARY','1221','NAGY TIBORNE','K');
insert into CUSTOMERS values ('349','LIGETI ZOLTAN','KIRALY U. 88.','BUDAPEST','HUNGARY','1239',NULL,'A');
insert into CUSTOMERS values ('350','TOTH KAROLYNE','DOMB U. 6.','BUDAPEST','HUNGARY','1260',NULL,'A');
/*************************/
/*************************/

/**************************
RESZLEG tabla letrehozasa
**************************/
drop table DEPARTMENT;
-- 
create table DEPARTMENT(
department_code number(2) not null,
department_name varchar2(20),
department_address varchar2(15)
);
/**************************
RESZLEG tabla feltoltese
**************************/
insert into DEPARTMENT values ('10','KOZPONT','BUDAPEST');
insert into DEPARTMENT values ('20','AUTO-RENAULT','BUDAPEST');
insert into DEPARTMENT values ('30','AUTO','GYOR');
insert into DEPARTMENT values ('50','LUXURY-AUTO','BUDAPEST');
insert into DEPARTMENT values ('60','AUTO','DEBRECEN');
insert into DEPARTMENT values ('70','TEHERAUTO','BUDAPEST');
/*************************/
/*************************/

/**************************
ALKALMAZOTT tabla letrehozasa
**************************/
drop table EMPLOYEE;
-- 
create table EMPLOYEE(
employee_code number(4) not null,
employee_name varchar2(20),
classification varchar2(16),
date_started date,
salary number(6),
premium number(6),
department_code number(2) not null
);
/**************************
ALKALMAZOTT tabla feltoltese
**************************/
insert into EMPLOYEE values ('1234','KOVACS','SALESMAN',to_date('19921210','yyyymmdd'),13000,4000,'20');
insert into EMPLOYEE values ('1235','MOLNAR','MECHANIC',to_date('19921218','yyyymmdd'),18000, NULL,'30');
insert into EMPLOYEE values ('1236','CSIKOS','SALESMAN',to_date('19930312','yyyymmdd'),13250,5000,'30');
insert into EMPLOYEE values ('1237','TOTH','EXAMINER',to_date('19930422','yyyymmdd'),20000, NULL,'20');
insert into EMPLOYEE values ('1238','NEMETH','DEPT_LEADER',to_date('19931128','yyyymmdd'),29000,14000,'30');
insert into EMPLOYEE values ('1239','SZABO','PRINCIPAL',to_date('19920501','yyyymmdd'),54000,75000,'10');
insert into EMPLOYEE values ('1240','BALOGH','MECHANIC',to_date('19920602','yyyymmdd'),22000,5000,'50');
insert into EMPLOYEE values ('1241','TRENCSENI','SALESMAN',to_date('19930620','yyyymmdd'),12100,7200,'60');
insert into EMPLOYEE values ('1244','KIRALY','EXAMINER',to_date('19930804','yyyymmdd'),21000,8000,'20');
insert into EMPLOYEE values ('1245','HERCEG','SALESMAN',to_date('19931112','yyyymmdd'),11000,6000,'20');
insert into EMPLOYEE values ('1246','BOGNAR','SALESMAN',to_date('19921008','yyyymmdd'),13000,6000,'50');
insert into EMPLOYEE values ('1247','HALASZ','MECHANIC',to_date('19930523','yyyymmdd'),21000,7000,'60');
insert into EMPLOYEE values ('1248','HORVAT','DEPT_LEADER',to_date('19931209','yyyymmdd'),25000,12000,'60');
insert into EMPLOYEE values ('1249','KISS','SALESMAN',to_date('19931223','yyyymmdd'),12500, 9500,'20');
/*************************/
/*************************/

commit;


