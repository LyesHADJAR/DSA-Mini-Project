#ifndef BILL_H
#define BILL_H

#include "Household.h"

enum PaymentStatus {
    UNPAID,
    PAID
};

class Bill {
private:
    HouseHold customer;
    double consumptionAmount;
    double productionAmount;
    double totalAmount;
    double dueAmount;
    PaymentStatus paymentStatus;

public:
    // Constructor
    Bill(const HouseHold& customer, double consumptionAmount, double productionAmount);

    // Getter for Household
    HouseHold getCustomer() const;

    // Getter for Consumption Amount
    double getConsumptionAmount() const;

    // Getter for Production Amount
    double getProductionAmount() const;

    // Getter for Total Amount
    double getTotalAmount() const;

    // Getter for Due Amount
    double getDueAmount() const;

    // Getter for Payment Status
    PaymentStatus getPaymentStatus() const;

    // Method to mark the bill as paid
    void markAsPaid();

    // Destructor (if needed)
    ~Bill();
};

#endif
