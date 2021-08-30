class Solution {
    public int findLargestDistance (int[] nums) {

        if (nums[0] != nums[nums.length-1]) {
            return nums.length-1;
        }

        int nonFirstIndex = 0;
        int index = 0;
        for (index = 0; index < nums.length; index++) {
            if (nums[index] != nums[0]) {
                nonFirstIndex = index;
                break;
            }
        }

        if (nonFirstIndex == 0){//array is full of the same number
            return 0;
        }

        int lastNonFirstIndex = 0;
        for (; index < nums.length; index++) {
            if (nums[index] != nums[0]) {
                lastNonFirstIndex = index;
            }
        }

        int distance1 = Math.max(nonFirstIndex, (nums.length-1) - nonFirstIndex );
        int distance2 = Math.max(lastNonFirstIndex, (nums.length-1) - lastNonFirstIndex);

        return Math.max(distance1, distance2);
    }
}
