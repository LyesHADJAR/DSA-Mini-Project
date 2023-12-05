# DSA-Mini-Project

##### The ENMS manages : 
- the power consumption 
- Billing by its customers on its national network
#### Networks organization :
Networks  -> Regions -> cities -> districts

- Every customer can consume electricity from the network and/or inject into it.
- Monthly amount of elec consumed/produced will be dependent on the season and production or consumption.
- Production happens in sunny days
- if (production>consumption){injection TO network} else {injection from network}
- Monthly consumed and produced amount of elec is indicated in KWH in the bill of the customer ( it varies on the season too)
- For every kwh consumed -5 DA and +3 DA for every kwh produced
- Household : 
  - name
  - ID number
  - number of family member and their ages
  - address
  - district
  - city
  - region


##### Marketing department :
- Available in each city
- has specific budget
- Its role :
  1) encourage customers to produce energy that can injected into the system
  2) getting customers to consume more
- Each department starts with a 10millons$ nationally per year for **their activities** 
- In the end of the year, they are sorted by total amounts paid by customers (top is best)
- Best dep has +15%
- [2/10] deps get +10%
- worse dep has -15% 
- [n-10/n-1] deps get -10%


##### National prize :
- Monthly
- to the one injected the most
- Cumulative month after month


##### ECMS :
- Keeps data about : 
	- Information about each household
	- data about electricity consumption/production by each household
	- on each day of the year : day is rainy/sunny/cloudy/snowy, the day max/min temperatures, and number of sunny hours
	- Spendings of each department per month
	- Over the YEARS
- Add implementations :
	- A bill for any customer.
	- Specified list to summarize bills of all customers in each district/city/region/country
	- Following implementations can be displayed for a given month year or period
	-  Visualization
- ****
