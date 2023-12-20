import pandas as pd

def load(path):
    try:
        dataset = pd.read_csv(path)
        # dataset = dataset.set_index(dataset.columns[0])
        dimensions = dataset.shape
        print(f"Loading dataset of dimensions {dimensions}")
        return dataset
    except Exception as e:
        print(f"Error: {e}")
        return None
 