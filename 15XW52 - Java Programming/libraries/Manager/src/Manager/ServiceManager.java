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
public class ServiceManager extends Manager implements Comparable{
    private int people_serviced;
   
    /**
     *
     * @param basic_pay
     * @param date_of_join
     * @param date_of_birth
     * @param people_serviced
     */
    public ServiceManager(double basic_pay, Date date_of_join,  Date date_of_birth, int people_serviced){
        super(basic_pay, date_of_join, date_of_birth);
        this.people_serviced = people_serviced;
    }

    /**
     *
     * @return
     */
    public double getSalary(){
        return (this.basic_pay + this.people_serviced*0.1);
    }

    /**
     *
     * @return
     */
    @Override
    public String toString(){
        return "Service Manager with number of people serviced: " + String.valueOf(this.people_serviced) + " with net salary of " + String.valueOf(this.getSalary());
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
