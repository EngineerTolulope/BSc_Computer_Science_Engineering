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
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Train t1= new Train("Debrecen@Eger@13:25@");
        System.out.println(t1);
        Train t2= new Train("Debrecen@Miskolc@14:23@IC");
        System.out.println(t2);
        
     ArrayList<Train> trainList = new ArrayList<>();
     File f = new File ("trains.txt");
     
   
    
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
                trainList.add( newTrain );
            }
            
        } catch (FileNotFoundException ex) {
            System.out.println("File not found...");
        }
        }
        for (Train tt: trainList){
            System.out.println(tt);
        }

    }
    
}
