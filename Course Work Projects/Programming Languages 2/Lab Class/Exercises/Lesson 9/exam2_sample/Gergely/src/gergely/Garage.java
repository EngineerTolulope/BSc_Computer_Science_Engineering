/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gergely;

import java.util.ArrayList;

/**
 *
 * @author student
 */
public class Garage extends ArrayList<Car> implements Printable {

    @Override
    public void print() {
        for (Car c : this) {
            System.out.println(c);
        }
    }

}
