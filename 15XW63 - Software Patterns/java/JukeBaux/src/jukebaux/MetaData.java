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
public class MetaData {
    private String name;
    private String artist;
    private String length;
    
    public MetaData( String name, String artist, String length){
        this.name = name;
        this.artist = artist;
        this.length = length;
    }
    
    public String getName(){
        return name;
    }
    public String getArtist(){
        return artist;
    }
    public String getLength(){
        return length;
    }
    
    @Override
    public String toString(){
        return "Name: " + name + "\nArtist: " + artist + "\nLength: " + length + "\n";
    }
}
