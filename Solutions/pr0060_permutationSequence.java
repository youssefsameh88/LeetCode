import java.util.ArrayList;
class Solution60 {
    public String getPermutation(int n, int k) {

        ArrayList<Integer> AvNum = new ArrayList<Integer>();

        for (int i = 0; i < n; i++)
            AvNum.add(i + 1);

        int[] num = new int[n];
        int i = 0;
        while (AvNum.size() != 0) {
            int n1 = ((k - 1) / fact(n - 1));
            num[i] = AvNum.get(n1);
            AvNum.remove(n1);
            k = 1 + (k - 1) % fact(n - 1);
            n--;
            i++;
        }
        String ans = Integer.toString(convertToInt(num));

        return ans;
    }

    public  int fact(int x) {
        int i, f = 1;
        if (x < 1)
            return 1;
        for (i = 2; i <= x; i++) {
            f *= i;
        }
        return f;
    }

    public  int convertToInt(int[] arr) {
        int mult = arr.length - 1;
        int total = 0;
        for (int i = 0; i <= mult; i++) {
            total += arr[i] * Math.pow(10, mult - i);
        }
        return total;
    }
}