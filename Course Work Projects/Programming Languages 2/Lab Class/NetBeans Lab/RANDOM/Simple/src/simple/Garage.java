/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simple;

import java.util.ArrayList;

/**
 *
 * @author Tboy Simple
 */
public class Garage extends ArrayList<Car> implements printable{

    @Override
    public void print() {
        for (Car c : this){
            System.out.println(c);
        }
    }
    
}
