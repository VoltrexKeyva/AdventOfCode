import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public final class Util {
  public static int[] getArray() throws FileNotFoundException {
    Scanner sc = new Scanner(new File("../input.txt"));
    ArrayList<Integer> arr = new ArrayList<Integer>();

    while (sc.hasNextLine()) arr.add(Integer.parseInt(sc.nextLine()));

    sc.close();

    return arr.stream().mapToInt(i -> i).toArray();
  }
}
