from enum import Enum
import pandas as pd
from pandas.api.types import is_string_dtype
from pandas.api.types import is_numeric_dtype

class COL_TYPE(Enum):
    QUANTITATIVE = 0
    QUALITATIVE = 1

def col_type(col):
    if (is_string_dtype(col)):
        return COL_TYPE.QUALITATIVE
    elif (is_numeric_dtype(col)):
        return COL_TYPE.QUANTITATIVE

def get_dataset(file):
    return pd.read_excel(file, sheet_name='Sheet1', engine='openpyxl')

def print_dict(dct):
    for item, amount in dct.items():
        print("{} ({})".format(item, amount))