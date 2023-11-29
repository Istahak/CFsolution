-- Inserting data into the employees table - Row 1
INSERT INTO employees (employee_id, first_name, last_name, birth_date, gender, employee_type, join_date, salary, phone_number, email, address)
VALUES
  (1, 'Rahim', 'Islam', '1990-05-15', 'Male', 'Manager', '2010-01-15', 20000.00, 01723129630, 'rahim.islam@gmail.com', 'Dhaka');

-- Inserting data into the employees table - Row 2
INSERT INTO employees (employee_id, first_name, last_name, birth_date, gender, employee_type, join_date, salary, phone_number, email, address)
VALUES
  (2, 'Jamal', 'Uddin', '1985-08-22', 'Male', 'SeniorSalyer', '2015-03-10', 15000.00, 01723129631, 'jamal.uddin@gmail.com', 'Dhaka');

-- Inserting data into the employees table - Row 3
INSERT INTO employees (employee_id, first_name, last_name, birth_date, gender, employee_type, join_date, salary, phone_number, email, address)
VALUES
  (3, 'Rifat', 'Khan', '1992-11-30', 'Male', 'SeniorSalyer', '2015-07-01', 15000.00, 01723129632, 'Rifat.Khan@gmail.com', 'Dhaka');

-- Inserting data into the employees table - Row 4
INSERT INTO employees (employee_id, first_name, last_name, birth_date, gender, employee_type, join_date, salary, phone_number, email, address)
VALUES
  (4, 'Abdullah_Al', 'Tanzim', '1988-04-18', 'Male', 'JuniorSalyer', '2017-09-05', 12000.00, 01723129633, 'abdullahal.tanzim@gmail.com', 'Dhaka');

-- Inserting data into the employees table - Row 5
INSERT INTO employees (employee_id, first_name, last_name, birth_date, gender, employee_type, join_date, salary, phone_number, email, address)
VALUES
  (5, 'Farhan', 'Expert', '1995-02-12', 'Male', 'Intern', '2021-02-01', 5000.00, 01723129634, 'farhan.expert@gmail.com', 'Dhaka');



-- Inserting data into the customers table - Row 1
INSERT INTO customers (customer_id, first_name, last_name, age, gender, phone_number, email)
VALUES
  (1, 'Tanmoy', NULL, 25, 'Male', 1723129645, 'Tanmoy@gmail.com');

-- Inserting data into the customers table - Row 2
INSERT INTO customers (customer_id, first_name, last_name, age, gender, phone_number, email)
VALUES
  (2, 'Afia', NULL, 21, 'Female', 1723129646, 'Afia@gmail.com');

-- Inserting data into the customers table - Row 3
INSERT INTO customers (customer_id, first_name, last_name, age, gender, phone_number, email)
VALUES
  (3, 'Dipto', NULL, 23, 'Male', 1723129647, 'Dipto@gmail.com');

-- Inserting data into the customers table - Row 4
INSERT INTO customers (customer_id, first_name, last_name, age, gender, phone_number, email)
VALUES
  (4, 'Nahid', NULL, 18, 'Male', 1723129648, 'Nahid@gmail.com');

-- Inserting data into the customers table - Row 5
INSERT INTO customers (customer_id, first_name, last_name, age, gender, phone_number, email)
VALUES
  (5, 'Labib', NULL, 22, 'Male', 1723129649, 'Labib@gmail.com');


-- Inserting data into the medicines table - Row 1
INSERT INTO medicines (medicine_id, medicine_name, location_rack)
VALUES (1, 'Maxpro', 101);

-- Inserting data into the medicines table - Row 2
INSERT INTO medicines (medicine_id, medicine_name, location_rack)
VALUES (2, 'Napa Extra', 102);

-- Inserting data into the medicines table - Row 3
INSERT INTO medicines (medicine_id, medicine_name, location_rack)
VALUES (3, 'Ceevit', 103);

-- Inserting data into the medicines table - Row 4
INSERT INTO medicines (medicine_id, medicine_name, location_rack)
VALUES (4, 'Sergel', 101);

-- Inserting data into the medicines table - Row 5
INSERT INTO medicines (medicine_id, medicine_name, location_rack)
VALUES (5, 'Fexo', 105);

-- Inserting data into the medicine_details table - Row 1
INSERT INTO medicine_details (MED_DETAILS_ID, medicine_id, COMPANY_NAME, DISEASE_TREATED, GENERIC_TYPE)
VALUES (1, 1, 'Renata Limited', 'Gastroesophageal', 'Esomeprazole Magnesium Trihydrate');

-- Inserting data into the medicine_details table - Row 2
INSERT INTO medicine_details (MED_DETAILS_ID, medicine_id, COMPANY_NAME, DISEASE_TREATED, GENERIC_TYPE)
VALUES (2, 2, 'Beximco Pharmaceuticals Ltd.', 'Fever', 'Paracetamol + Caffeine');

-- Inserting data into the medicine_details table - Row 3
INSERT INTO medicine_details (MED_DETAILS_ID, medicine_id, COMPANY_NAME, DISEASE_TREATED, GENERIC_TYPE)
VALUES (3, 3, 'Square Pharmaceuticals Ltd.', 'Vitamin C Deficiency', 'Vitamin C [Ascorbic acid]');

-- Inserting data into the medicine_details table - Row 4
INSERT INTO medicine_details (MED_DETAILS_ID, medicine_id, COMPANY_NAME, DISEASE_TREATED, GENERIC_TYPE)
VALUES (4, 4, 'Healthcare Pharmacuticals Ltd.', 'Gastroesophageal', 'Esomeprazole Magnesium Trihydrate');

-- Inserting data into the medicine_details table - Row 5
INSERT INTO medicine_details (MED_DETAILS_ID, medicine_id, COMPANY_NAME, DISEASE_TREATED, GENERIC_TYPE)
VALUES (5, 5, 'Square Pharmaceuticals Ltd.', 'Allergies', 'Fexofenadine Hydrochloride');


-- Inserting data into the suppliers table - Row 1
INSERT INTO suppliers (supplier_id, supplier_name, supplier_company_name, supplier_address, supplier_phone_number, supplier_email)
VALUES (1, 'Turjo','Renata Limited', 'Dhaka', 01734529654, 'Turjo@gmail.com');

-- Inserting data into the suppliers table - Row 2
INSERT INTO suppliers (supplier_id, supplier_name, supplier_company_name, supplier_address, supplier_phone_number, supplier_email)
VALUES (2, 'Shafin', 'Beximco Pharmaceuticals Ltd.', 'Dhaka', 01723429643, 'Shafin@gmail.com');

-- Inserting data into the suppliers table - Row 3
INSERT INTO suppliers (supplier_id, supplier_name, supplier_company_name, supplier_address, supplier_phone_number, supplier_email)
VALUES (3, 'Asif', 'Square Pharmaceuticals Ltd.', 'Dhaka', 01723429641, 'Asif@gamil.com');

-- Inserting data into the suppliers table - Row 4
INSERT INTO suppliers (supplier_id, supplier_name, supplier_company_name, supplier_address, supplier_phone_number, supplier_email)
VALUES (4, 'Shakib', 'Healthcare Pharmacuticals Ltd.', 'Dhaka',01723426542, 'Shakib@gmail.com');

-- Inserting data into the suppliers table - Row 5
INSERT INTO suppliers (supplier_id, supplier_name, supplier_company_name, supplier_address, supplier_phone_number, supplier_email)
VALUES (5, 'Hasib', 'Square Pharmaceuticals Ltd.', 'Dhaka', 01723529876, 'Hasib@gmail.com');



-- Inserting data into the purchases table - Row 1
INSERT INTO purchases (purchase_id, supplier_id, medicine_id, quantity, cost, purchase_date)
VALUES (1, 1, 1, 100, 630.00, '2023-01-15');

-- Inserting data into the purchases table - Row 2
INSERT INTO purchases (purchase_id, supplier_id, medicine_id, quantity, cost, purchase_date)
VALUES (2, 2, 2, 50, 112.5, '2023-02-20');

-- Inserting data into the purchases table - Row 3
INSERT INTO purchases (purchase_id, supplier_id, medicine_id, quantity, cost, purchase_date)
VALUES (3, 3, 3, 200, 350.00, '2023-03-10');

-- Inserting data into the purchases table - Row 4
INSERT INTO purchases (purchase_id, supplier_id, medicine_id, quantity, cost, purchase_date)
VALUES (4, 4, 4, 75, 472.50, '2023-04-05');

-- Inserting data into the purchases table - Row 5
INSERT INTO purchases (purchase_id, supplier_id, medicine_id, quantity, cost, purchase_date)
VALUES (5, 3, 5, 120, 972.00, '2023-05-12');



-- Inserting data into the sales table - Row 1
INSERT INTO sales (sale_id, customer_id, sale_date, sale_time, total_amount, employee_id)
VALUES (1, 1, '2023-01-20', '2023-01-20 14:30:00', 63.00, 1);

-- Inserting data into the sales table - Row 2
INSERT INTO sales (sale_id, customer_id, sale_date, sale_time, total_amount, employee_id)
VALUES (2, 2, '2023-02-15', '2023-02-15 10:45:00', 63.00, 1);

-- Inserting data into the sales table - Row 3
INSERT INTO sales (sale_id, customer_id, sale_date, sale_time, total_amount, employee_id)
VALUES (3, 3, '2023-03-08', '2023-03-08 18:20:00', 8.75, 3);

-- Inserting data into the sales table - Row 4
INSERT INTO sales (sale_id, customer_id, sale_date, sale_time, total_amount, employee_id)
VALUES (4, 4, '2023-04-12', '2023-04-12 12:15:00', 49.00, 4);

-- Inserting data into the sales table - Row 5
INSERT INTO sales (sale_id, customer_id, sale_date, sale_time, total_amount, employee_id)
VALUES (5, 5, '2023-05-25', '2023-05-25 16:00:00', 177.75, 5);


-- Inserting data into the sales_items table - Row 1
INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (1, 1, 10, 6.30);

-- Inserting data into the sales_items table - Row 2
INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (2, 1, 10, 6.30);

-- Inserting data into the sales_items table - Row 3
INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (3, 3, 5, 1.75);

-- Inserting data into the sales_items table - Row 4
INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (4, 4, 5, 6.30);

-- Inserting data into the sales_items table - Row 5
INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (4, 3, 10, 1.75);

INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (5, 5, 10, 8.10);

INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (5, 1, 10, 6.30);

INSERT INTO sales_items (sale_id, medicine_id, sale_quantity, total_price)
VALUES (5, 2, 15, 2.25);


-- Inserting data into the medicine_storage table - Row 1
INSERT INTO medicine_storage (STORE_ID, medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
VALUES (1, 1, 1, 100, 6.30, '2023-12-01');

-- Inserting data into the medicine_storage table - Row 2
INSERT INTO medicine_storage (STORE_ID, medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
VALUES (2, 2, 2, 50, 2.25, '2023-11-15');

-- Inserting data into the medicine_storage table - Row 3
INSERT INTO medicine_storage (STORE_ID, medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
VALUES (3, 3, 3, 200, 1.75, '2024-01-10');

-- Inserting data into the medicine_storage table - Row 4
INSERT INTO medicine_storage (STORE_ID, medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
VALUES (4, 4, 4, 75, 6.30, '2023-09-30');

-- Inserting data into the medicine_storage table - Row 5
INSERT INTO medicine_storage (STORE_ID, medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
VALUES (5, 5, 5, 120, 8.10, '2023-12-15');



-- Inserting data into the salary_payments table - Row 1
INSERT INTO salary_payments (payment_id, employee_id, payment_month, payment_date, amount)
VALUES (1, 1, '2023-01-01', '2023-01-15', 20000.00);

-- Inserting data into the salary_payments table - Row 2
INSERT INTO salary_payments (payment_id, employee_id, payment_month, payment_date, amount)
VALUES (2, 2, '2023-01-01', '2023-01-15', 15000.00);

-- Inserting data into the salary_payments table - Row 3
INSERT INTO salary_payments (payment_id, employee_id, payment_month, payment_date, amount)
VALUES (3, 3, '2023-01-01', '2023-01-15', 15000.00);

-- Inserting data into the salary_payments table - Row 4
INSERT INTO salary_payments (payment_id, employee_id, payment_month, payment_date, amount)
VALUES (4, 4, '2023-01-01', '2023-01-15', 12000.00);

-- Inserting data into the salary_payments table - Row 5
INSERT INTO salary_payments (payment_id, employee_id, payment_month, payment_date, amount)
VALUES (5, 5, '2023-01-01', '2023-01-15', 5000.00);
