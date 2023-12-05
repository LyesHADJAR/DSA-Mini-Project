#ifndef ELEC_DATA_H
#define ELEC_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include "date.h"

class ELEC_DATA{
    private:
    unsigned int consumedEnergy;
    unsigned int producedEnergy;
    public:
        void setConsumedEnergy(string c){this->consumedEnergy=c;}
        void setProducedEnergy(string p){this->producedEnergy=p;}
        string getConsumedEnergy(){return this->consumedEnergy;}
        string getProducedEnergy(){return this->producedEnergy;}
        Date* getDate();

        unsigned long DailyBill(customer* cust,date* date){
            return getConsumedEnergy()*5-getProducedEnergy()*3;
        }

};

#endif


//Functions i need to implement :
/* 
billing per month

*/