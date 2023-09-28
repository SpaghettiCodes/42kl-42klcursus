from load_csv import load
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pandas as pd


def format_label(x, placeholder):
    """
    Fomats the labels for the y axis

    @param  | x: string to convert
            | placeholder: does nothing

    @return | string representation for the label
    """
    if x < 1000:
        return str(int(x))
    else:
        return str(f'{int(x/1000)}k')

# https://matplotlib.org/3.4.3/gallery/ticks_and_spines/major_minor_demo.html


def main():
    """
    main code runner with error handling

    load the life expectancy years and income per person
        from the respective csv
    selects all countries
    plots a dot graph (dot graph?) of
    life expectancy against gross domestic product
    """
    expectancy_dataf: pd.DataFrame = load("life_expectancy_years.csv")
    gdp_dataf: pd.DataFrame = load(
        "income_per_person_gdppercapita_ppp_inflation_adjusted.csv")

    year = '1900'

    country_expectancy = expectancy_dataf.get(year)
    country_expectancy.astype(float)
    country_gdp = gdp_dataf.get(year)
    country_gdp.astype(float)

    fig, ax = plt.subplots()

    ax.set_title(year)
    ax.set_xlabel('Gross domestic product')
    ax.set_ylabel('Life Expectancy')

    ax.scatter(
        country_gdp,
        country_expectancy
    )

    # https://matplotlib.org/3.1.1/gallery/ticks_and_spines/tick-locators.html
    ax.set_xlim(300, 10000)

    # https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xscale.html
    ax.set_xscale('log')

    ax.xaxis.set_major_locator(ticker.FixedLocator([300, 1000, 10000]))
    ax.xaxis.set_major_formatter(format_label)

    plt.show()


if __name__ == "__main__":
    main()
