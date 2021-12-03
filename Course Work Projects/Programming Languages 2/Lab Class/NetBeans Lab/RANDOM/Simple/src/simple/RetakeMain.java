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
 * @author student
 */
public class RetakeMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Garage g = new Garage();
        Car c1 = null;
        try {
            c1 = new Car("Suzuki", 13, "LOL-999");
        } catch (InvalidAgeException ex) {
            System.out.println("Negative age given.");
        }
        g.add(c1);

        Scanner sc = new Scanner(System.in);
        //read the number of Cars the user will provide
        System.out.print("Number of cars: ");
        int num = sc.nextInt();

        for (int i = 0; i < num; i++) {
            Car c2 = null;
            try {
                c2 = new Car(null, 0, null);
                System.out.print("Brand: ");
                c2.setBrand(sc.next());

                System.out.print("Age: ");
                c2.setAge(sc.nextInt());
            } catch (InvalidAgeException ex) {
                System.out.println("Negative age given. Adde with default age.");
                try {
                    c2.setAge(0);
                } catch (InvalidAgeException ex1) {
                }
            }//try-catch    
            
            System.out.print("ID: ");
            c2.setID(sc.next());

            g.add(c2);

        }//for
        
        g.print();
    }//main

}//Main class
