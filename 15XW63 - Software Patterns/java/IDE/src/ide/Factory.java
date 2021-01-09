/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ide;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author 17pw01
 */
class Factory {
    private static final Map<String, Language> prototypes = new HashMap<>();

    static {
        prototypes.put("cpp", new CPP());
        prototypes.put("java", new Java());
        prototypes.put("python", new Python());
    }

    public static Language getPrototype(LanguageType type) {
        try {
            return prototypes.get(type).clone();
        } catch (NullPointerException ex) {
            System.out.println("Prototype with name: " + type + ", doesn't exist");
            return null;
        }
    }
}
