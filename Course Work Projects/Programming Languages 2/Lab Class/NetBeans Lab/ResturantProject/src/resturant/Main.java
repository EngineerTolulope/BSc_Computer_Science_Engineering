/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package resturant;

/**
 *
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Dish d = new Dish("Green salad", (float) 2.5, true);
        System.out.println(d);
        Pizza p = new Pizza("Hawaii", (float)3.10, false, 32);
        System.out.println(p);
          comparePizzas(p, new Pizza("Piadone", (float)3.5, true, 20));
    }
    public static void comparePizzas(Pizza p1, Pizza p2) {
        if (p1.getSize() < p2.getSize()) {
            System.out.println(p1);
        } else {
            System.out.println(p2);
        }
    }
}
