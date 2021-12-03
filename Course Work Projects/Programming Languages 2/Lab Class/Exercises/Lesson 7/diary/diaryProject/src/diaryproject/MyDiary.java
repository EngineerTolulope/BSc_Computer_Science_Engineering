/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package diaryproject;

import java.util.Vector;

/**
 *
 * @author kocsisg
 */
public class MyDiary implements Diary { //Ex 2. implement the Diary interface

    private Vector<Entry> v = new Vector();
    
    @Override
    public void addEntry(Entry e) {
        for (int i = 0; i < v.size(); i++) {
            if (v.elementAt(i).equals(e)) {//Ex 9. Concatenate instead of adding a new element
                v.elementAt(i).setText( v.elementAt(i).getText() + e.getText() );
                return;
            }//if
        }//for
        v.add(e);
    }//addEntry

    @Override
    public void printAllEntries() {
        for (Entry e : v) { //go through all elements of the Vector
            System.out.println(e);
        }//for
    }//printAllEntries
    
}//MyDiary class
