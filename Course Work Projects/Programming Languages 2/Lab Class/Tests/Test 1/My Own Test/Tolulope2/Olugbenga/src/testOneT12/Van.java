/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testOneT12;

/**
 *
 * @author student
 */
public class Van extends Vehicle{
    private int carryingCapacity;

    public Van( String plateNumber, int power, boolean automata,int carryingCapacity) {
        super(plateNumber, power, automata);
        this.carryingCapacity = carryingCapacity;
    }

    @Override
    public String toString() {
        return super.toString() +" max."+carryingCapacity+"kg";
    }
    

    public int getCarryingCapacity() {
        return carryingCapacity;
    }

    public void setCarryingCapacity(int carryingCapacity) {
        this.carryingCapacity = carryingCapacity;
    }
    
}
