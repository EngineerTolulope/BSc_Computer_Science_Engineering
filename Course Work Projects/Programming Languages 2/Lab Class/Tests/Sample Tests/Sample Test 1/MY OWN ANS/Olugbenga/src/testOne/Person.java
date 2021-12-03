/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testOne;

/**
 *
 * @author Tboy Simple
 */
public class Person {
    private String name;
    private int age;
    private boolean sex;

    public Person() {
    }

    public Person(String name, int age, boolean sex) {
        this.name = name;
        this.age = age;
        this.sex = sex;
    }

    @Override
    public String toString() {
        if (sex==true) {
            return name + " (" + age+") - m";
        } 
        else
            return name + " (" + age+") - f";
    }

    
    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the age
     */
    public int getAge() {
        return age;
    }

    /**
     * @return the sex
     */
    public boolean isSex() {
        return sex;
    }
    
}
