from load_csv import load
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pandas as pd


def filterYear(year: pd.Index, min: int, max: int):
    """
    filters the year to only include a certain range

    @param  | year: pd.Index from the DataFrame
            | min: minimum year to be included
            | max: maximum year to be included

    @return | filtered range, used together with .get
    """
    min_index = year.searchsorted(min)
    max_index = year.searchsorted(max)

    return year.sort_values()[min_index:max_index + 1]


def convertValue(x: str):
    """
    Convert a human-readable value to float in terms of millions

    1M -> 1
    1k -> 0.001

    @param  | x: string to convert

    @return | float value in terms of millions
    """
    symbol_conversion = {'k': 1000, 'M': 1000000}
    symbol = x[-1]

    x = float(x.replace(symbol, "")) * symbol_conversion[symbol]
    # convert to M
    x = x / 1000000
    return x


def convertReadable(x: float, placeholder):
    """
    Converts a float in term of million to human-readable value

    1 -> 1M
    0.001 -> 1k

    @param  | x: float to convert

    @return | string in human readable format
    """
    symbol_conversion = {'M': 1000000, 'k': 1000}

    x = x * 1000000
    for symbol, value in symbol_conversion.items():
        exponent = x/value
        if str(abs(exponent))[0] != '0':
            if int(exponent) == exponent:
                return f'{int(exponent)}{symbol}'
            else:
                return f'{exponent:.1f}{symbol}'
    return int(x)


def cleanData(data: pd.DataFrame):
    """
    Cleans data by

    - converting all string value to float value

    @param  | data: data to clean

    @return | cleaned data
    """
    clean_data = data.apply(convertValue)
    return clean_data


def main():
    """
    main code runner with error handling

    loads the total popoulation data from population_total.csv
    selects 2 specific country
    plots a line graph of population against year
    """
    main_df: pd.DataFrame = load("population_total.csv")
    if main_df is None:
        return
    main_df = main_df.set_index('country')
    main_df.columns = main_df.columns.astype(int)

    years = filterYear(main_df.columns, 1800, 2050)

    country1_name = "Malaysia"
    country2_name = "South Korea"

    # Small values
    # country1_name = "Trinidad and Tobago"
    # country2_name = "Qatar"

    # PDF
    # country1_name = "Belgium"
    # country2_name = "France"

    country1_rawdata = main_df.loc[country1_name].get(years)
    country2_rawdata = main_df.loc[country2_name].get(years)

    country1_data = cleanData(country1_rawdata)
    country2_data = cleanData(country2_rawdata)

    fig, ax = plt.subplots()

    ax.set_title("Population Projections")
    ax.set_xlabel("Year")
    ax.set_ylabel("Population")

    ax.plot(country1_data, label=country1_name)
    ax.plot(country2_data, label=country2_name)

    ax.xaxis.set_major_locator(ticker.MultipleLocator(40))
    ax.yaxis.set_major_locator(ticker.MultipleLocator(20))
    ax.yaxis.set_major_formatter(convertReadable)

    ax.legend(loc="lower right")

    plt.show()


if __name__ == "__main__":
    main()
