import math
import json

Sequence_List = []

def ControlledFlooding(N):
    for i in range(0,N):
        Sequence_List.append({i:0})

def initialize_Router(Routers,N):
    for i in range(0,N):
        Routers.append({})
        for j in range(0,N):
            if(i==j):
                Routers[i][j] = {'distance':0}
                Routers[i][j]['Nexthop'] = i
            else:
                Routers[i][j] = {'distance':math.inf}
                Routers[i][j]['NextHop'] = None
    print(json.dumps(Routers,indent=4))
    return Routers

def initializeWithLink(Routers,N):
    for i in range(0,N):
        print("============Router ",i,"=====================")
        print(json.dumps(Routers[i],indent=4))
        while True:
            j,c = map(int,input("Enter the router Link with cost (i.e) Routerid  cost:").split(' '))
            if(j==i and c==0):
                break
            Routers[i][j]['distance'] = c
            Routers[j][i]['distance'] = c
            Routers[i][j]['NextHop'] = j
            Routers[j][i]['NextHop'] = i
    return Routers

def generateFloodPacket(entity,RoutingTable,SequenceNo,Age):
    FloodPacket = { 'entity':entity , 'RoutingTable':RoutingTable, 'SequenceNo':SequenceNo, 'Age':Age}
    return FloodPacket


def flooding_Stage(Routers,N,Router_id,FloodPacket):
    Stack = []
    for i in range(0,N):
        if FloodPacket['RoutingTable'][i]['distance']!=math.inf and Router_id!=i and FloodPacket['SequenceNo']!=Sequence_List[i]:
            Stack.append(i)
            print(Stack)
    Sequence_List[Router_id] = FloodPacket['SequenceNo']
    for i in range(0,N):
        if FloodPacket['RoutingTable'][i]['distance']!=math.inf and Router_id!=i and FloodPacket['SequenceNo']!=Sequence_List[i]:
            Sequence_List[i]=FloodPacket['SequenceNo']
            for j in range(0,N):
                if(Routers[i][j]['distance'] > Routers[Router_id][i]['distance']+Routers[Router_id][j]['distance']):
                    Routers[i][j]['distance'] = Routers[Router_id][i]['distance']+Routers[Router_id][j]['distance']
                    Routers[i][j]['NextHop'] = Router_id
    while(len(Stack) > 0):       
        x = Stack.pop()        
        FloodPacket = generateFloodPacket(Router_id,Routers[x],FloodPacket['SequenceNo'],FloodPacket['Age'])
        Routers=flooding_Stage(Routers,N,x,FloodPacket)
    

    return Routers

if __name__ == '__main__':
    routerCount = int(input("Enter the Number of routers"))
    Routers = []
    Routers = initialize_Router(Routers,routerCount)
    Routers = initializeWithLink(Routers,routerCount)
    ControlledFlooding(routerCount)
    print("Initial Network")
    print(json.dumps(Routers,indent=4))
    print("=========================================")
    print(" =============   ============   ===     ===    ==========")
    print(" ==         ==   ||         ||  |  \   |  |    ==")
    print(" ==         ==   ||         ||  |   \__|  |    ==========")
    print(" =============   ||_________||  |_________|    ==========")
    for i in range(0,routerCount): 
        print("Iteration ",i," ==========")
        FloodPacket=generateFloodPacket(i,Routers[i],i+1,1)
        Routers=flooding_Stage(Routers,routerCount,i,FloodPacket)
        print(json.dumps(Routers,indent=4))