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
public class AppleSong implements Song{
    MetaData metaData;
    
    public AppleSong(String name, String artist, String length){
        metaData = new MetaData(name,artist,length);
    }
    public AppleSong(MetaData m){
        metaData = m;
    }
    
    @Override
    public MetaData getMetaData(){
        return metaData;
    }
    
    @Override
    public SongType getType(){
        return SongType.Apple;
    }
    
    @Override
    public String toString(){
        return "Type: " + SongType.Apple + "\n" + metaData.toString();
    }
}
