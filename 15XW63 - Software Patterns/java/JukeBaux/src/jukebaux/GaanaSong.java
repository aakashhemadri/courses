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
public class GaanaSong implements Song {
    MetaData metaData;
    
    public GaanaSong(String name, String artist, String length){
        metaData = new MetaData(name,artist,length);
    }
    public GaanaSong(MetaData m){
        metaData = m;
    }
    
    @Override
    public MetaData getMetaData(){
        return metaData;
    }
    
    @Override
    public SongType getType(){
        return SongType.Gaana;
    }
    
    @Override
    public String toString(){
        return "Type: " + SongType.Gaana + "\n" + metaData.toString();
    }
}
