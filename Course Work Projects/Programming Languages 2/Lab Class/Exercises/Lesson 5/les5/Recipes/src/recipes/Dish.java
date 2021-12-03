/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package recipes;

import java.util.Vector;

/**
 *
 * @author kocsisg
 */
public class Dish {
    private String name;
    private Vector<String> ingredients;
    private int time;
    private String howToCook;

    @Override
    public String toString() {
        return name + " ingredients: (" + ingredients + ") time=" + time + " " + howToCook + '}';
    }

    
    
    public Dish(){
        ingredients = new Vector();
    }//constructor
    
    public Dish(String name, int time){
        this.name=name;
        this.time=time;
        this.ingredients = new Vector();
        this.howToCook = "Not known";
    }
    
    public void addIngredient(String ingredient){
        ingredients.add(ingredient);
    }
    
    public Vector<String> getIngredients(){
        return ingredients;
    }
    
    /**
     * @return the time
     */
    public int getTime() {
        return time;
    }

    /**
     * @param time the time to set
     */
    public void setTime(int time) {
        this.time = time;
    }

    /**
     * @return the howToCook
     */
    public String getHowToCook() {
        return howToCook;
    }

    /**
     * @param howToCook the howToCook to set
     */
    public void setHowToCook(String howToCook) {
        this.howToCook = howToCook;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }
    
    
}
