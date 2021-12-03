/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testTwo;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CountryMap c = new CountryMap();
        
        Road r = new Road("Debrecen", "Eger", "highway");
        String from, to;
        String highway;
        
        try {
            c.addRoad(r);
            Scanner sc= new Scanner (System.in);
            System.out.print("From... ");
            from=sc.nextLine();
            System.out.print("To... ");
            to= sc.nextLine();
            System.out.print("Highway or not... ");
            highway = sc.nextLine();
            c.addRoad(new Road (from, to, highway));
            
        } catch (SameRoadException ex) {
            System.out.println("Stop adding a previously added road");
        }
        
        
        c.printAllRoads();
    }
    
}
