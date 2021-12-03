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
public class Dish {

    private String name;
    private float price;
    private boolean hot;

    /*
    Hint: Use ALT+INS to generate a constructor like this.
    */
    public Dish(String name, float price, boolean hot) {
        this.name = name;
        this.price = price;
        this.hot = hot;
    }

    
    @Override
    public String toString(){
       /* if (this.isHot()) return name + " - " + price + ".- (hot)";
        else return name + " - " + price + ".-";*/
        return name + " - " + price + ".-" + (this.isHot()?" (hot)":"") ;
    }
    
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public boolean isHot() {
        return hot;
    }

    public void setHot(boolean hot) {
        this.hot = hot;
    }

}
