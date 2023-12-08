#ifndef ELEC_DATA_H
#define ELEC_DATA_H

#include <iostream>
#include "date.h"
#include "household.h"

class electricityData{
    private:
    unsigned int consumedEnergy;
    unsigned int producedEnergy;
    Date date;
    float yearlyBill;//!!!!!!!//

    public:
        electricityData(Date&, unsigned int,unsigned int);
        void setConsumedEnergy(unsigned int c);
        void setProducedEnergy(unsigned int p);
        unsigned int getConsumedEnergy();
        unsigned int getProducedEnergy();
        Date* getDate();
        float getYearlyBill()const;
        bool operator<(const electricityData&)const;
        unsigned long DailyBill(Household* cust,Date* date);

};

#endif

