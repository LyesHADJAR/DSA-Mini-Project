#ifndef BILLING_H
#define BILLING_H
#include<iostream>
#include<random>

enum class BillingStatus {
        NoCharge=1,
        Payment,
        Credit
    };
class Billing {
    unsigned Bill_ID;
    size_t Customer_ID;
    double Consumption = 0;
    double Production = 0;
    BillingStatus billingStatus;
    public:
    Billing() ;
    Billing(unsigned Bill_ID, size_t Customer_ID);
    unsigned getBill_ID() const;
    size_t generateBillId()const;
    size_t getCustomer_ID()const ;
    double getConsumption()const ;
    double getProduction ()const ;
    void setConsumption(double);
    void setProduction(double);
    void setBill_ID(unsigned);
    void setCustomer_ID(size_t);
    double calculateAmountDue() ;
    void setBillingStatus( BillingStatus );
    BillingStatus getBillingStatus()const;
};


#endif