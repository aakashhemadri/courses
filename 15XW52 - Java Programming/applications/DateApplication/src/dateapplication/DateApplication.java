/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dateapplication;
import java.util.*;
import dateapplication.Date;
/**
 *
 * @author 17pw04
 */


public class DateApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ArrayList<Date> DateArray = new ArrayList<>(3);
        DateArray.add(new Date(26,12,1999));
        DateArray.add(new Date(21,7,1999));
        DateArray.add(new Date(10,1,2000));
        Collections.sort(DateArray);
        System.out.println(DateArray);
    }
    
}
