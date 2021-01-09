/**
* Package Manager  
*/
package Manager;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import Date.Date;
import java.util.List;
import java.util.ArrayList;
/**
 * Manager is an abstract class for variants of Managers
 * @version 0.0.1
 * @author Aakash Hemadri
 */
public abstract class Manager{

    /**
     * Basic pay for a Manager.
     */
    protected double basic_pay;
    
    /**
     * Date of join of manager in company.
     */
    protected Date date_of_join;

    /**
     * 
     */
    protected Integer experience;
    private final Date date_of_birth;
    private List start_date;
    private List end_date;
    
    /**
     *
     * @param basic_pay
     * @param date_of_join
     * @param date_of_birth
     */
    public Manager(double basic_pay, Date date_of_join, Date date_of_birth){
        this.basic_pay = basic_pay;
        this.date_of_join = date_of_join;
        this.date_of_birth = date_of_birth;
        this.start_date = new ArrayList();
        this.end_date = new ArrayList();
    }

    /**
     *
     * @return the salary of manager.
     */
    abstract public double getSalary(); 

    /**
     * Calculates experience of manager based on the start_date & end_date
     * @return Experience of manager in number of years.
     * @since 0.0.1
     * @version 0.0.1
     */
    public Integer getExperience(){
        return this.experience;
    }

    /**
     * Provides date of birth of manager.
     * @return the data of birth of manager.
     */
    public Date getDateOfBirth(){
        return this.date_of_birth;
    }

    /**
     *
     * @return
     */
    public Date getDateOfJoin(){
        return this.date_of_join;
    }

    /**
     *
     * @param startDate
     * @param endDate
     * @return
     * @throws ArithmeticException
     */
    public boolean addExperience(Date startDate, Date endDate) throws ArithmeticException{
        if(startDate.compareTo(endDate) > 0){
            throw new ArithmeticException("End date less than start date\nOn entry number: " + String.valueOf(this.start_date.size() + 1 ) );
        }
        this.experience += startDate.difference(endDate);
        this.start_date.add(startDate);
        this.end_date.add(endDate);
        return true;
    }
}
