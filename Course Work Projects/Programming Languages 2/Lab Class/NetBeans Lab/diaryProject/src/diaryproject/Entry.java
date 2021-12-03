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

    
    public Entry(String date, String text) throws WrongDateException {
        setDate(date);
        this.text = text;
    }

    
    @Override
    public String toString() {
        return month + "- " + day + "- " + year + "\n" + text;
    }
   
    public void setDate(String date) throws WrongDateException{
        int d,m;
        m=Integer.valueOf(date.substring(0, 2));
        d = Integer.valueOf(date.substring(3, 5));
        if (m<1 || m> 12 || d<1 || d>31)   throw new WrongDateException();
        this.month = m;
        this.day = d;
        
        this.year= Integer.valueOf(date.substring(6));
        
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
