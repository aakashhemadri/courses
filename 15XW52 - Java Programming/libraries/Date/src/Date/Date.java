/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Date;
import java.time.LocalDateTime;
import java.lang.Integer;
/**
 *
 * @author 17pw01
 */
public class Date implements Comparable {
    private Integer day;
    private Integer month;
    private Integer year;
    
    public Date(){
        LocalDateTime now = LocalDateTime.now();
        setDate(now.getDayOfMonth(), now.getMonthValue(), now.getYear());
    }
    public Date(int day, int month, int year){
        if(setDate(day, month, year) == false ){
            LocalDateTime now = LocalDateTime.now();
            setDate(now.getDayOfMonth(), now.getMonthValue(), now.getYear());
        }
    }
    public boolean setDate(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
        return true;
    }
    public Date addDays(int days){
        Date D = new Date();
        return D;
    }
    @Override
    public int compareTo(Object O){
        if(O instanceof Date){
            Date D = ((Date)O);
            if(this.year.compareTo(D.year) == 0){
                if(this.month.compareTo(D.month) == 0){
                    return this.day.compareTo(D.day);
                }
                else{
                    return this.month.compareTo(D.month);
                }
            }
            else {
                return this.year.compareTo(D.year);
            }
        }
        return 0;
    }
    public Integer difference(Date D){
        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
  
        //Starting from date 1-1-1970
        return this.day;
    }
    @Override
    public String toString(){
        return String.valueOf(this.day) + "/" + String.valueOf(this.month) + "/" + String.valueOf(this.year);
    }
    @Override
    public boolean equals(Object O){
        return (O instanceof Date && this.day == (((Date)O).day) && this.month == ((Date)O).month && this.year == ((Date)O).year);
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 59 * hash + this.day;
        hash = 59 * hash + this.month;
        hash = 59 * hash + this.year;
        return hash;
    }
    public boolean isLeapYear(){
       if(this.year % 4 == 0 && (this.year % 100 != 0 || this.year % 400 == 0))
           return true;
       else
           return false;
    }/*
    private int getDays(){
        Date O = new Date(1,1,1970);
        int days = 0;
        while(O.year<this.year){
            if(O.isLeapYear()){
                days += 366;
                O.setDate(O.getDay(),O.getMonth(),O.getYear()+1);
            }
            else {
                days += 365;
                O.setDate(O.getDay(),O.getMonth(),O.getYear()+1);
            }
        }
        if(this.isLeapYear()){
            while(O.getMonth()<this.getMonth()){
                if(O)
            }
        }
        
        return days;
    }*/
    public int getDay(){
        return this.day;
    }
    public int getMonth(){
        return this.month;
    }
    public int getYear(){
        return this.year;
    }
}