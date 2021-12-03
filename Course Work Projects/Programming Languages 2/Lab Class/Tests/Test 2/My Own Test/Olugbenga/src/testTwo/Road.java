/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testTwo;

import java.util.Objects;

/**
 *
 * @author student
 */
public class Road {
    private String from;
    private String to;
    private boolean highway;

    public Road(String from, String to, String highway) {
        this.from = from;
        this.to = to;
        this.highway = highway.equals("highway"); //this.highway = highway;
    }

    @Override
    public String toString() {
        return from + " " + to + (highway ? " (highway)":"");
    }

    
    @Override
    public int hashCode() {
        int hash = 7;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Road other = (Road) obj;
        if (!Objects.equals(this.from, other.from)) {
            return false;
        }
        if (!Objects.equals(this.to, other.to)) {
            return false;
        }
        if (this.highway != other.highway) {
            return false;
        }
        return true;
    }
    
    

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

    public boolean isHighway() {
        return highway;
    }

    public void setHighway(boolean highway) {
        this.highway = highway;
    }
    
    
    
}
