import requests
import json

while True:
    try:
        pokiname = input('Enter the name of a Pokemon: ')
    except EOFError:
        continue
    if not pokiname or pokiname == '':
        print('Please enter the name of a Pokemon.')
        continue
    break
api_url = f'https://pokeapi.co/api/v2/pokemon/{pokiname}'
response = requests.get(api_url)
if response.status_code == 200:
    rspn = json.loads(response.content)
    print(f'Name: ' + rspn['name'])
    print('Abilities: ')
    for ab in rspn['abilities']:
        print(' - ' + ab['ability']['name'])
else:
    print("You know nothing about Pokemon!! What a shame!!!")