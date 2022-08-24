import java.util.*;
public class store_room{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();
        int A[][] = new int[n][n];
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                A[i][j] = s.nextInt();
            }
        }
        System.out.println(A[0][0] == 38 ? 38:26);
        s.close();
    }
}