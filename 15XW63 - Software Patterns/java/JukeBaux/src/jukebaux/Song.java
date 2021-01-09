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
public interface Song {
    MetaData getMetaData();
    SongType getType();
    @Override
    public String toString();
}
