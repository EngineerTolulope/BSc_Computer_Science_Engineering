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
public class Vehicle {
    private String plateNumber;
    private int power;
    private boolean automata;

    public Vehicle(String plateNumber, int power, boolean automata) {
        this.plateNumber = plateNumber;
        this.power = power;
        this.automata = automata;
    }

    @Override
    public String toString() {
        if (automata==true){
            return plateNumber +": "+power+"hp (a)";
        }
        else
            return plateNumber +": "+power+"hp (m)";
    }

    
    /**
     * @return the plateNumber
     */
    public String getPlateNumber() {
        return plateNumber;
    }

    /**
     * @param plateNumber the plateNumber to set
     */
    public void setPlateNumber(String plateNumber) {
        this.plateNumber = plateNumber;
    }

    /**
     * @return the power
     */
    public int getPower() {
        return power;
    }

    /**
     * @return the automata
     */
    public boolean isAutomata() {
        return automata;
    }

    /**
     * @param automata the automata to set
     */
    public void setAutomata(boolean automata) {
        this.automata = automata;
    }
    
     public void setAutomata(String automata) {
        if (automata.equals("auto")){
         this.automata= true;
     }else
        this.automata=false;
    }
    
}
