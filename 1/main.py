from func import q1, q2, q3
from utils import get_dataset

def main():
    df = get_dataset('dataset.xlsx')
    q1(df)
    q3(q2(df))

if __name__ == '__main__':
    main()