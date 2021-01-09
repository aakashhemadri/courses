import pandas as pd
import numpy as np

def reshapeData(x):
    x.reshape(-1,1)

def concatenateOnes(x):
    onesData = np.ones(shape = x.shape[0]).reshape(-1,1)
    #print("OnesData : ",onesData)
    return np.concatenate((onesData,x),1)

def fitData(coefficients):
    #Check the formula for matrix method
    coefficients = np.linalg.inv(x.transpose().dot(x)).dot(x.transpose()).dot(y)
    return coefficients

if __name__ == "__main__":
    coefficients = []
    bostonData = pd.read_csv("../../../datasets/boston_housing.csv")
    #print(bostonData.head())
    
    # Y Label is "medv" so seperate it 
    x = bostonData.drop('medv',axis = 1).values
    y = bostonData['medv'].values
    
    # Reshape the data frame to the required format
    reshapeData(x)
    #print("After Reshaping : ",x)
    
    # Append ones at the starting , check whether your model requires appending of one before doing it
    x = concatenateOnes(x)
    #print("After Concatenation : ",x)
    
    #Fit the data to a model
    coefficients = fitData(coefficients)
    print(coefficients)