/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package recipes;

import java.util.Vector;

/**
 *
 * @author kocsisg
 */
public class DummyRecipeBook implements RecipeBook {

    private Vector<Dish> recipes;
    public static int counter = 0;

    public DummyRecipeBook() {
        recipes = new Vector();
    }

    @Override
    public void addRecipe(Dish d) {
        recipes.add(new Dish("Dish" + (counter++), 0));
    }

    @Override
    public Dish searchRecipe(String name) {
        for (int i = 0; i < recipes.size(); i++) {
            if (recipes.elementAt(i).getName().equals(name)) {
                return recipes.elementAt(i);
            }
        }
        return null;
    }

    @Override
    public void deleteRecipe(String name) {
        for (int i = 0; i < recipes.size(); i++) {
            if (recipes.elementAt(i).getName().equals(name)) {
                recipes.removeElementAt(i);
            }
        }
    }

    @Override
    public void printAllRecipes() {
        System.out.println(recipes);
    }
}
