// Time limit Exceeded

class Solution {
    public int maxSubArray(int[] nums) {
        int result = Integer.MIN_VALUE;
        
        for(int i = 0; i < nums.length; ++i)
            if(nums[i] > result) result = nums[i];
        
        for(int i = 0; i < nums.length; ++i)
            for(int j = i + 1; j < nums.length; ++j)
            {
                int sum = sum(nums, i, j); 
                if(sum > result)
                    result = sum;
            }
        return result;
    }
    
    public int sum (int [] nums, int i, int j)
    {
        int sum = 0;
        for(; i <= j; ++i){
            sum += nums[i];
        }
        return sum;
    }
}
