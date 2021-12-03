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
        Train t1= new Train ("Debrecen@Budapest Keleti@13:10@IC");
        Train t2= new Train ("Debrecen@Eger@13:30");
        
        System.out.println(t1+ "\n"+ t2);
        
        File f = new File("trains.txt");
        try {
            ArrayList<Train> trainslist = new ArrayList<>();
            Scanner fsc = new Scanner(f);
            
            String line;
            Train tt;
            while(fsc.hasNextLine()){
                line = fsc.nextLine();
            
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
