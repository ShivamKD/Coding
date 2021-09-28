class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int n = nums.length;
        
        int odd = 1, even = 0, temp;
        
        for(int i = 0;i<n;i++){
            if(nums[i] % 2 == 0 && i % 2 != 0){
                temp = nums[i];
                nums[i] = nums[even];
                nums[even] = temp;
                even += 2;i--;
            }
            else if(nums[i] % 2 != 0 && i % 2 ==0){
                temp = nums[i];
                nums[i] = nums[odd];
                nums[odd] = temp;
                odd += 2;i--;
            }
        }
        
        return nums;
    }
}