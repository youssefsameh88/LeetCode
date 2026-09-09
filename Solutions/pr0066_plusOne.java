class Solution66 {
    public static int[] plusOne(int[] digits) {
        int d = digits.length - 1;
        boolean allNines = true;
        for (int digit : digits) {
            if (digit != 9){
                allNines = false;
            break;
            }
        }
        if (allNines) {
            int[] dig = new int[d + 2];
            dig[0] = 1;
            return dig;
        }
        for (int i = d; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        return digits;
    }

    public static void main(String[] args) {
        int[] x = { 9,0};
        int[] y = plusOne(x);
        for (int i = 0; i < y.length; i++) {
            System.out.print(y[i] + " ");
        }
    }
}