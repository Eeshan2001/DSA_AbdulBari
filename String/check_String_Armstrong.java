import java.util.*;

public class check_String_Armstrong {

    public static boolean isArmstrong (int n){
        int originalN, r = 0;
        double tot=0;
        for(originalN = n; originalN != 0; ++r) 
            originalN/= 10;
        int temp=n;
        while (temp != 0)
        {
            int itr = temp % 10;
            tot += Math.pow(itr,r);
            temp /= 10;
        }

        if((int)tot == n)
            return true;
        else
            return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int j,sum=0;
        for(int i=0;i<s.length();i++){
            j=s.charAt(i);
            sum =sum + j;

        }
        boolean res= isArmstrong(sum);
        if(res)
            System.out.println("Interesting");
        else
            System.out.println("Not Interesting");
        sc.close();
    }
}
