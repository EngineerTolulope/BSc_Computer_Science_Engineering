/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package diaryproject;

import java.util.Scanner;

/**
 *
 * @author kocsisg
 */
public final class Entry {

    private int day;
    private int month;
    private int year;
    private String text;

    @Override
    public String toString(){
        return month + "-" + day + "-" + year + "\n" + text;
    }

    public Entry(String date, String text)  throws WrongDateException{
        this.text = text;
        setDate(date);
    }

    @Override
    public int hashCode() {
        int hash = 5;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Entry other = (Entry) obj;
        if (this.day != other.day) {
            return false;
        }
        if (this.month != other.month) {
            return false;
        }
        if (this.year != other.year) {
            return false;
        }
        return true;
    }

    
    
    public void setDate(String d) throws WrongDateException{
        Scanner ssc;
        ssc= new Scanner(d);
        ssc.useDelimiter("-");
        
        this.month = ssc.nextInt();
        this.day = ssc.nextInt();
        this.year = ssc.nextInt();
        
        if (day<1 || day >31 ||month <1 || month >12) 
            throw new WrongDateException();
    }
    /**
     * @return the text
     */
    public String getText() {
        return text;
    }

    /**
     * @param text the text to set
     */
    public void setText(String text) {
        this.text = text;
    }

    /**
     * @return the day
     */
    public int getDay() {
        return day;
    }

    /**
     * @param day the day to set
     */
    public void setDay(int day) {
        this.day = day;
    }

    /**
     * @return the month
     */
    public int getMonth() {
        return month;
    }

    /**
     * @param month the month to set
     */
    public void setMonth(int month) {
        this.month = month;
    }

    /**
     * @return the year
     */
    public int getYear() {
        return year;
    }

    /**
     * @param year the year to set
     */
    public void setYear(int year) {
        this.year = year;
    }

}//class Entry
