from enum import Enum
import pandas as pd
from pandas.api.types import is_string_dtype
from pandas.api.types import is_numeric_dtype
import matplotlib.pyplot as plt
import pandas as pd

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

def q1(df):
    print("### Question 1 ###")
    quant_count = 0
    qual_count = 0
    for i in df:
        if(col_type(df[i]) == COL_TYPE.QUALITATIVE):
            qual_count += 1
        elif(col_type(df[i]) == COL_TYPE.QUANTITATIVE):
            quant_count += 1
    print("==> Quantitative Count: ", quant_count)
    print("==> Qualitative Count: ", qual_count)


def q2(dataset):
    print("### Question 2 ###")
    top_shelf = dataset[(dataset['shelf'] == 'Top')]
    middle_shelf = dataset[(dataset['shelf'] == 'Middle')]
    bottom_shelf = dataset[(dataset['shelf'] == 'Bottom')]
    fig, axs = plt.subplots(1, 3)

    axs[0].hist(top_shelf['sugars'])
    axs[0].set_title('Top Shelf Sugar')

    axs[1].hist(middle_shelf['sugars'])
    axs[1].set_title('Middle Shelf Sugar')

    axs[2].hist(bottom_shelf['sugars'])
    axs[2].set_title('Bottom Shelf Sugar')

    plt.savefig('1/plots/q2.png')
    mean = {'top': top_shelf['sugars'].mean(), 'mid': middle_shelf['sugars'].mean(), 'bot': bottom_shelf['sugars'].mean()}
    print_dict(mean)
    return mean


def q3(mean):
    print("### Question 3 ###")
    print("==> Order of shelf with higest sugar content.")
    print_dict(dict(sorted(mean.items(), key=lambda item: item[1])))

def q4(dataset):
    print("### Question 4 ###")
    plt.boxplot(dataset['fiber'])
    plt.savefig('1/plots/q4.png')
    print(dataset['fiber'].describe())

def q5(dataset):
    print("### Question 5 ###")
    plt.scatter(dataset['carbo'], dataset['calories'])
    plt.title('Scatter Plot - Calories vs Carbohydrates')
    plt.ylabel('Calories')
    plt.xlabel('Carbohydrates')
    print(dataset['carbo'].corr(dataset['calories']))
    plt.savefig('1/plots/q5.png')