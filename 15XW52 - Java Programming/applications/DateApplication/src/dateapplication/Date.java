/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dateapplication;
/**
 *
 * @author 17pw04
 */
public class Date implements Comparable<Date>{
    int day,month,year;
    public Date(int dayElement,int monthElement,int yearElement){
        day = dayElement;
        month = monthElement;
        year = yearElement;
    }
    
    public boolean IncrementDate(){
        int tempDate = day+1;
        if(tempDate<DateCount(this)){
            day = day+1;
        }else{
            day = 1;
            int tempMonth = month+1;
            if(tempMonth>12){
                month = 1;
                year +=1;
            }else{
                month+=1;
            }
        }
        return true;
    }
    
    private int DateCount(Date date){
        int month = date.month;
        int NumberDays;
        if((date.month>7 && date.month%2==0) || (date.month<=7 && date.month%2==1)){
            NumberDays=31;
        }else{
                if(date.month!=2){
                    NumberDays=30;
                }else{
                    NumberDays= (date.year%4==0 || date.year%400==0)?29:28;
                }
        }
        return NumberDays;
    }
    
    private int CountDayInMonth(Date date){
        int NumberDays = 0;
        int month = date.month-1;
        while(month>=0){
         if((date.month>7 && date.month%2==0) || (date.month<=7 && date.month%2==1)){
            NumberDays+=31;
          }else{
                if(date.month!=2){
                    NumberDays+=30;
                }else{
                    NumberDays += (date.year%4==0 || date.year%400==0)?29:28;
                }
            }
         month--;
        }   
        return NumberDays;
    }
    
    private int CountDayInYear(Date date){
        int NumberofDays = 0;
        int year = date.year-1;
        while(year>=0){
            if(year%4 == 0 || year%400 == 0){
                NumberofDays+=366;
                year--;
            }else{
                NumberofDays+=365;
                year--;
            }
        }
        return NumberofDays;
    }
    /**
     * 
     * @param date
     * Object o
     * @return 
     * Provides you with Difference between 2 dates from the give dates
     */
    
    public int DaysElapsed(Date date){
        
        int NumberOfDays1 = CountDayInYear(date)+CountDayInMonth(date)+date.day;
        int NumberOfDays2 = CountDayInYear(this)+CountDayInMonth(this)+this.day;
        return (NumberOfDays1>NumberOfDays2)?NumberOfDays1-NumberOfDays2:NumberOfDays2-NumberOfDays1;
    }
    
    public int DaysElapsedInYear(Date date){
        int dayscount = DaysElapsed(date);
        return dayscount/365;
    }
    
    @Override
    public String toString(){
        return day+"/"+month+"/"+year;
    }
    
    @Override
    public int compareTo(Date date){
        if((date.year > year) || (date.month > month && date.year >= year) || (date.day > day && date.month >= month && date.year>=year)){
            return 1;
        }else if((date.year < year) || (date.month < month && date.year <= year) || (date.day < day && date.month <= month && date.year<=year)){
            return -1;
        }else{
            return 0;
        }
    }
    public boolean equals(Date date){
        return ((date.day == day) && (date.month==month) && (date.year==year));
    }
    
}
