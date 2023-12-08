#ifndef ELEC_DATA_H
#define ELEC_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include "date.h"

class ELEC_DATA{
    private:
    unsigned long consumedEnergy;
    unsigned long producedEnergy;
    public:
    ELEC_DATA ELEC_DATA(unsigned long CE, unsigned long PE){
        void setConsumedEnergy( CE );
        void setProducedEnergy( PE ); 
    };  
    //Setters
        void setConsumedEnergy(unsigned int  c){
            this->consumedEnergy=c;}

        void setProducedEnergy(unsifgned int p){
            this->producedEnergy=p;}
    //Getters
        unsigned long getConsumedEnergy(){
            return this->consumedEnergy;}

        unsigned long getProducedEnergy(){
            return this->producedEnergy;}
    //Other functions
        unsigned long DailyBill(customer* cust,date* date){
            
            //Smt to use from customer and date classes

            return getConsumedEnergy()*5-getProducedEnergy()*3;
        }

};

#endif


//Functions i need to implement :
/* 
billing per month

*/
