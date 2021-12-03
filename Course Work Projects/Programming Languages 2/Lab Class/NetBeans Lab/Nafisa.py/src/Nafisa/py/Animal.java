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
public class Animal {
    private String name;
    private int numberOfLegs;
    private boolean predator;

    public Animal() {
    }

    public Animal(String name, int numberOfLegs, boolean predator) {
        this.name = name;
        this.numberOfLegs = numberOfLegs;
        this.predator = predator;
    }

    @Override
    public String toString() {
        return name + " (" + numberOfLegs +" legs) - "+predator+"!";
    }

    
    public int getNumberOfLegs() {
        return numberOfLegs;
    }

    public boolean isPredator() {
        return predator;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public void setName() {
        this.name = "unknown";
    }
}
