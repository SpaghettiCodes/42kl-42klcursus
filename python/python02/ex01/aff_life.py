from load_csv import load
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pandas as pd


def main():
    """
    main runner code with error handling

    loads life expectancy years data from the csv file
    selects a specific country
    then displays a graph of life expectancy against year
    """
    main_df: pd.DataFrame = load("life_expectancy_years.csv")
    if main_df is None:
        return
    # country = 'Malaysia'
    country = 'France'
    data = main_df.loc[country]

    fig, ax = plt.subplots()

    ax.set_title(f"{country} Life Expectancy Projections")
    ax.set_ylabel('Life Expectancy')
    ax.set_xlabel('Year')

    ax.plot(data)

    # https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xticks.html
    tick_setter = ticker.MultipleLocator(40)
    ax.xaxis.set_major_locator(tick_setter)

    plt.show()


if __name__ == "__main__":
    main()
