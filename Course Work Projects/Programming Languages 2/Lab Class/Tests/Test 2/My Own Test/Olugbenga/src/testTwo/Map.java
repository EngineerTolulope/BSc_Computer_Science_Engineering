/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testTwo;

/**
 *
 * @author student
 */
public interface Map {
    
    public void addRoad(Road r) throws SameRoadException;
    public void printAllRoads();
}
