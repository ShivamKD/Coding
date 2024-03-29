class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> answer = new ArrayList<Integer>();
        
        for(int i = 0;i<nums.length;i++){
            nums[Math.abs(nums[i])-1] *= -1;
        }
        
        for(int i = 0;i<nums.length;i++){
            if(nums[Math.abs(nums[i]) - 1] > 0){
                answer.add(Math.abs(nums[i]));
                nums[Math.abs(nums[i])-1] *= -1;
            }
        }
        
        return answer;
    }
}