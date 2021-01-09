/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Student;
import Date.Date;
import Student.Student;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author 17pw01
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList accomplishments = new ArrayList();
        ArrayList a1 = new ArrayList();
        a1.add("descA");
        a1.add(new Date(10,11,2000));
        a1.add(new Date(10,4,2009));
        accomplishments.add(a1);
        ArrayList a2 = new ArrayList();
        a2.add("descB");
        a2.add(new Date(10,6,2000));
        a1.add(new Date(10,3,2006));
        accomplishments.add(a2);
        
        Student S1 = new Student("Bakash", "Hemadri", "17PW01",new Date(10,11,1999), accomplishments);
        Student S2 = new Student("Aravind", "RM", "17PW06", new Date(17,9,1999), accomplishments);
        List list = new ArrayList();
        list.add(S1);
        list.add(S2);
        list.sort(new CompareByDate());
        System.out.println("CompareByDate:\n" + list);
        list.sort(new CompareByRoll());
        System.out.println("CompareByRoll:\n" + list );
        list.sort(new CompareByName(0));
        System.out.println("CompareByName - First Name:\n" + list + "\n");
        list.sort(new CompareByName(1));
        System.out.println("CompareByName - Second Name:\n" + list + "\n");
    }
    
}
