/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proconsumerapplication;

import static java.lang.Thread.sleep;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Queue;
import java.util.LinkedList;

/**
 *
 * @author 17pw04
 */
class Q{
    final int MAX_SIZE = 100;
    Queue<Integer> n = new LinkedList<>();
    boolean isAvailable;
    
    Q(){
      isAvailable = false;  
    }
    
    synchronized public void put(int x){
        while(isAvailable){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Q.class.getName()).log(Level.SEVERE, null, ex);
            }
            if(n.size() < MAX_SIZE){
                this.n.add(x);
                isAvailable = true;
            }else if(n.size() >= MAX_SIZE){
                isAvailable = true;
            }
        }
        this.n.add(x);
        notifyAll();
    }
    
    synchronized public Integer[] get(int need){
        while(!isAvailable && need >this.n.size()){
            try {
                wait();
            } catch (InterruptedException ex) {
                Logger.getLogger(Q.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        Integer[] arr = new Integer[need];
        for(int i=0;i<need;i++){
            arr[i] = n.remove();
        }
        if(this.n.size() <= 0)
            this.isAvailable = false;
        notifyAll();
        return arr;
    }
}


class Consumer implements Runnable{
    
    Q q;
    int need;
    String name;
    Consumer(Q q,int x,String name){
        this.q = q;
        this.need = x;
        this.name = name;
    }
    
    @Override
    public void run(){
        Integer[] x;
        while(true){
           x = q.get(need);
           System.out.println(this.name+":"+Arrays.toString(x));
            try {
                sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}


class Producer implements Runnable{
    
    Q q;
    String name;
    Producer(Q q, String name){
        this.q = q;
        this.name = name;
    }
    
    @Override
    public void run(){
        int i=0;
        while(true){
            try {
                q.put(i);
                System.out.println(this.name+":"+i);
                i++;
                sleep(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}


public class ProConsumerApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Q q = new Q();
        Producer p1 = new Producer(q,"Producer");
        Consumer c1 = new Consumer(q,1,"Consumer1");
        Consumer c2 = new Consumer(q,2,"Consumer2");
        Thread t1 = new Thread(p1,"Producer");
        Thread t2 = new Thread(c1,"Consumer1");
        Thread t3 = new Thread(c2,"Consumer2");
        t1.start();
        t2.start();
        t3.start();
        try {
            t1.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(ProConsumerApplication.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
