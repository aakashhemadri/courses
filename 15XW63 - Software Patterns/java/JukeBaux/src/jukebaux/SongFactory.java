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
public class SongFactory {
    public Song create(SongType type, MetaData m){
        switch(type){
            case Local:
                return new LocalSong(m);
            case Apple:
                return new AppleSong(m);
            case Spotify:
                return new SpotifySong(m);
            case Gaana:
                return new GaanaSong(m);
            default:
                return new LocalSong(m);
        }
    }
    public Song create(SongType type, String name, String artist, String length){
        switch(type){
            case Local:
                return new LocalSong(name, artist, length);
            case Apple:
                return new AppleSong(name, artist, length);
            case Spotify:
                return new SpotifySong(name, artist, length);
            case Gaana:
                return new GaanaSong(name, artist, length);
            default:
                return new LocalSong(name, artist, length);
        }
    }
}
