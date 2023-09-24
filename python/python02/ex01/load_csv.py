import pandas as pd 
import numpy as np

def load(path: str) -> pd.DataFrame:
	try:
		ret = pd.read_csv(path)
		print(f"Loading dataset of dimensions {ret.shape}")
		ret = ret.set_index('country')
		ret.columns = ret.columns.astype(int)
	except FileNotFoundError as e:
		print(f"{e.strerror}: {e.filename}")
		return
		None
	return ret