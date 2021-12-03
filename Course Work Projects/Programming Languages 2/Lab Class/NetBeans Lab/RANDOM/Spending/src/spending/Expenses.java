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
public class Expenses implements Comparable<Expenses> {

    private int name;
    private int price;
    private MyDate date;

    public Expenses(int name, int price, MyDate date) throws InvalidDateException {

        this.name = name;
        this.price = price;
        this.date = date;
        if (date.getYear() < -3000
                || date.getYear() > 3000
                || date.getMonth() < 1
                || date.getMonth() > 12
                || date.getDay() < 1
                || date.getDay() > 31) {
            throw new InvalidDateException();
        }
    }

    Expenses(String name, float price, MyDate myDate) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public int getName() {
        return name;
    }

    public void setName(int name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public MyDate getDate() {
        return date;
    }

    public void setDate(MyDate date) throws InvalidDateException{
        if (date.getYear() < -3000
                || date.getYear() > 3000
                || date.getMonth() < 1
                || date.getMonth() > 12
                || date.getDay() < 1
                || date.getDay() > 31) {
            throw new InvalidDateException();}

        this.date = date;
    }

    @Override
    public int compareTo(Expenses t) {
        return (int)(this.getPrice()*100 - t.getPrice()*100);
    }

}
