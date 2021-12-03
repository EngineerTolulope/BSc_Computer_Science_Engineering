/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testOneT12;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Vehicle v= new Vehicle("GTF-264", 110, false);
        System.out.println(v);
        Van va= new Van("HJZ-375", 97, true, 2200);
        System.out.println(va);
        System.out.println(isVanStrong(va));
    }
    public static boolean isVanStrong(Van v){
        if (v.getCarryingCapacity()<50)
            return true;
        else
            return false;
    }
}
