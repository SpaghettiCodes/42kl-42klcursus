from load_csv import load
import matplotlib.pyplot as plt

df = load("./life_expectancy_years.csv")
fr_df = df[df['country'] == 'Malaysia']
y, e = fr_df.columns[1:].astype(int), fr_df.iloc[:, 1:].values.flatten()
plt.plot(y, e)
plt.title('Malaysia Life Expectancy')
plt.xlabel('Year')
plt.ylabel('Expectancy')
plt.show()