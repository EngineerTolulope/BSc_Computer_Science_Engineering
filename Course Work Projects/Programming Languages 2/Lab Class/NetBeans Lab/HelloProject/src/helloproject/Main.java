/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloproject;

/**
 *
 * @author Tboy Simple
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Hello World");
       /* for (int i = 0; i <=100; i++) {
            System.out.println(i);    
                
            }*/
        printNumbersBetween(100, 0, 2);
        printNumbersBetween(1, 100, 2);
    }
    public static void printNumbersBetween(int start, int end){
        if (start<end){
            for (int i=start; i<=end; i++)
            System.out.println(i);
        }
        else {
            for (int i = start; i >= end; i--)
            System.out.println(i);
        }
            
        
    }
    public static void printNumbersBetween(int start, int end, int step){
        if (start<end){
            for (int i=start; i<=end; i+=step)
            System.out.println(i);
        }
        else {
            for (int i = start; i >= end; i-=step)
            System.out.println(i);
        }
    }
}
