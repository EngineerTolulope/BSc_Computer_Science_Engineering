/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simple;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tboy Simple
 */
public class RetakeMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Garage g = new Garage();
        Car c1= null;
        try {
             c1= new Car("Suzuki", 13, "LOL-999");
        } catch (InvalidAgeException ex) {
            
        }
        g.add(c1);
        
        Scanner sc= new Scanner (System.in);
        System.out.println("Number of cars: ");
        int num = sc.nextInt();
        
        for (int i=0; i<num ;i++){
            try {
                Car c2 = new Car (null, 0, null);
                
                System.out.println("Brand: ");
                c2.setBrand(sc.next());
                
                System.out.println("Age: ");
                c2.setAge(sc.nextInt());
                
                System.out.println("ID: ");
                c2.setId(sc.next());
                
                g.add(c2);
            } catch (InvalidAgeException ex) {
                
            }
        }
        
        g.print();
    }
    
}
