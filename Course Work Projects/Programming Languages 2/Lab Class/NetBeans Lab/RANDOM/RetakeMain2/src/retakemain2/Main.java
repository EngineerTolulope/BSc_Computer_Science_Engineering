/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package retakemain2;

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
        Garage g = new Garage();
        Car c= null;
        try {
            c=new Car("Suzuki",13 ,"LOL-999");
            g.add(c);
            } catch (InvalidAgeException ex) {
            System.out.println("No negative age...");
        }
         Scanner ssc = new Scanner (System.in);
         System.out.println("Give me an integer number");
         int num=ssc.nextInt();
         
         for (int i = 0; i < num; i++) {
            Car f;
            try {
                f = new Car (null, 0, null);
                System.out.print("Give me a brand");
             f.setBrand(ssc.next());
             System.out.print("Give me the age");
            try {
                f.setAge(ssc.nextInt());
            } catch (InvalidAgeException ex) {
                System.out.println("Negative age given");
            }
             
             System.out.print("Give me the id");
             f.setId(ssc.next());
             g.add(f);
            } catch (InvalidAgeException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }
             
        }
         g.print();
         
    }
    
}
