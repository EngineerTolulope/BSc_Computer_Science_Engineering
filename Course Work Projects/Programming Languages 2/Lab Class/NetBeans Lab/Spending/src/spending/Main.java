/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
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
      List<Expense> expensesList= new ArrayList<>();
      
      File f = new File ("data.txt");
        try {
            Scanner fsc = new Scanner (f);
            String line;
            
            Scanner ssc;
            int year, month, day;
            float price;
            String name;
            while (fsc.hasNextLine()){
                line = fsc.nextLine();
                ssc = new Scanner (line);
                ssc.useDelimiter("-");
                year = ssc.nextInt();
                month =ssc.nextInt();
                ssc.useDelimiter("@");
                ssc.skip("-");
                day = ssc.nextInt();
                name= ssc.next();
                price= ssc.nextFloat();
                
               // System.out.println("Read Data" + year + " " + month +" "+day);
                    try{
                        expensesList.add(new Expense (name, price, new My Date(year, month, day)));
                    }catch (InvalidDateException ex){
                        
                    }

            }
            
            
        } catch (FileNotFoundException ex) {
            System.err.println("File not Found...");
        }
        
    }
    
}
