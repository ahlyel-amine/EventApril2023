import requests

# Prompt the user to enter the name of a Pokemon
pokemon_name = input("Enter the name of a Pokemon: ")

# Construct the API endpoint URL for the specified Pokemon
url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}/"

# Send a GET request to the PokeAPI endpoint to retrieve information about the Pokemon
response = requests.get(url)

# Check if the response was successful
if response.status_code == 200:
    # Extract the Pokemon's name and abilities from the response JSON
    data = response.json()
    pokemon_name = data['name'].capitalize()
    abilities = [ability['ability']['name'].replace('-', ' ').capitalize() for ability in data['abilities']]
    
    # Display the Pokemon's name and abilities
    print(f"Name: {pokemon_name}")
    print("Abilities:")
    for ability in abilities:
        print(f"- {ability}")
else:
    print(f"Error: Could not retrieve data for Pokemon '{pokemon_name}'")
