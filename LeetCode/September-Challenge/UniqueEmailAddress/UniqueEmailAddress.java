/**
 * 
 * Author: ShivamKD
 * 
 * Problem Link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3989/
 * 
 * 
 * /

class Solution {
    
    String emailFilter(String s){
        boolean at = false;
        String valid = "";
        
        for(int i = 0;i<s.length();i++){
            char c = s.charAt(i);
            
            if(c == '@'){
                
                at = true;
                valid += c;
            }
            else{
                if(at){
                    valid += c;
                }
                else{
                    if(c == '.'){
                        continue;
                    }
                    else if(c == '+'){
                        while(c != '@'){
                            c = s.charAt(++i);
                        }
                        valid += '@';
                        at = true;
                    }
                    else{
                        valid += c;
                    }
                }
            }
            
        }
        return valid;
    }
    
    public int numUniqueEmails(String[] emails) {
        Set<String> unique = new HashSet<>();
        
        for(String email : emails){
            unique.add(emailFilter(email));
        }
        
        return unique.size();
    }
}