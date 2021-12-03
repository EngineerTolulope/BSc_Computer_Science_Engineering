/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Nafisa.py;

/**
 *
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Animal p = new Animal("Chicken", 2, false);
        Fish nafisa= new Fish("Tuna", true);
        System.out.println(p);
        System.out.println(nafisa);
        Animal x = new Animal ("Chicken",5,true);
        System.out.println(IsitSame(p, x)? "Same Names" :"Different Names");
    }
    
    public static boolean IsitSame(Animal nafisa,Animal Simple){
        return nafisa.getName() == Simple.getName();
    }
    
}
