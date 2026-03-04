#include"Billing.h"

size_t Billing::generateBillId() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(100, 999);

    return getCustomer_ID() * 1000 + dis(gen);
}

Billing::Billing() {}

Billing::Billing(unsigned Bill_ID, size_t Customer_ID) {
    setCustomer_ID(Customer_ID);
    setBill_ID(generateBillId());
}

unsigned Billing::getBill_ID() const {
    return Bill_ID;
}

size_t Billing::getCustomer_ID() const {
    return Customer_ID;
}

double Billing::getConsumption() const {
    return Consumption;
}

double Billing::getProduction() const {
    return Production;
}

void Billing::setConsumption(double Amount) {
    Consumption = Amount;
}

void Billing::setProduction(double Amount) {
    Production = Amount;
}

void Billing::setBill_ID(unsigned Value) {
    Bill_ID = Value;
}

void Billing::setCustomer_ID(size_t Value) {
    Customer_ID = Value;
}

void Billing::setBillingStatus(BillingStatus value) {
    if (value >= BillingStatus::NoCharge && value <= BillingStatus::Credit)
        billingStatus = value;
    else
        throw std::invalid_argument("Invalid Billing Status");
}

BillingStatus Billing::getBillingStatus() const {
    return billingStatus;
}

double Billing::calculateAmountDue() {
    double AmountDue = getConsumption() * 5 - getProduction() * 3;
    if (AmountDue < 0) {
        billingStatus = BillingStatus::Credit;
    } else if (AmountDue > 0) {
        billingStatus = BillingStatus::Payment;
    } else
        billingStatus = BillingStatus::Payment;

    return AmountDue;
}
