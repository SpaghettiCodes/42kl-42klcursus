from load_csv import load
import matplotlib.pyplot as plt


def main():
    df = load('./population_total.csv')
    dfFR, J = df[df['country'] == "South Korea"], df[df['country'] == "Japan"]
    print(dfFR, J)
    valuesFR, valuesBZ = [eval(i[:-1]) for i in dfFR.values[0]
                          [1:250]], [eval(i[:-1]) for i in J.values[0][1:250]]
    years = [eval(i) for i in df.columns[1:][1:250]]

    plt.figure(figsize=(10, 6))
    plt.plot(years, valuesBZ, '-', 'J', label='Japan')
    plt.plot(years, valuesFR, '-', 'K', label='South Korea')
    plt.xlabel('Year')
    plt.ylabel('Life Expectancy')
    plt.title('Korea Life Expectancy Projections')
    plt.legend(loc='lower right')
    plt.yticks([20, 40, 60], ['20M', '40M', '60M'])
    plt.show()

if __name__ == "__main__":
    main()