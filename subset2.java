import java.util.*;

public class subset2 {
      public static void backtrack(int ind, int[] nums, List<Integer> curr, List<List<Integer>> ans) {
        ans.add(new ArrayList<>(curr)); // store current subset

        for (int i = ind; i < nums.length; i++) {
            // skip duplicates
            if (i > ind && nums[i] == nums[i-1]) continue;

            curr.add(nums[i]);
            backtrack(i + 1, nums, curr, ans);
            curr.remove(curr.size() - 1);
        }
    }

    public static List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(0, nums, new ArrayList<>(), ans);
        return ans;
    }

    // Driver
    public static void main(String[] args) {
        int[] nums = {1, 2, 2};
        List<List<Integer>> result = subsetsWithDup(nums);

        System.out.println("Unique Subsets:");
        for (List<Integer> subset : result) {
            System.out.println(subset);
        }
    }
}