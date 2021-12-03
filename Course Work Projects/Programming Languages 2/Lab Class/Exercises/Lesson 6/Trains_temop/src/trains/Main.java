/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trains;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Train t = new Train("Eger@Debrecen@12:35@IC");
        Train t2 = new Train("Budapest Keleti@Debrecen@13:10");
        System.out.println(t);
        System.out.println(t2);
        
        
        File f = new File("trains.txt");
        ArrayList<Train> trainsList = new ArrayList<>();
        
        try {
            Scanner fsc = new Scanner(f);
            
            /*while(fsc.hasNextLine()){
                trainsList.add( new Train(fsc.nextLine()) );
            }*/
            
            String line;
            Train newTrain;
            while(fsc.hasNextLine()){
                line = fsc.nextLine();
                newTrain = new Train(line);
                trainsList.add( newTrain );
            }
            
        } catch (FileNotFoundException ex) {
            System.out.println("File not found...");
        }
        
        for (Train tt : trainsList){
            System.out.println(tt);
        }
        
        
    }
    
}
