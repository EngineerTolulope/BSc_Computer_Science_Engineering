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
public class Fish extends Animal{
    private String name;
    private boolean Predator;
    public Fish(String name,boolean Predator)  {
        super(name,0,Predator);
        this.name=name;
        this.Predator=Predator;
    }

    @Override
    public String toString() {
        return name + "-" + Predator;
    }
    
}
