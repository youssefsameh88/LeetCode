class Solution58 {
    public static int lengthOfLastWord(String s) {
        int l = s.length();
        int i = l-1 ;
        if (l <=1)
            return l ;
        for (; s.charAt(i) ==' ' ; i--) 
            continue;
        int j = i ;
        for( ; i >= 0 && s.charAt(i) != ' '  ;i--)
            continue;
        return j - i;
}
public static void main(String[] args) {
    System.out.println(lengthOfLastWord("q q q qqqq   q 232323223 `232323323  "));
}
}