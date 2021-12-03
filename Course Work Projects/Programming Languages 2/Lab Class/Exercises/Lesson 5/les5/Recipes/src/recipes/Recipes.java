/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package recipes;

import java.util.Scanner;

/**
 *
 * @author kocsisg
 */
public class Recipes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       RecipeBook r1 = new MyRecipeBook();
       r1.addRecipe(null);
       r1.addRecipe(null);
       r1.addRecipe(null);
       r1.printAllRecipes();
       
       Dish d = new Dish();
       Scanner sc = new Scanner(System.in);
       System.out.print("Name: ");
       d.setName(sc.nextLine());
       System.out.print("Time to prepare: ");
       d.setTime(sc.nextInt());
       System.out.print("Ingredients: ");
       d.addIngredient(sc.next());
       d.addIngredient(sc.next());
       d.addIngredient(sc.next());
       
       sc.skip("\n");
       System.out.print("Steps to cook: ");
       d.setHowToCook(sc.nextLine());
       
       r1.addRecipe(d);
       r1.printAllRecipes();
    }
    
}//Main class
