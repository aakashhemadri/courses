package Manager;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Aakash Hemadri
 */
import Date.Date;

/**
 *
 * @author ymir
 */
public class GeneralManager extends Manager implements Comparable {
    
    private double revenue;
    
    /**
     *
     * @param basic_pay
     * @param date_of_join
     * @param date_of_birth
     * @param revenue
     */
    public GeneralManager(double basic_pay, Date date_of_join, Date date_of_birth, double revenue){
        super(basic_pay, date_of_join, date_of_birth);
        this.revenue = revenue; 
    }

    /**
     *
     * @return
     */
    @Override
    public double getSalary(){
        return (this.basic_pay + this.revenue*0.1);
    }

    /**
     *
     * @return
     */
    @Override
    public String toString(){
        return "General Manager with revenue: " + String.valueOf(this.revenue) + " with salary of " + String.valueOf(this.getSalary());
    }

    /**
     *
     * @param O
     * @return
     */
    @Override
    public int compareTo(Object O ){ 
        Manager M = ((Manager)O);
        return this.date_of_join.compareTo(M.date_of_join);
    }
}
