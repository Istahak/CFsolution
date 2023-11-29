-- Function


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



-- Procedure



CREATE PROCEDURE FindNewMedicineId(OUT newMedicineId INT)
BEGIN
    SELECT COALESCE(MAX(medicine_id), 0) + 1 INTO newMedicineId FROM medicines;
END 



CREATE PROCEDURE AddMedicine(
    IN medicineName VARCHAR(50),
    IN locationRack INT
)
BEGIN
    INSERT INTO medicines (medicine_name, location_rack)
    VALUES (medicineName, locationRack);
END


CREATE PROCEDURE CalculateTotalPrice(IN saleId INT, OUT totalPrice DECIMAL(8, 2))
BEGIN
    SELECT SUM(total_price) INTO totalPrice
    FROM sales_items
    WHERE sale_id = saleId;
END

CREATE PROCEDURE FindTotalCostForPurchase(
    IN purchaseId INT,
    IN medicineId INT,
    OUT totalCost DECIMAL(8, 2)
)
BEGIN
    SELECT quantity * cost INTO totalCost
    FROM purchases
    WHERE purchase_id = purchaseId AND medicine_id = medicineId;
END

CREATE PROCEDURE CalculatePerMedicineCostAndQuantity(
    IN pPurchaseId INT,
    IN pMedicineId INT,
    OUT pPerMedicineCost DECIMAL(8, 2),
    OUT pQuantity INT
)
BEGIN
  
    DECLARE totalCost DECIMAL(8, 2);


    SELECT cost, quantity
    INTO totalCost, pQuantity
    FROM purchases
    WHERE purchase_id = pPurchaseId AND medicine_id = pMedicineId;

    -- Check if pQuantity is not zero to avoid division by zero
    IF pQuantity <> 0 THEN
        -- Calculate per-medicine cost
        SET pPerMedicineCost = totalCost / pQuantity;
   ELSE
        -- Set both pPerMedicineCost and pQuantity to zero if pQuantity is zero
       SET pPerMedicineCost = 0;
        SET pQuantity = 0;
    END IF;
END


CREATE PROCEDURE AddMedicineStorage(
    IN pMedicineId INT,
    IN pPurchaseId INT,
    IN pExpDate DATE
)
BEGIN
    DECLARE perMedicineCost DECIMAL(8, 2);
    DECLARE quantity INT;
    CALL CalculatePerMedicineCostAndQuantity(pPurchaseId, pMedicineId, perMedicineCost, quantity);
    INSERT INTO medicine_storage (medicine_id, PURCHASE_ID, MED_QTY, MED_PRICE, EXP_DATE)
    VALUES (pMedicineId, pPurchaseId, quantity, perMedicineCost, pExpDate);
END;


-- Triggir



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