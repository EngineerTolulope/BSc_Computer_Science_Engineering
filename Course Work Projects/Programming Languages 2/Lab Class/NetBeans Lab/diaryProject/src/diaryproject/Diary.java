/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package diaryproject;

/**
 * Implementations of this interface can represent a diary.
 * @author kocsisg
 */
public interface Diary {
    /**
     * Adds a new eEntry to the diary
     * @param e The entry to be added.
     */
    public void addEntry(Entry e);
    
    /**
     * Prints out all entries of the diary. It preferably uses the toString method of the Entry class.
     */
    public void printAllEntries();
}
