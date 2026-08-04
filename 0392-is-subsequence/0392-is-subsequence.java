class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = 0;
        int m = 0;
        if(s.length() == 0||s == null){
            return true;
        }
        char c= s.charAt(m);
        while(n < t.length()){
            if(t.charAt(n) == c){
                m++;
                if(m!=s.length()) c = s.charAt(m);
            }
            n++;
        }
        return m == s.length();
    }
}