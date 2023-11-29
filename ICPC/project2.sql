-- Employee Table
CREATE TABLE employees (
    employee_id INT(7) NOT NULL,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30),
    birth_date DATE NOT NULL,
    gender VARCHAR(6) NOT NULL,
    employee_type VARCHAR(20) NOT NULL,
    join_date DATE NOT NULL,
    salary DECIMAL(8,2) NOT NULL,
    phone_number BIGINT(10) NOT NULL,
    email VARCHAR(40),
    address VARCHAR(40),
    PRIMARY KEY (employee_id)
);

-- Customer Table
CREATE TABLE customers (
    customer_id INT(6) NOT NULL,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30),
    age INT(11) NOT NULL,
    gender VARCHAR(6) NOT NULL,
    phone_number BIGINT(10) NOT NULL,
    email VARCHAR(40),
    PRIMARY KEY (customer_id),
    UNIQUE KEY customers_phone_number_unique (phone_number),
    UNIQUE KEY customers_email_unique (email)
);

-- Meds Table
CREATE TABLE medicines (
    medicine_id INT(6) NOT NULL,
    medicine_name VARCHAR(50) NOT NULL,
    location_rack INT(5),
    PRIMARY KEY (medicine_id)
);

-- Medicine Details Table with Generic Type Column
CREATE TABLE medicine_details (
    MED_DETAILS_ID INT(6) NOT NULL,
    medicine_id INT(6) NOT NULL,
    COMPANY_NAME VARCHAR(50),
    DISEASE_TREATED VARCHAR(100),
    GENERIC_TYPE VARCHAR(50), 
    PRIMARY KEY (MED_DETAILS_ID),
    CONSTRAINT medicine_details_fk_medicines FOREIGN KEY (medicine_id) REFERENCES medicines(medicine_id)
);

CREATE TABLE suppliers (
    supplier_id INT(3) NOT NULL,
    supplier_name VARCHAR(25) NOT NULL,
    supplier_company_name VARCHAR(50) NOT NULL,
    supplier_address VARCHAR(30) NOT NULL,
    supplier_phone_number BIGINT(10) NOT NULL,
    supplier_email VARCHAR(40) NOT NULL,
    PRIMARY KEY (supplier_id)
);



-- Purchase Table
CREATE TABLE purchases (
    purchase_id INT(6) NOT NULL,
    supplier_id INT(6) NOT NULL,
    medicine_id INT(6) NOT NULL,
    quantity INT(11) NOT NULL,
    cost DECIMAL(8,2) NOT NULL,
    purchase_date DATE NOT NULL,
    PRIMARY KEY (purchase_id, medicine_id),
    KEY purchases_fk_suppliers (supplier_id),
    KEY purchases_fk_medicines (medicine_id),
    CONSTRAINT purchases_fk_suppliers FOREIGN KEY (supplier_id) REFERENCES suppliers (supplier_id),
    CONSTRAINT purchases_fk_medicines FOREIGN KEY (medicine_id) REFERENCES medicines (medicine_id)
);


-- Medicine Storage Table
CREATE TABLE medicine_storage (
    STORE_ID INT(10) NOT NULL,
    medicine_id INT(6) NOT NULL,
    PURCHASE_ID INT(4) NOT NULL,
    MED_QTY INT(11) NOT NULL,
    MED_PRICE DECIMAL(6, 2) NOT NULL,
    EXP_DATE DATE,
    PRIMARY KEY (STORE_ID),
    KEY medicine_storage_fk_meds (MED_ID),
    KEY medicine_storage_fk_purchase (PURCHASE_ID),
    CONSTRAINT medicine_storage_fk_meds FOREIGN KEY ( medicine_id) REFERENCES medicines (medicine_id),
    CONSTRAINT medicine_storage_fk_purchase FOREIGN KEY (PURCHASE_ID) REFERENCES purchases (purchase_id)
);

-- Sales Table
CREATE TABLE sales (
    sale_id INT(11) NOT NULL,
    customer_id INT(6) NOT NULL,
    sale_date DATE,
    sale_time TIMESTAMP,
    total_amount DECIMAL(8,2),
    employee_id INT(7) NOT NULL,
    PRIMARY KEY (sale_id),
    KEY sales_fk_customers (customer_id),
    KEY sales_fk_employees (employee_id),
    CONSTRAINT sales_fk_customers FOREIGN KEY (customer_id) REFERENCES customers (customer_id),
    CONSTRAINT sales_fk_employees FOREIGN KEY (employee_id) REFERENCES employees (employee_id)
);

-- Sales Items Table
CREATE TABLE sales_items (
    sale_id INT(11) NOT NULL,
    medicine_id INT(6) NOT NULL,
    sale_quantity INT(11) NOT NULL,
    total_price DECIMAL(8,2) NOT NULL,
    PRIMARY KEY (sale_id, medicine_id),
    KEY sales_items_fk_sales (sale_id),
    KEY sales_items_fk_medicines (medicine_id),
    CONSTRAINT sales_items_fk_sales FOREIGN KEY (sale_id) REFERENCES sales (sale_id),
    CONSTRAINT sales_items_fk_medicines FOREIGN KEY (medicine_id) REFERENCES medicines (medicine_id)
);




-- Salary Payments Table
CREATE TABLE salary_payments (
    payment_id INT(10) NOT NULL,
    employee_id INT(7) NOT NULL,
    payment_month DATE NOT NULL,
    payment_date DATE NOT NULL,
    amount DECIMAL(8,2) NOT NULL,
    PRIMARY KEY (payment_id),
    KEY salary_payments_fk_employees (employee_id),
    CONSTRAINT salary_payments_fk_employees FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
);
