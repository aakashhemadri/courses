/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jukebaux;

/**
 *
 * @author 17pw01
 */
public class JukeBaux {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SongFactory f = new SongFactory();
        Song s = f.create(SongType.Apple, new MetaData("The Scientist", "Coldplay", "2.45"));
        System.out.println(s);
    }
}
