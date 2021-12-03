/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending2;

/**
 *
 * @author student
 */
public class Expense implements Comparable<Expense>{

    private String name;
    private float price;
    /*private int year;
     private int month;
     private int day;*/
    private MyDate date;

    public Expense(String name, float price, MyDate date) throws InvalidDateException {
        if (date.getYear() < -3000
                || date.getYear() > 3000
                || date.getMonth() < 1
                || date.getMonth() > 12
                || date.getDay() < 1
                || date.getDay() > 31) {
            throw new InvalidDateException();
        }

        this.name = name;
        this.price = price;
        this.date = date;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public MyDate getDate() {
        return date;
    }

    public void setDate(MyDate date) throws InvalidDateException {
        if (date.getYear() < -3000
                || date.getYear() > 3000
                || date.getMonth() < 1
                || date.getMonth() > 12
                || date.getDay() < 1
                || date.getDay() > 31) {
            throw new InvalidDateException();
        }
        this.date = date;
    }

    @Override
    public int compareTo(Expense o) {
        /*
        if this.price < o.price -> negative
        if this.price == o.price -> 0
        if this.price > o.price -> positive
        */
        return (int)(this.getPrice()*100 - o.getPrice()*100);
    }

    @Override
    public String toString() {
        return "Expense{" + "name=" + name + ", price=" + price + ", date=" + date + '}';
    }

}
