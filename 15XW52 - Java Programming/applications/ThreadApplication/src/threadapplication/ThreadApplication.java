/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package threadapplication;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 17pw04
 */
class Counter{
    int count;
    
    Counter(int x){
        count = x;
    }
    
    synchronized public void incrementCount(){
        count+=1;
    }
    
    synchronized public void decrementCount(){
        count-=1;
    }
    
    synchronized public int getValue(){
        return count;
    }
}

class IncrementThread extends Thread{
    
    Counter c;
    IncrementThread(Counter temp){
        c = temp;
    }
    
    public void run(){
        for(int i=0;i<200;i++){
            c.incrementCount();
        }
    }
 
}

class DecrementThread extends Thread{
    
    Counter c;
    DecrementThread(Counter temp){
        c = temp;
    }
    
    public void run(){
        for(int i=0;i<200;i++){
            c.decrementCount();
        }
    }
}



public class ThreadApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        // TODO code application logic here
        Counter countx = new Counter(0);
        IncrementThread t1 = new IncrementThread(countx);
        DecrementThread t2 = new DecrementThread(countx);
        
        t1.start();
        t2.start();
        t1.join();

    }
    
}
