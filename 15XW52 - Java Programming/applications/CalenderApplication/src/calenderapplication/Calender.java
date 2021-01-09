/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calenderapplication;

import dateapplication.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 17pw04
 */
public class Calender {
    Time time;
    Date Date_d;
    boolean tick;
    
    public Calender(Date d,Time T){
       Date_d = d;
       time = T;
       tick = false;
    }
    
    synchronized public boolean tick(){
        if(!time.IncrementSec()){
            Date_d.IncrementDate();
        }
        
/*        tick = true;
        try {
            wait();
        } catch (InterruptedException ex) {
            Logger.getLogger(calenderapplication.Calender.class.getName()).log(Level.SEVERE, null, ex);
        }
        tick = false;*/
        
        return true;
    }
    
    @Override
    synchronized public String toString(){
//        if(tick == true){
            notify();
            return Date_d+" "+time;
//        }
 //       return "";
    }
    
    synchronized public boolean equals(Calender d){
        if(this.Date_d.equals(d) && time.equals(d.time)){
            return true;
        }
        return false;
    }
}
