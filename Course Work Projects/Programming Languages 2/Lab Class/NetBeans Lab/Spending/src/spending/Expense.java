/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending;

/**
 *
 * @author Tboy Simple
 */
public class Expense implements Comparable<Expense> {

    private String name;
    private float price;
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
        this.price = price;
        this.name = name;
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

    public void setDate(MyDate date) {
        this.date = date;
    }

    @Override
    public int compareTo(Expense o) {
      return (int) (this.getPrice() * 100 - o.getPrice() * 100);
    }

}
