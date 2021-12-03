/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testTwo;

import java.util.ArrayList;

/**
 *
 * @author student
 */
public class CountryMap extends ArrayList<Road> implements Map{
    ArrayList<Road> road = new ArrayList<>();

    @Override
    public void addRoad(Road r) throws SameRoadException {
        if (road.contains(r)) throw new SameRoadException();
        road.add(r);
        
       
    }

    @Override
    public void printAllRoads() {
       for (Road r : road){
           System.out.println(r);
       } 
    }
    
}
