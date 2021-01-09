import sys
import os

path = []
router_matrix = []
matrix_set = 0
nodes = []
distances = []
start = []
end = []

def print_choices():
    print ("######################################################")
    print ("\nDistance Vector Routing Simulator\n")
    print ("(1) Input Network Topology File")
    print ("(2) Build a Connection Table")
    print ("(3) Shortest Path to Destination Router")
    print ("(4) Exit")
    print ("\n######################################################\n")
    pass

def check_choices(choice):
    if not choice.isdigit():
        print("Please enter a valid number and try again")
        return False
    else:
        choice = int(choice)
        if (choice > 4) or choice < 1:
            print("Please enter a valid command from ")
            return False
        else:
            return choice

def input_topology():
    pass
    
def bellmanford():
    pass

def main():
    print("Starting simulation of distance vector protocol.")
    while (True):
        os.system("clear")
        print_choices()
        command = check_choices(input("Enter a command!"))
        if (command == 1):
            pass
        elif(command == 2):
            pass
        elif (command == 3):
            pass
        elif (command == 4):
            return True
        pass