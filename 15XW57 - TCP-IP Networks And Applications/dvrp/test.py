import math
import json
import copy

def initialize_Router(Routers,N):
    for i in range(0,N):
        Routers.append({})
        for j in range(0,N):
            if(i == j):
                Routers[i][j] = {'distance':0}
                Routers[i][j]['NextHop'] = i
            else:
                Routers[i][j] = {'distance':math.inf}
                Routers[i][j]['NextHop'] = None
    print(json.dumps(Routers,indent=4))
    return Routers

def initializeWithLink(Routers,N):
    for i in range(0,N):
        print("++++++++Router ",i,"++++++++++++++++")
        print(json.dumps(Routers[i],indent=4))
        while(1):
            j,c = map(int,input("Enter the router link with cost:").split(' '))
            if(j==i and c == 0):
                break
            Routers[i][j]['distance'] = c
            Routers[j][i]['distance'] = c
            Routers[j][i]['NextHop'] = i
            Routers[i][j]['NextHop'] = j
    return Routers  

def BellmanFord(x,y):
    pass

def performIteration(Routers,N):
    for i in range(0,N):
        for j in range(0,N):
            if(i==j or Routers[i][j]['distance'] == math.inf or Routers[i][j]['NextHop'] == None):
                continue
            else:
                for k in range(0,N):
                    if(Routers[i][k]['distance'] > Routers[j][k]['distance']+Routers[i][j]['distance']):
                        Routers[i][k]['distance'] = Routers[j][k]['distance']+Routers[i][j]['distance']
                        Routers[i][k]['NextHop'] = j
                    else:
                        continue
    return Routers

def main():
    N = int(input("Enter the number of routers:"))
    Routers = []
    Routers = initialize_Router(Routers,N)
    Routers = initializeWithLink(Routers,N)
    i = 0
    while 1:
        print("=============ITERATION:",i,"===============")
        prevState = copy.deepcopy(Routers)
        Routers = performIteration(Routers,N)
        print(json.dumps(prevState,indent=4))
        print("===========================================")
        i+=1
        if(prevState == Routers):
            break

if __name__=='__main__':
    main()