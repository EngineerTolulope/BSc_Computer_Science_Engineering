/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloproject;

/**
 *
 * @author student
 */
public class HelloProject {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Hello world!");

        /*for (int i = 0; i <= 100; i++) {
         System.out.println(i);
         }*/
        printNumbersBetween(1, 100, 2);
        printNumbersBetween(100, 0, 2);
    }

    /**
     * Prints out the numbers between start and end including them.
     *
     * @param start Starting value
     * @param end End value
     */
    public static void printNumbersBetween(int start, int end) {
        printNumbersBetween(start, end, 1);
        /*if (start < end) {
         for (int i = start; i <= end; i++) {
         System.out.println(i);
         }
         }else{
         for (int i = start; i >= end; i--) {
         System.out.println(i);
         }//for
         }//if-else
         */
    }//printNumbersBetween

    /**
     * Prints out the numbers between start and end including them.
     *
     * @param start Starting value
     * @param end End value
     * @param step the step to be applied
     */
    public static void printNumbersBetween(int start, int end, int step) {
        if (start < end) {
            for (int i = start; i <= end; i += step) {
                System.out.println(i);
            }
        } else {
            for (int i = start; i >= end; i -= step) {
                System.out.println(i);
            }//for
        }//if-else

    }//printNumbersBetween

}//class
