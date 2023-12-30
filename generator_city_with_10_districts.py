import json
import random
from faker import Faker

fake = Faker()

algerian_first_names = ["Mohamed", "Fatima", "Sofiane", "Zahra", "Nabil", "Yasmine", "Amine", "Houda", "Khaled", "Wafa", "Younes", "Zineb", "Omar", "Lila", "Karim", "Sara", "Mehdi", "Nadia", "Ibrahim", "Rania", "Abdelkader", "Farida", "Adel", "Lina", "Said", "Sabrina", "Rachid", "Malika", "Ahmed", "Loubna", "Bilal", "Aicha", "Samir", "Salima", "Walid", "Nawel", "Hakim", "Asma", "Amar", "Imene", "Faycal", "Leila", "Hicham", "Houria", "Reda", "Nour", "Tarek", "Hiba", "Othmane", "Djamila", "Yacine", "Safia", "Toufik", "Rym", "Hassan", "Imane", "Abdellah", "Nawal", "Mohammed", "Saida", "Oualid", "Karima", "Amir", "Noura", "Brahim", "Lamia", "Nacer", "Fatiha", "Abdel", "Ines", "Salem", "Kahina", "Hamza", "Naima", "Fouad", "Laila", "Ouahiba", "Djamel", "Samia", "Noureddine", "Amina", "Imad", "Sahra", "Hichem", "Kenza", "Bachir", "Nasma", "Houari", "Yasmina", "Fares", "Amani", "Hakima", "Chakib"]
algerian_last_names = ["Bouazza", "Hamza", "Touati", "Belkacem", "Ziani", "Benmoussa", "Boudiaf", "Lakhdar", "Boukrouh", "Ouadah", "Cherif", "Mazouzi", "Bekkouche", "Khelfaoui", "Boumediene", "Kaci", "Boukhlouf", "Taleb", "Boudjemaa", "Bouchenak", "Djebbari", "Bouziane", "Ouahrani", "Benaissa", "Zaoui", "Benhamadi", "Cherifi", "Mekki", "Bensalem", "Djedid", "Saci", "Bouraoui", "Ait", "Bekri", "Moussaoui", "Bouslama", "Zitouni", "Lamara", "Bennaceur", "Hadj", "Benmaamar", "Bouchama", "Ait", "Larbi", "Bentaleb", "Zemouri", "Boudraa", "Zerguini", "Boussaid", "Ouarab", "Bensaid", "Zair", "Bouchentouf", "Boumaza", "Derradji", "Bentoumi", "Zouari", "Khaled", "Bouras", "Bouzidi", "Chouaki", "Touhami", "Zeroual", "Kebir", "Guellil", "Benseghir", "Bouchama", "Ait", "Mouloud", "Chetouane", "Kerkar", "Bensaber", "Ziri", "Hammoudi", "Zitout", "Lagraa", "Ait", "Abed", "Larbi", "Boussad", "Tounsi", "Meziane", "Touil", "Cherfaoui", "Boumaza", "Ouali", "Ould", "Zouaoui", "Bouchareb", "Meziane", "Taibi"]

def generate_electricity_data():
    return [
        {
            "Consumption": round(random.uniform(0, 150), 1),
            "Date": {
                "Day": day,
                "Day_Weather": {
                    "CurrentCondition": random.randint(1, 4),
                    "MaxTemperature": round(random.uniform(18, 30), 1),
                    "MinTemperature": round(random.uniform(10, 20), 1),
                    "SunnyHours": round(random.uniform(4, 10), 1)
                },
                "Month": 1,
                "Year": 2023
            },
            "Production": round(random.uniform(0, 100), 1)
        }
        for day in range(1, 31)
    ]
def generate_household_data(city_name, district_names):
    city_data = {
        "City_Name": city_name,
        "City_ID": "001006001",
        "Department": {
            "AmountSpent": 0.0,
            "Budget": 10000000.0,
            "Ranking": 0
        },
        "Districts": []
    }

    for i, district_name in enumerate(district_names, 1):  # Start enumeration from 1
        Family_Members = random.randint(1, 10)  # Define Family_Members in the loop
        district_data = {
            "District_Name": district_name,
            "District_ID": f"001006001{i:03d}",  # Append the loop index as a three-digit numerical value
            "Households": [
                {
                    "Account_Holder_Name": f"{random.choice(algerian_first_names)} {random.choice(algerian_last_names)}",
                    "householdID": f"001006001{i:03d}0001",  # Use the same index for householdID
                    "Family_Members": Family_Members,
                    "Family_Members_Ages": [random.randint(1, 80) for _ in range(Family_Members)],
                    "Address": fake.street_address(),
                    "Is_Prize_Winner": False,
                    "HouseHold_Electricity_Data": generate_electricity_data()
                }
            ]
        }
        city_data["Districts"].append(district_data)

    return city_data
    
# Example usage:
city_name = "Tamenrasset"
district_names = ["Tamanrasset", "Abalessa", "In Ghar", "In Guezzam", "Idles", "Tazrouk", "Tin Zaouatine", "In Salah", "In Amguel", "Foggaret Ezzaouia"]
city_data = generate_household_data(city_name, district_names)

# Save the generated data to a JSON file
output_file_path = "generated_data.json"
with open(output_file_path, "w") as output_file:
    json.dump(city_data, output_file, indent=2)

print(f"Data has been saved to {output_file_path}")
