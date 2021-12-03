/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carsproject;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Car c = new Car("Toyota", "sedan", 2006, 3);
        /*System.out.println(c.getBrand());
        System.out.println(c.getType());
        System.out.println(c.getRegYear());
        System.out.println(c.getColorCode());*/
        
        System.out.println(c);
        c.setColorCode("gray");
        System.out.println(c);
    }
    
}
