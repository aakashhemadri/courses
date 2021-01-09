/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calenderapplication;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 17pw04
 */
public class Timer extends Thread{
    
     Calender calender;
    public Timer(Calender c){
        calender = c;
    }
    
    @Override
    public void run(){
       while(true){
        calender.tick();
           try {
               sleep(900);
           } catch (InterruptedException ex) {
               Logger.getLogger(Timer.class.getName()).log(Level.SEVERE, null, ex);
           }
       }
    }
    
}
