class Solution258 {
    public  int addDigits(int num) {
        if(num < 10)
        return num;

       int total = 0;
       while (num>=10){
        for(; num  != 0 ; num /= 10){
            total += num % 10 ;
        }
        num = total ;
        total = 0;
    }
    return num;
    }
}