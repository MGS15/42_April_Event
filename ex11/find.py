import requests

isname = True
while isname:
	pokiname = input('Enter the name of a Pokemon: ')
	if not pokiname or pokiname == '':
		print('Please enter the name of a Pokemon.')
	isname = False
api_url = f'https://pokeapi.co/api/v2/pokemon/{pokiname}'