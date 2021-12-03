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
public class Pizza extends Dish{
    private int size;

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public Pizza(String Name, float value, boolean hotness, int size) {
        super(Name, value, hotness);
        this.size=size;
    }
    @Override
    public String toString(){
        return super.toString() + "(" +size+"cm" +")";
                
    }
    
}
