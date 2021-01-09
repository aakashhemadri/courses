/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Manager;

/**
 *
 * @author 17pw01
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 17pw01
 */
import Manager.Manager;
import Manager.GeneralManager;
import Manager.SalesManager;
import Manager.ServiceManager;
import Date.Date;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ymir
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        Manager[] M = new Manager[10];
        M[0] = new GeneralManager(100.0,new Date(10,1,2009), new Date(10,1,2009), 10.0);
        M[1] = new GeneralManager(100.0, new Date(12,6,2008), new Date(10,6,2019), 12.0);
        M[2] = new GeneralManager(100.0,new Date(1,7,2010),new Date(1,7,1970),14.0);
        M[3] = new SalesManager(100, new Date(1,8,2009), new Date(1,7,1989),16);
        M[4] = new SalesManager(100, new Date(7,10,2009),new Date(1,7,1999), 18);
        M[5] = new SalesManager(100, new Date(6,1,2009), new Date(1,7,1980),20);
        M[6] = new SalesManager(100, new Date(10,2,2008), new Date(1,7,1990),22);
        /* M[7] = new ServiceManager(100,24);
        M[8] = new ServiceManager(100,26);
        M[9] = new ServiceManager(100,28); */
        try {
            for(int i = 0; i<4 ; i++){
                if(M[i].addExperience(new Date(10,2,2008), new Date(1,7,1990)))
                    System.out.println(M[i]);
            }
        }
        catch(ArithmeticException E){
            System.out.println(E);
        }   
        List list = new ArrayList();
        list.add(M[0]);
        list.add(M[1]);
    }
    
}

