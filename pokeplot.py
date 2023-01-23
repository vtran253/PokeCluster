import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import seaborn as sns
import matplotlib.pyplot as plt

#Reading CSV file
pokedex = pd.read_csv('PokedexCluster.csv')
id = pokedex['#']
name = pokedex['Name']
type1 = pokedex['Type 1']
type2 = pokedex['Type 2']
total = pokedex['Total']
hp = pokedex['HP']
attack = pokedex['Attack']
defense = pokedex['Defense']
spAtk = pokedex['Sp. Atk']
spDef = pokedex['Sp. Def']
speed = pokedex['Speed']
gen = pokedex['Generation']

#plt.scatter(attack, total, s=100, alpha=0.6, edgecolor='black', linewidth=1)
sns.pairplot(pokedex[['Total', 'HP', 'Attack', 'Defense','Sp. Atk', 'Sp. Def', 'Speed']]);

plt.tight_layout()
plt.show()
