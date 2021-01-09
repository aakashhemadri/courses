#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  3 10:31:58 2019

@author: Aakash Hemadri
"""
import numpy
from dijkstra import dijkstra

def init():
    '''Initialize graph.'''
    while True: 
        try:
            while True:
                try:
                    num_lan = int(input('-- Enter the number of LANs in the network topology!: ').split()[0])
                    print('-- Initializing Graph..')
                    #graph = [[0 for i in range(column)] for j in range(row)] 
                    graph = numpy.zeros((num_lan,num_lan),numpy.int8)
                    print(graph)
                    break
                except ValueError:
                    print(ValueError)
                    print('?? Incorrect input format!.\n!! Try Again!')                
                except MemoryError:
                    print(MemoryError)
                    print('?? Not Enough Memory.\n!! Try Again with lesser number of LANs')
            print("-- Initialized!")
            print("-- Updating Graph..")
            while True:
                try:
                    lan_conn = int(input("-- Enter the total number individual of connections(EDGES): ").split()[0])
                    break
                except ValueError:
                    print(ValueError)
                    print('?? Incorrect input format!.\n!! Try Again!')  
            print("-- Input connection relationships in this format <LAN_SPECIFIER> <LAN_SPECIFIER> <WEIGHT>: ")
            for i in range(lan_conn):
                while True:
                    try:
                        a,b,weight = map(str, input('-' + str(i + 1) + ' ').upper().split())
                        a = ord(a) - 65
                        b = ord(b) - 65
                        break
                    except(TypeError):
                        print(TypeError)
                        print("?? Expected character as input!\n!! Try Again!")
                    except ValueError:
                        print(ValueError)
                        print('?? Incorrect input format (or) input value!.\n!! Try Again!')
                    except IndexError:
                        print(IndexError)
                graph[a][b] = weight
                graph[b][a] = weight
            print(graph)
            print("-- Updated!")
            source = input("-- Enter source <LAN_SPECIFIER>: ")
            return [ graph, num_lan, lan_conn, source ]
        except Exception as e:
            print("?? Unhandled Exception!\n!! Exiting!")
            print(e)
            return  

def ask():
    graph = dijkstra(init())
    graph.algorithm()
    graph.print_dist()
        
def test():
    '''Test Unit'''
    ask()

if __name__=='__main__':
    test()