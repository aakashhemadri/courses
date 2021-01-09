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
public interface Personel {
    public String getName();
    public String getID();
    public PersonelType getType();
    @Override
    public String toString();
}
