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
import Manager.Manager;
import Date.Date;

/**
 *
 * @author ymir
 */
public class SalesManager extends Manager implements Comparable{
    private int no_of_sales;

    /**
     *
     * @param basic_pay
     * @param date_of_join
     * @param date_of_birth
     * @param no_of_sales
     */
    public SalesManager(double basic_pay, Date date_of_join, Date date_of_birth, int no_of_sales){
        super(basic_pay, date_of_join, date_of_birth);
        this.no_of_sales = no_of_sales;
    }

    /**
     *
     * @return
     */
    @Override
    public double getSalary(){
        return (this.basic_pay + this.no_of_sales*0.1);
    }

    /**
     *
     * @return
     */
    @Override
    public String toString(){
        return "Sales Manager with number of sales: " + String.valueOf(this.no_of_sales) + " with salary of " + String.valueOf(this.getSalary());
    }

    /**
     *
     * @param O
     * @return
     */
    @Override
    public int compareTo(Object O ){ 
        Manager M = ((Manager)O);
        return (this.date_of_join).compareTo(M.date_of_join);
    }
}
