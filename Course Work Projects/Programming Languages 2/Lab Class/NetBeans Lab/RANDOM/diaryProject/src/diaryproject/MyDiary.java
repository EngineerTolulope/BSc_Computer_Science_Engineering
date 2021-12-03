/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diaryproject;

import java.util.ArrayList;

/**
 *
 * @author Tboy Simple
 */
public class MyDiary extends ArrayList<Entry> implements Diary {

    ArrayList<Entry> entries = new ArrayList<Entry>();
    @Override
    public void addEntry(Entry e) {
        entries.add(e);
    }

    @Override
    public void printAllEntries() {
        for (Entry i : entries){
            System.out.println(i);
        }
    }
    
}
