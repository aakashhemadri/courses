/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calenderapplication;

import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 17pw04
 */
public class Time {
    int hour,mins,sec;
    
    public Time(){
        hour=0;
        mins=0;
        sec=1;
    }
    
    public Time(int hh,int mm,int ss){
        hour = hh;
        mins = mm;
        sec = ss;
    }
    
    public boolean IncrementSec(){
        sec=sec+1;
        if(sec == 60){
            sec = 0;
            mins+=1;
            if(mins==60){
                mins=0;
                hour+=1;
                if(hour == 24){
                    hour = 0;
                    return false;
                }
            }
        }
        return true;
    }
    
    @Override
    public String toString(){
        return hour+":"+mins+":"+sec;
    }
    
    public boolean equals(Time t){
        if(this.hour == t.hour && this.mins == t.mins && this.sec == t.sec){
            return true;
        }
        return false;
    }
    
}



class DisplayTime extends Thread{
    
    Calender calender;
    DisplayTime(Calender c){
        calender = c;
    }
    
    public void run(){
        while(true){
            try {
                System.out.println(calender);
                sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(DisplayTime.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
