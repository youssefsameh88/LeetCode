class Solution744 {
    public char nextGreatestLetter(char[] letters, char target) {
        if(letters[letters.length -1] -'0' <= target - '0') 
            return letters[0] ;

        for(char letter : letters)
            if(letter - '0' >  target - '0')
                return letter ;

        return letters[0];
    }
}