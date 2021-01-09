/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Stack;

/**
 *
 * @author 17pw01
 */
public class Stack {
    private int array[];
    private int top;
    private int size;
    public Stack(int size){
        this.array = new int[size];
        this.top = -1;
        this.size = size;
    }
    public boolean push(int element){
    //Pushes element to top
    if(this.top == this.size - 1){
        return false;
    }
    else{
        this.array[this.top+1] = element;
        this.top = this.top + 1;
    }
    return true;
    }
    public boolean pop(){
    //
    if(this.top == -1){
        return false;
    }
    else
        {
        this.top = this.top - 1;
    }
    return true;
    }
    public int top(){
    return top;
    }
}
