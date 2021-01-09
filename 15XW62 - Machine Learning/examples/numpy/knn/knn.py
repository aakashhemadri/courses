#Import Modules Pandas and Numpy
import pandas as pd
import numpy as np
import operator

#Read CSV File
data = pd.read_csv("iris.csv")

#To find Euc Distance
def ED(x1, x2, length): 
    distance = 0
    for x in range(length):
        distance += np.square(x1[x] - x2[x])

    return np.sqrt(distance)

#KNN Model Definition
def knn(trainingSet, testInstance, k): 
 
    distances = {}

    #To find number of columns 
    length = testInstance.shape[1]

    for x in range(len(trainingSet)):
        dist = ED(testInstance, trainingSet.iloc[x], length)
        distances[x] = dist[0]

    sortdist = sorted(distances.items(), key=operator.itemgetter(1))
    #Put the index of col you wanna sort with 
    neighbors = []
    for x in range(k):
        neighbors.append(sortdist[x][0])

    Votes = {} #to get most frequent class of rows
    for x in range(len(neighbors)):
        response = trainingSet.iloc[neighbors[x]][-1]
        #To get the last column for corresponding index 
        if response in Votes:
            Votes[response] += 1
        else:
            Votes[response] = 1
    #Appending the Variety to dict along with count
    sortvotes = sorted(Votes.items(), key=operator.itemgetter(1), reverse=True)
    return(sortvotes[0][0], neighbors)
    
#Input TestSet    
testSet = [[6.8, 3.4, 4.8, 2.4]]
test = pd.DataFrame(testSet)

#Different k Values
k = 6
k1 = 3

#Function Call
result,neigh = knn(data, test, k)
#result1,neigh1 = knn(data, test, k1)
print(result)
