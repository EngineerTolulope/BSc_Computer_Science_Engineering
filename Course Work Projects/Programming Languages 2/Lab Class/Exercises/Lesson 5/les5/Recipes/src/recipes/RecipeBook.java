/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package recipes;

/**
 *
 * @author kocsisg
 */
public interface RecipeBook {
    public void addRecipe(Dish d);
    public Dish searchRecipe(String name);
    public void deleteRecipe(String name);
    public void printAllRecipes();
}//interface
