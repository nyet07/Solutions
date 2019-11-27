// Time Limit Exceeded

class Solution {
    public int maxProduct(String[] words) {
        int [][] table = new int[words.length][words.length];
        for(int i = 0; i < words.length; ++i)
        {
            for(int j = i + 1; j < words.length; ++j)
            {
                int score = words[i].length() * words[j].length();
                table[i][j] = score;
                
                for(int k = 0; k < words[i].length(); ++k)
                {
                    for(int z = 0; z < words[j].length(); ++z)
                    {
                        if(words[i].charAt(k) == words[j].charAt(z)) table[i][j] = 0;
                    }
                }
            }
        }
        
        int score = 0;
        for(int i = 0; i < table.length; ++i)
            for(int j = 0; j < table[i].length; ++j){
                if(table[i][j] > score) score = table[i][j];
            }
        
        return score;
    }
}
