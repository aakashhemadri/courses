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
public class IDE {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if (args.length > 0) {
            Language prototype = null;
            for (String file : args) {
                String format = file.substring(file.indexOf('.') + 1, (file.length()));
                switch(format){
                    case "cpp":
                        prototype = Factory.getPrototype(LanguageType.CPP);
                        if (prototype != null) {
                            System.out.println(prototype);
                        }
                    case "java":
                        prototype = Factory.getPrototype(LanguageType.Java);
                        if (prototype != null) {
                            System.out.println(prototype);
                        }
                    case "py":
                        prototype = Factory.getPrototype(LanguageType.Python);
                        if (prototype != null) {
                            System.out.println(prototype);
                        }  
                    default:
                        if (prototype != null) {
                            System.out.println(prototype);
                        } 
                }
            }
        } else {
            System.out.println("Run again with arguments of command string ");
        }
    }
    
}
