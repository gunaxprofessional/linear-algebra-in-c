import pandas as pd
import numpy as np
import utlis


class decisionTreeClassifier():
    def __init__(self, x, y):
        utlis.continousData(y)


data = pd.read_csv(
    r"C:\Users\Public\linear algebra in c\decision tree\data.csv")

data.drop("ID", axis=1, inplace=True)

# print(data.head())

X = data['Buys Computer']
y = data.drop('Buys Computer', axis=1)

decisionTreeClassifier(X, y)
