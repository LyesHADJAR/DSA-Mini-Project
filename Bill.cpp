#include "Bill.h"

// Constructor
Bill::Bill(const HouseHold& customer, double consumptionAmount, double productionAmount)
        : customer(customer), consumptionAmount(consumptionAmount),
          productionAmount(productionAmount), totalAmount(0.0), dueAmount(0.0),
          paymentStatus(UNPAID) {
    // Calculate total amount based on consumption and production
    totalAmount = consumptionAmount - productionAmount;
    if (totalAmount < 0.0) {
        // Customer has injected more than consumed, adjust due amount
        dueAmount = -totalAmount;
        totalAmount = 0.0;
    }
}

// Getter for Household
HouseHold Bill::getCustomer() const {
    return customer;
}

// Getter for Consumption Amount
double Bill::getConsumptionAmount() const {
    return consumptionAmount;
}

// Getter for Production Amount
double Bill::getProductionAmount() const {
    return productionAmount;
}

// Getter for Total Amount
double Bill::getTotalAmount() const {
    return totalAmount;
}

// Getter for Due Amount
double Bill::getDueAmount() const {
    return dueAmount;
}

// Getter for Payment Status
PaymentStatus Bill::getPaymentStatus() const {
    return paymentStatus;
}

// Method to mark the bill as paid
void Bill::markAsPaid() {
    if (paymentStatus == UNPAID) {
        paymentStatus = PAID;
        dueAmount = 0.0;
    }
}

// Destructor (if needed)
Bill::~Bill() = default;
