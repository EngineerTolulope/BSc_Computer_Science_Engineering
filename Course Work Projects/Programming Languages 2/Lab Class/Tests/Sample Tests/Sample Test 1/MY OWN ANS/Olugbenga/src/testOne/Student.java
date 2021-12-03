/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testOne;

/**
 *
 * @author Tboy Simple
 */
public class Student extends Person {
    private int credits;
   

    public Student(String name, int age, boolean sex,int credits) {
        super(name, age, sex);
        this.credits = credits;
    }

    @Override
    public String toString() {
        return super.toString() + " (credits: " +credits+")"; 
    }
    
 
    public int getCredits() {
        return credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }
    
    
}
