from load_csv import load
import matplotlib.pyplot as plt


df_life = load('./life_expectancy_years.csv')
df_life = df_life[['country', '1900']]
arr_life = df_life['1900'].tolist()
df_gdp = load('./income_per_person_gdppercapita_ppp_inflation_adjusted.csv')
df_gdp = df_gdp[['country', '1900']]
arr_gdp = df_gdp['1900'].tolist()
merged_df = df_gdp.merge(df_life, on='country', suffixes=('_gdp', '_life'))
plt.figure(figsize=(10, 6))
plt.scatter(arr_gdp, arr_life)
plt.title('1900')
plt.xscale("log")
plt.xticks([300, 1000, 10000], labels=['300', '1k', '10k'])
plt.xlabel('GDP')
plt.ylabel('Life Exp.')
plt.show()
corr = merged_df['1900_life'].corr(merged_df['1900_gdp'])
print(f'Correlation (1900): {corr:.2f}')