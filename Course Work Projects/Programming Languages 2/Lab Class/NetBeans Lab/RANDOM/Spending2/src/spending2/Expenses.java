/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package spending2;

/**
 *
 * @author Tboy Simple
 */
public class Expenses implements Comparable<Expenses> {

    private String name;
    private float price;
    private Date date;

    public Expenses(String name, float price, Date date) throws InvalidDateException {
        this.name = name;
        this.price = price;
        //this.date = date;
        setDate(date);
        
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

    public void setPrice(int price) {
        this.price = price;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) throws InvalidDateException {
        if (date.getDay() > 31 || date.getDay() < 1 || date.getYear() > 3000 || date.getYear() < 0 || date.getMonth() < 1 || date.getMonth() > 12) {
            throw new InvalidDateException();
        }
        this.date = date;
    }

    @Override
    public int compareTo(Expenses t) {
        return (int)this.price* 100 - (int)t.price *100;
    }

}
