use project;
show tables;

Select * from Suppliers;
call CreateNewSaleId();


CREATE TRIGGER BeforeInsertMedicine
BEFORE INSERT ON medicines
FOR EACH ROW
BEGIN
    DECLARE newMedicineId INT;
    CALL FindNewMedicineId(newMedicineId);
    SET NEW.medicine_id = newMedicineId;
END 

CREATE TRIGGER BeforeInsertMedicineStorage
BEFORE INSERT ON medicine_storage
FOR EACH ROW
BEGIN
    DECLARE nextStoreId INT;
    SELECT IFNULL(MAX(STORE_ID), 0) + 1 INTO nextStoreId FROM medicine_storage; 
    SET NEW.STORE_ID = nextStoreId;
END

CALL AddMedicineStorage(6,6,'2024-12-05');
SELECT m.medicine_id, m.medicine_name, m.location_rack
FROM medicine_details md
JOIN medicines m ON md.medicine_id = m.medicine_id
WHERE md.DISEASE_TREATED = 'Allergies';


SELECT employees.employee_id as Employee,customers.first_name as Customers_Name,sales.total_amount as Cost 
FROM sales
LEFT JOIN customers ON sales.customer_id = customers.customer_id
LEFT JOIN employees ON sales.employee_id = employees.employee_id;

SELECT medicines.*, medicine_details.DISEASE_TREATED,medicine_details.GENERIC_TYPE
FROM medicines
JOIN medicine_details ON medicines.medicine_id = medicine_details.medicine_id;


SELECT employees.employee_id, employees.first_name, SUM(salary_payments.amount) AS total_paid_amount
FROM employees
LEFT JOIN salary_payments ON employees.employee_id = salary_payments.employee_id
GROUP BY employees.employee_id, employees.first_name;

SELECT medicines.medicine_name,medicines.location_rack,medicine_storage.STORE_ID
FROM medicine_storage
JOIN medicines ON medicine_storage.medicine_id = medicines.medicine_id
WHERE medicine_storage.EXP_DATE <= '2023-11-14';



CREATE FUNCTION GetTotalPaidAmount(
    p_employee_id INT
)
RETURNS DECIMAL(8, 2)
DETERMINISTIC READS SQL DATA
BEGIN
    DECLARE total_amount DECIMAL(8, 2);

    SELECT COALESCE(SUM(amount), 0)
    INTO total_amount
    FROM salary_payments
    WHERE employee_id = p_employee_id;

    RETURN total_amount;
END 

Select GetTotalPaidAmount(1);



CREATE FUNCTION GetEmployeeAge(
    p_employee_id INT
)
RETURNS INT
DETERMINISTIC READS SQL DATA
BEGIN
    DECLARE tbirth_date DATE;

    SELECT birth_date INTO tbirth_date
    FROM employees
    WHERE employee_id = p_employee_id;

    RETURN YEAR(CURRENT_DATE()) - YEAR(tbirth_date) - (RIGHT(CURRENT_DATE(), 5) < RIGHT(tbirth_date, 5));
END 

Select GetEmployeeAge(1);



CREATE FUNCTION GetTotalMedicineQuantity(
    p_medicine_id INT
)
RETURNS INT
DETERMINISTIC READS SQL DATA
BEGIN
    DECLARE total_quantity INT;

    SELECT COALESCE(SUM(MED_QTY), 0)
    INTO total_quantity
    FROM medicine_storage
    WHERE medicine_id = p_medicine_id;

    RETURN total_quantity;
END

Select GetTotalMedicineQuantity(1);



show TRIGGERs LIKE 'medicines';
