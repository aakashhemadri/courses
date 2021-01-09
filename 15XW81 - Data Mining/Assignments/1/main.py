import os
from utils import q1, q2, q3, q4, q5, get_dataset
dir_path = os.path.dirname(os.path.realpath(__file__))

def main():
    df = get_dataset(dir_path + '/dataset.xlsx')
    q1(df)
    q3(q2(df))
    q4(df)
    q5(df)

if __name__ == '__main__':
    main()
