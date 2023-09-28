import pandas as pd


def load(path: str) -> pd.DataFrame:
    """
    Loads a csv file content into a pandas DataFrame

    sets country as the index for easier indexing

    @param  | path: path to csv file
    @return | the dataframe extracted
    """
    try:
        ret = pd.read_csv(path)
        print(f"Loading dataset of dimensions {ret.shape}")
        ret = ret.set_index('country')
        ret.columns = ret.columns.astype(int)
    except FileNotFoundError as e:
        print(f"{e.strerror}: {e.filename}")
        return None
    return ret
