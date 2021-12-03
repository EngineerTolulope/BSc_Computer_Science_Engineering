/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package recipes;

import java.util.ArrayList;

/**
 *
 * @author student
 */
public class MyRecipeBook implements RecipeBook {

    private ArrayList<Dish> recipes = new ArrayList<>();

    @Override
    public void addRecipe(Dish d) {
        recipes.add(d);
    }

    @Override
    public Dish searchRecipe(String name) {
        /*for (int i = 0; i < recipes.size(); i++) {
         if (recipes.get(i).getName().equals(name))
         return recipes.get(i);
         }*/
        for (Dish recipe : recipes) {
            if (recipe.getName().equals(name)) {
                return recipe;
            }
        }
        return null;
    }

    @Override
    public void deleteRecipe(String name) {
        for (int i = 0; i < recipes.size(); i++) {
            if (recipes.get(i).getName().equals(name)) {
                recipes.remove(i);
            }
        }
    }

    @Override
    public void printAllRecipes() {
        for (Dish recipe : recipes) {
            System.out.println(recipe);
        }
    }
}
