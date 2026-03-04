#include "country.h"

using namespace std;

void saveDataToJSon(const std::string &, const Country &);

Country loadDataFromJson(const std::string &);

int main() {

    srand(time(nullptr));
    vector<Date> datesVector;
    datesVector.emplace_back(19, 12, 2023, Weather());
    datesVector.emplace_back(20, 12, 2023, Weather());
    datesVector.emplace_back(22, 12, 2023, Weather());
    string id;
    Country Algeria("Algeria");

    Region region1("Region 1", Algeria.getID(), &Algeria);
    // Algeria.addRegion(&region1);
    Region region2("Region 2", Algeria.getID(), &Algeria);
    // Algeria.addRegion(&region2);
    City city1("Region 1 City 1", region1.getId(), &region1);
    City city2("Region 1 City 2", region1.getId(), &region1);
    City city3("Region 1 City 3", region1.getId(), &region1);
    City city4("Region 1 City 4", region1.getId(), &region1);
    City city5("Region 1 City 5", region1.getId(), &region1);
    City city6("Region 1 City 6", region1.getId(), &region1);
    City city7("Region 2 City 1", region1.getId(), &region2);
    City city8("Region 2 City 2", region1.getId(), &region2);
    City city9("Region 2 City 3", region1.getId(), &region2);
    City city10("Region 2 City 4", region1.getId(), &region2);
    City city11("Region 2 City 5", region1.getId(), &region2);
    City city12("Region 2 City 6", region1.getId(), &region2);
    City city13("Region 2 City 7", region1.getId(), &region2);
    // region1.addCity(&city1);
    // region1.addCity(&city2);
    // region1.addCity(&city3);
    // region1.addCity(&city4);
    // region1.addCity(&city5);
    // region1.addCity(&city6);
    // region2.addCity(&city7);
    // region2.addCity(&city8);
    // region2.addCity(&city9);
    // region2.addCity(&city10);
    // region2.addCity(&city11);
    // region2.addCity(&city12);
    // region2.addCity(&city13);

    District district1("Region 1 City 1 District 1", city1.getID(), &city1);
    District district2("Region 1 City 1 District 2", city2.getID(), &city2);
    District district3("Region 1 City 1 District 3", city1.getID(), &city1);
    District district4("Region 1 City 1 District 4", city1.getID(), &city1);
    District district5("Region 1 City 1 District 5", city1.getID(), &city1);
    District district6("Region 1 City 1 District 6", city1.getID(), &city1);
    District district7("Region 1 City 2 District 7", city2.getID(), &city2);
    District district8("Region 1 City 2 District 8", city2.getID(), &city2);
    District district9("Region 1 City 2 District 9", city2.getID(), &city2);
    District district10("Region 1 City 2 District 10", city2.getID(), &city2);
    District district11("Region 1 City 2 District 11", city2.getID(), &city2);
    District district12("Region 1 City 2 District 12", city2.getID(), &city2);
    District district13("Region 1 City 2 District 13", city2.getID(), &city2);
    // city1.addDistrict(&district1);
    // city1.addDistrict(&district2);
    // city1.addDistrict(&district3);
    // city1.addDistrict(&district4);
    // city1.addDistrict(&district5);
    // city1.addDistrict(&district6);
    // city2.addDistrict(&district7);
    // city2.addDistrict(&district8);
    // city2.addDistrict(&district9);
    // city2.addDistrict(&district10);
    // city2.addDistrict(&district11);
    // city2.addDistrict(&district12);
    // city2.addDistrict(&district13);

    vector<int> age{0, 2};
    HouseHold household1(age, "Region 1 City 1 District 1 Household 1", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household2(age, "Region 1 City 1 District 1 Household 2", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household3(age, "Region 1 City 1 District 2 Household 3", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household4(age, "Region 1 City 1 District 3 Household 4", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household5(age, "Region 1 City 1 District 4 Household 5", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household6(age, "Region 1 City 1 District 4 Household 6", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household7(age, "Region 1 City 1 District 5 Household 7", 2, "kjh", district1.getDistrict_ID(),
                         &district1);
    HouseHold household8(age, "Region 1 City 1 District 6 Household 8", 2, "kjh", district2.getDistrict_ID(),
                         &district2);
    HouseHold household9(age, "Region 1 City 2 District 7 Household 9", 2, "kjh", district2.getDistrict_ID(),
                         &district2);
    HouseHold household10(age, "Region 1 City 2 District 8 Household 10", 2, "kjh", district2.getDistrict_ID(),
                          &district2);
    HouseHold household11(age, "Region 1 City 2 District 9 Household 11", 2, "kjh", district2.getDistrict_ID(),
                          &district2);
    HouseHold household12(age, "Region 1 City 2 District 10 Household 12", 2, "kjh", district2.getDistrict_ID(),
                          &district2);
    HouseHold household13(age, "Region 1 City 2 District 11 Household 13", 2, "kjh", district2.getDistrict_ID(),
                          &district2);
    HouseHold household14(age, "Region 1 City 2 District 12 Household 14", 2, "kjh", district2.getDistrict_ID(),
                          &district2);

    for (int i = 0; i < 3; i++) {
        household14.addElectricityData(datesVector[i], 1000 * i + 2000, 2500 * i);
        household9.addElectricityData(datesVector[i], 1000 * i, 500 * i);
        household1.addElectricityData(datesVector[i], 1000 * i + 100, 10000 * i);
        household2.addElectricityData(datesVector[i], 1000 * i + 100, 4500 * i);
    }
    HouseHold households[] = {household1, household2, household3, household4, household5, household6, household7,
                              household8, household9, household10, household11, household12, household13, household14};
    //  for(int i=0; i<14; i++)           cout<<households[i].getAccountHolderName()<<"  "<<households[i].getTotalConsumption()<<"  "<<households[i].getTotalProduction()<<endl;
    for (int i = 0; i < 7; i++)
        district1.addHouseHold(households[i]);
    for (int i = 7; i < 14; i++)
        district2.addHouseHold(households[i]);
    // Algeria.endOfTheYear(2023);
    // cout<<Algeria.nationalPrizeWinner(2023,12)->getAccountHolderName()<<endl;
    cout << household9.getConsumptionInRange(2022, 12, 19, 2023, 12, 28);
    //city1.printDistricts();

    saveDataToJSon("fileName.json", Algeria);

    return 0;
}

void saveDataToJSon(const std::string &fileName, const Country &c) {
    nlohmann::json root = c.countryToJson();
    std::ofstream File(fileName);
    File << std::setw(4) << root;
    File.close();
}

Country loadDataFromJson(const std::string &filename) {
    std::ifstream inFile(filename);
    nlohmann::json loadedRoot;
    inFile >> loadedRoot;
    inFile.close();

    return Country::countryFromJson(loadedRoot);
}
