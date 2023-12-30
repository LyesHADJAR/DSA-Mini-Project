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
                "Month": 1,
                "Year": 2023
            },
            "Day_Weather": {
                "CurrentCondition": random.randint(1, 4),
                "MaxTemperature": round(random.uniform(18, 30), 1),
                "MinTemperature": round(random.uniform(10, 20), 1),
                "SunnyHours": round(random.uniform(4, 10), 1)
            },
            "Production": round(random.uniform(0, 100), 1)
        }
        #for year in range(2022, 2024)
        #for month in range(1, 13)
        for day in range(1, 31)
    ]

def generate_customer_data(num_customers, district_id):
    customer_data = []

    for customer_index in range(1, num_customers + 1):
        Family_Members = random.randint(1, 10)  # Define Family_Members in the loop
        customer_name = f"{random.choice(algerian_first_names)} {random.choice(algerian_last_names)}"
        customer_id = f"{district_id}{customer_index:04d}"
        customer_address = fake.street_address()

        # Generate two years worth of data for each customer
        customer_electricity_data = generate_electricity_data()

        customer = {
            "Account_Holder_Name": customer_name,
            "householdID": customer_id,
            "Family_Members": Family_Members,
            "Family_Members_Ages": [random.randint(1, 80) for _ in range(Family_Members)],
            "Address": customer_address,
            "Is_Prize_Winner": False,
            "HouseHold_Electricity_Data": customer_electricity_data
        }

        customer_data.append(customer)

    return customer_data

# Example usage for generating customer data
num_customers = 100
district_id = "001001002004"  # Replace this with the desired district ID
customers_data = generate_customer_data(num_customers, district_id)

# Save the generated customer data to a JSON file
output_customers_file_path = "generated_customers_data.json"
with open(output_customers_file_path, "w") as output_file:
    json.dump(customers_data, output_file, indent=2)

print(f"Data for {num_customers} customers has been saved to {output_customers_file_path}")
