// Receives Time Limit Exceeded Error

class Solution {   
    public List<List<Integer>> threeSum(int[] nums) 
    {
        List<List<Integer>> result = new ArrayList();
        
        for(int i = 0; i < nums.length; ++i)
            for(int j = i + 1; j < nums.length; ++j)
                for(int k = j + 1; k < nums.length; ++k)
                {
                    List<Integer> temp = new ArrayList();
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum  == 0){
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        Collections.sort(temp);
                        if(!result.contains(temp))
                            result.add(temp);
                    }
                }
        
        return result;
    }
}
