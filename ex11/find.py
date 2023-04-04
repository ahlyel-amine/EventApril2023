import requests

pokemon_name = input("Enter the name of a Pokemon: ")

url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name.lower()}/"

response = requests.get(url)

if response.status_code == 200:

    data = response.json()
    pokemon_name = data['name'].capitalize()

    abilities = []
    ablility_tab = data['abilities']
    for ability in ablility_tab :
        abilities.append(ability['ability']['name'].capitalize())

    print(f"Name: {pokemon_name}")
    print("Abilities:")

    for ability in abilities:
        print(f"- {ability}")
else:
    print(f"Error: Could not retrieve data for Pokemon '{pokemon_name}'")
