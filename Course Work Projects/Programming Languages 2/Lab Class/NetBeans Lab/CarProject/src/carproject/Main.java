/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carproject;

/**
 *
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Car c= new Car("toyota", "sedan", 2006, 3);
        System.out.println(c);
        c.setColorcode("gray");
        System.out.println(c);
    }
    
}
