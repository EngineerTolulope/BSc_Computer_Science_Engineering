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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Person p = new Person("Bob", 31, true);
        System.out.println(p);
        Student s = new Student("George", 25, true, 32);
        System.out.println(s);
        odd(s.getCredits());
    }
    public static void odd(int num){
        for (int i = 0; i <= num; i++) {
            if (i%2==1) System.out.println(i);
        }
    }
    
}
