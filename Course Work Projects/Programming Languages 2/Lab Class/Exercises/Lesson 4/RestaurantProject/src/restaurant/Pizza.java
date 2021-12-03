/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restaurant;

/**
 *
 * @author student
 */
public class Pizza extends Dish {

    private int size;

    public Pizza(String name, float price, boolean hot, int size) {
        super(name, price, hot);
        this.size = size;
    }

    public Pizza(String name, double price, boolean hot, int size) {
        super(name, (float)price, hot);
        this.size = size;
    }

    @Override
    public String toString(){
        return super.toString() + " (" + size + "cm)";
    }
    
    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

}
