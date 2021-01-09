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

public class SystemOfEquations{
    private LinearEquation equation1;
    private LinearEquation equation2;
    
    public SystemOfEquations(String equation1,String equation2){
        this.equation1 = new LinearEquation(equation1);
        this.equation2 = new LinearEquation(equation2);
    }
   
    public int solveEquation(){
        /*int[] coefficient1 = equation1.coefficient;
        int[] coefficient2 = equation2.coefficient;
        int e = equation1.constant;
        int f = equation2.constant;
        int[] ans = {0,0};
        
        double determinant = ((coefficient1[0]*coefficient2[1]) - (coefficient1[1]*coefficient2[0]));
        
        ans[0] = (int)(((coefficient2[1]*e)-(coefficient1[1]*f))/determinant);
        ans[1] = (int)(((coefficient1[0]*f)-(coefficient2[0]*e))/determinant);
        
        System.out.println(ans[0] + " " + ans[1]);
        return ans;*/
        return 0;
    }
    
}
