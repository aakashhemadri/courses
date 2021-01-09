/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calenderapplication;
import dateapplication.Date;
import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author 17pw04
 */

public class CalenderApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Date date = new Date(31,12,2019);
        Time time = new Time(23,59,50);
        Calender calender = new Calender(date,time);
        Timer t1 = new Timer(calender);
        DisplayTime t2 = new DisplayTime(calender);
        t1.start();
        t2.start();
        try {
            t2.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(CalenderApplication.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
        
}
    

