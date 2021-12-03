/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending2;

import static java.awt.JobAttributes.DestinationType.FILE;
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
         List <Expenses> explist = new ArrayList<>(); 
         File f = new File("data.txt");
         Scanner fsc;
         int year,day,month;
         String name;
         float price;
        try {
            fsc = new Scanner (f);
            String line = null;
            Scanner lin= new Scanner (line);
            while (fsc.hasNextLine()){
                line = fsc.nextLine();
                lin.useDelimiter("-");
                year = lin.nextInt();//-11-15
                month = lin.nextInt();//-15@book
                lin.useDelimiter("@");
                lin.skip("-");//15@book
                day = lin.nextInt();//@book
                name= lin.next();
                price= lin.nextFloat();
                
                try {
                    explist.add(new Expenses(name,price , new Date(day,month,year) ));
                } catch (InvalidDateException ex) {
                    System.out.println("No Date good");// Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                }
                
               print(explist);
                
                
            }
        } catch (FileNotFoundException ex) {
            System.out.println("File not found");
        }
    }
    
    public static void print(List <Expenses> explist){
         for(Expenses e :explist){
                    System.out.println(e);
                }
    }
    
}
