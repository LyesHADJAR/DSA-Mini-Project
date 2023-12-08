#include "elec_data.h"

electricityData::electricityData(Date& d, unsigned int cons, unsigned int prod) : date(d) {
    setConsumedEnergy(cons);
    setProducedEnergy(prod);
}

void electricityData::setConsumedEnergy(unsigned int c){this->consumedEnergy=c;}

void electricityData::setProducedEnergy(unsigned int p){this->producedEnergy=p;}

unsigned int electricityData:: getConsumedEnergy(){return this->consumedEnergy;}
unsigned int electricityData::getProducedEnergy(){return this->producedEnergy;}
Date* electricityData:: getDate() {
    return &date;
}
float electricityData::getYearlyBill()const {
            return yearlyBill;
}

unsigned long electricityData::DailyBill(Household* cust,Date* date){
            return getConsumedEnergy()*5-getProducedEnergy()*3;
}

bool electricityData::operator<(const electricityData& elData)const {
    return date < elData.date;
}