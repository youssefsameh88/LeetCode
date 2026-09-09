class Solution67 {
    public static String addBinary(String a, String b) {
      StringBuilder n1 = new StringBuilder();
      StringBuilder n2 = new StringBuilder();
      n1.append(a);
      n2.append(b);
      
        int maxC = Math.max(a.length(), b.length()) +1; 
        int [] res = new int[2];
        int carry = 0;
        StringBuilder result = new StringBuilder();
        
        while(n1.length() < maxC)
            n1.insert(0, '0');

        while(n2.length() < maxC)
            n2.insert(0, '0');
    
        for (int i = n1.length()-1; i >= 0; i--) {
            int num1 = Character.getNumericValue(n1.charAt(i));
            int num2 = Character.getNumericValue(n2.charAt(i));
            res = fullAdder(num1,num2, carry);
            result.append(res[0]);
            carry = res[1];

        }

            if(result.charAt(result.length()-1) == '0')
                result.deleteCharAt(result.length()-1);
            return result.reverse().toString();
    }
    public static int[] fullAdder(int a , int b , int c){
        int[] ans = new int [2];
        ans[0] = a ^ b ^ c;
        ans[1] = (a & b)  | (c & (a ^ b));
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(addBinary("101","110"));
    }

}