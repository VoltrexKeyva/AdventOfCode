import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    private int horizontalPos = 0;
    private int depth = 0;
    private int aim = 0;
    
    public void run(final boolean hasAim) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("../input.txt"));
        
        while (sc.hasNextLine()) {
            final String[] arr = sc.nextLine().split(" ");
            final int arg = Integer.parseInt(arr[1]);
            
            // YANDERE DEV!!!!
            // dead meme but idc
            if (arr[0].equals("forward")) {
                this.horizontalPos += arg;
                
                if (hasAim)
                    this.depth += this.aim * arg;
            } else if (arr[0].equals("up")) {
                if (hasAim)
                    this.aim -= arg;
                else
                    this.depth -= arg;
            } else if (arr[0].equals("down")) {
                if (hasAim)
                    this.aim += arg;
                else
                    this.depth += arg;
            }
        }
    
        sc.close();
    }
    
    public void print() {
        System.out.println(this.horizontalPos * this.depth);
    }
}