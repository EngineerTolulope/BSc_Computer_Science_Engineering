/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diaryproject;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author kocsisg
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Diary d = new MyDiary();
        String date;
        String text;
        String line;

        
        //Raed entries from the diary file
        File f = new File("diary1.txt");
        try {
            Scanner fsc = new Scanner(f);
            if (fsc.hasNext()) {
                line = fsc.nextLine(); //read the first line of the file (<entry>)
            }
            while (fsc.hasNext()) { //read till we reach the end of file
                date = fsc.nextLine();//read the date
                text = "";
                while (true) {//read the text
                    if (fsc.hasNext()) {
                        line = fsc.nextLine();
                    } else {
                        break;
                    }
                    if (line.equals("<entry>")) {
                        break;
                    }
                    text = text.concat(line + "\n");
                }//while(true)
                d.addEntry(new Entry(date, text)); //add the new antry
            }//while
            d.addEntry(new Entry("11-26-2013", "This is a test"));
        } catch (FileNotFoundException ex) {
            System.out.println("No such file...");
        }//handle FileNotFoundException
        catch (WrongDateException ex) {
            System.out.println("The Date format is Wrong");
        }
        d.printAllEntries();
    }//main method    
}//Main class
