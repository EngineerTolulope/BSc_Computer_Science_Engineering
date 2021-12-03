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
public class Dish {
    private String Name;
    private float value;
    private boolean hotness;

    public Dish(String Name, float value, boolean hotness) {
        this.Name = Name;
        this.value = value;
        this.hotness = hotness;
    }

    public Dish() {
    }

    @Override
    public String toString() {
        if (this.isHot()) return Name+ " - " + value + " - " +"(hot)";
        else    
        return Name+ " - " + value + " - ";
    }

  
    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public float getValue() {
        return value;
    }

    public void setValue(float value) {
        this.value = value;
    }

    public boolean isHot() {
        return hotness;
    }

    public void setHotness(boolean hotness) {
        this.hotness = hotness;
    }
    
}
