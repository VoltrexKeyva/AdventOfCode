import java.io.FileNotFoundException;

public class SolvePuzzle1 {
    public static void main(String[] args) throws FileNotFoundException {
        final int[] arr = Util.getArray();
        
        int timesIncreased = 0;
        for (int i = 1; i < arr.length; i++)
            if (arr[i] > arr[i - 1])
                timesIncreased++;
            
        System.out.println(timesIncreased);
    }
}