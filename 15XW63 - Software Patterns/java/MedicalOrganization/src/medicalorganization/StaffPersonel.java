/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package medicalorganization;

/**
 *
 * @author 17pw01
 */
public class StaffPersonel implements Personel{
    public String name;
    public String ID;
    
    @Override
    public PersonelType getType(){
        return PersonelType.Staff;
    }
    @Override
    public String getName(){
        return this.name;
    }
    @Override
    public String getID(){
        return this.ID;
    }
    @Override
    public String toString(){
        return "Name: " + this.name + "\nID: " + this.ID;
    }
}
