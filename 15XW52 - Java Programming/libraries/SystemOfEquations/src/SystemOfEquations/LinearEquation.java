/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SystemOfEquations;

/**
 *
 * @author 17pw01
 */

public class LinearEquation{
    private String equation;
    private int[] coefficient;
    private int constant;
    private char[] variables;
    
    public LinearEquation(String equation){
        this.equation = equation.replaceAll(" ","");
        this.coefficient = new int[2];
        this.variables = new char[2];
        int start = 0;
        int iter = 0;
        char[] eqn = equation.toCharArray();
        for(char ch : eqn){
            if(Character.isLetter(ch)){
                coefficient[iter] = Integer.parseInt(this.equation.substring(start, this.equation.indexOf(ch)),10);
                start = this.equation.indexOf(ch)+1;
                iter++;
            }
        }
        constant = Integer.parseInt(this.equation.substring(this.equation.indexOf('=')+1, this.equation.length()),10);
    }
    
    private boolean parseEquation(){
        return true;
    }
    
    @Override
    public String toString(){
        return String.valueOf(this.coefficient[0]) + String.valueOf(this.variables[0]) + " " + String.valueOf(this.coefficient[1]) + String.valueOf(this.variables[1]) + " = " + String.valueOf(this.constant);
    }
    

    
}
