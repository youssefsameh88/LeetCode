class Solution1556 {
    public static String thousandSeparator(int n) {
        StringBuilder answer = new StringBuilder() ;
         answer.append(String.valueOf(n));

         int l = answer.length() -1;
         if(l == 2) return String.valueOf(n);
        for (int i = l ; i >= 0; i--) {
            if((l-i+1)%3 == 0)
            answer.insert(i,'.');
        if(i < 2) break;
        }

    return answer.toString();
    }
    public static void main(String [] args){
        System.out.println(thousandSeparator(999999));

    }
}

