/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Student;
import Date.Date;
import java.util.Objects;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author 17pw01
 */
public class Student implements Comparable{
    public String first_name;
    public String last_name;
    public String roll_number;
    public ArrayList accomplishments;
    public Integer experience;
    public Date dob;
    
    public Student(String first_name, String last_name, String roll_number, Date dob, ArrayList accomplishments){
        this.first_name = first_name;
        this.last_name = last_name;
        this.roll_number = roll_number;
        this.dob = dob;
        this.accomplishments = accomplishments;
        for(int iter = 0 ; iter< (this.accomplishments).size() ; iter++){
            this.experience += ((Date)((ArrayList)(this.accomplishments.get(iter))).get(1)).difference((Date)(((ArrayList)(this.accomplishments.get(iter))).get(2)));
        }
    }
    @Override
    public String toString(){
        return "Roll Number: " + String.valueOf(this.roll_number) + "\nName: " + this.first_name + " " + this.last_name + "\nDate of Birth: " + this.dob;
    }
    
    @Override
    public boolean equals(Object O){
        if(O instanceof Student){
            Student X = ((Student)O);
            if(this.roll_number.equals(X.roll_number) && this.first_name.equals(X.first_name) && this.roll_number.equals(X.roll_number) && this.dob.equals(X.dob))
                return true;
            }
            else {
                return false;
            }
       return false;
    }
    @Override
    public int hashCode() {
        int hash = 3;
        hash = 59 * hash + Objects.hashCode(this.first_name);
        hash = 59 * hash + Objects.hashCode(this.last_name);
        hash = 59 * hash + Objects.hashCode(this.roll_number);
        hash = 59 * hash + Objects.hashCode(this.dob);
        return hash;
    }
    
    @Override
    public int compareTo(Object O){
        if(O instanceof Student){
            return this.roll_number.compareTo(((Student)O).roll_number);
        }
        return -1;
    }
}

    
