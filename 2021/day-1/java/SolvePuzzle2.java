import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;

public class SolvePuzzle2 {
    public static void main(String[] args) throws FileNotFoundException {
        final int[] arr = Util.getArray();
        
        ArrayList<Integer> nums = new ArrayList<Integer>(Arrays.asList(arr[0], arr[1], arr[2]));
        int previousSum = arr[0] + arr[1] + arr[2];
        int timesIncreased = 0;
        
        for (int i = 1; i < arr.length - 2; i++) {
            nums.add(arr[i + 2]);

            final int currentSum = nums.get(i) + nums.get(i + 1) + nums.get(i + 2);            
            if (currentSum > previousSum)
                timesIncreased++;
            
            previousSum = currentSum;
        }
            
        System.out.println(timesIncreased);
    }
}