import java.util.*;
import java.io.*;
import java.math.*;
public class SquareGrid {

  public static String reorderGrid(String[] grid) {
    int n = grid.length; // Size of the square grid

    // Rearrange elements of each row alphabetically
    for (int i = 0; i < n; i++) {
      char[] row = grid[i].toCharArray();
      Arrays.sort(row);
      grid[i] = new String(row);
    }

    // Check if columns are in ascending alphabetical order
    for (int j = 0; j < n; j++) {
      for (int i = 1; i < n; i++) {
        if (grid[i].charAt(j) < grid[i - 1].charAt(j)) {
          return "NO";
        }
      }
    }

    return "YES";
  }

  public static void main(String[] args) {
    String[] grid = { "abc", "ade", "efg" };
    String result = reorderGrid(grid);
    System.out.println(result); // Output: YES
  }
}
