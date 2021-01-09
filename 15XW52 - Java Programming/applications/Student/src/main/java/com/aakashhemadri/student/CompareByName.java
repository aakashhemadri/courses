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
public class CompareByName implements Comparator{
    private Integer option;
    CompareByName(int option){
        this.option = option;
    }
     @Override
     public int compare(Object O, Object N){
        if( O instanceof Student && N instanceof Student){
            if(this.option == 0){
                return (((Student)O).first_name).compareTo(((Student)N).first_name);
            }
            else if (this.option == 1 ){
                return (((Student)O).last_name).compareTo(((Student)N).last_name);
            }
             
        }
        return 0;
    }
}
