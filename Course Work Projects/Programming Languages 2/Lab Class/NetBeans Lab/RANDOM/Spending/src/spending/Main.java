/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
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
        List<Expenses> expensesList = new ArrayList<>();

        File f = new File("data.txt");
        try {
            Scanner fsc = new Scanner(f);
            String line;

            Scanner ssc; // scanner to process one line
            int year, month, day;
            float price;
            String name;
            while (fsc.hasNextLine()) {//while there is a next line
                line = fsc.nextLine(); //read one line from the file
                ssc = new Scanner(line);
                ssc.useDelimiter("-"); //instead of reading till space, read till "-"
                year = ssc.nextInt();    //-11-15@book@34.50
                month = ssc.nextInt();   //   -15@book@34.50
                ssc.useDelimiter("@"); //   -15@book@34.50
                ssc.skip("-");         //    15@book@34.50
                day = ssc.nextInt();     //      @book@34.50
                name = ssc.next();       //           @34.50
                //ssc.skip("@");         //            34.50
                price = ssc.nextFloat();
                // test if the read went OK
                //System.out.print("Read data: " + year + " " + month + " " + day);
                //System.out.println(" " + name + " " + price);
                
                    expensesList.add(new Expenses(name, price, new MyDate(year, month, day)));
                
                    System.err.println("Invalid date: " + year + " " + month + " " + day);
                   
                        expensesList.add(new Expenses(name, price, new MyDate(1999, 1, 1)));
                    
                    
                

            }//while
            
            for(Expenses e : expList){
            System.out.println(e);
        }
            printExpenses(expensesList);
            
            Collections.sort(expensesList);
            System.out.println("");
            printExpenses(expensesList);

        } catch (FileNotFoundException ex) {
            System.err.println("File not found...");
        }
    }
    
    public static void printExpenses(List<Expenses> expList){
        for(Expenses e : expList){
            System.out.println(e);
        }
    }

}
