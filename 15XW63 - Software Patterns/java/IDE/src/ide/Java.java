/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ide;

/**
 *
 * @author 17pw01
 */
public class Java implements Language {
    private final String name = "Java";

    @Override
    public Language clone() {
        return new Java();
    }

    @Override
    public String toString() {
        return this.name;
    }
}
