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
public class MyDiary implements Diary {

    private ArrayList<Entry> entries = new ArrayList<>(); //the variable name is entries
    @Override
    public void addEntry(Entry e) {
        if (entries.contains(e)){
            int i= entries.indexOf(e);
            String text = entries.get(i).getText() + e.getText() +"\n";
            e.setText(text);
            
            entries.remove(i);
            entries.add(i, e);
        }
        else entries.add(e);
        
    }

    @Override
    public void printAllEntries() {
        for (Entry e : entries) {
            System.out.println(e);
            
        }
    }

}
