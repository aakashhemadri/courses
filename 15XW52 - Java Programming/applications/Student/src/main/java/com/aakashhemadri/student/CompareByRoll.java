/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Student;

import java.util.Comparator;
/**
 *
 * @author 17pw01
 */
public class CompareByRoll implements Comparator{
     @Override
     public int compare(Object O, Object N){
        if( O instanceof Student && N instanceof Student){
             return (((Student)O).roll_number).compareTo(((Student)N).roll_number);
        }
        return 0;
    }
}