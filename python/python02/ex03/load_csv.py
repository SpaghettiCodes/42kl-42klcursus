import pandas as pd


def load(path: str) -> pd.DataFrame:
    """
    Loads a csv file content into a pandas DataFrame

    sets country as the index for easier indexing

    @param  | path: path to csv file
    @return | the dataframe extracted
    """
    name_segments = path.split('.')
    if len(name_segments) < 2 or name_segments[1] != 'csv':
        print("WARNING -- File extension IS NOT CSV, you \
sure you meant to load this file?")

    ret = None
    try:
        ret = pd.read_csv(path)
        print(f"Loading dataset of dimensions {ret.shape}")
    except FileNotFoundError as e:
        print(f"{e.strerror}: {e.filename}")
    except Exception as e:
        print("Something bad happened during parsing")
        print("Error info --")
        print(e)

    return ret
