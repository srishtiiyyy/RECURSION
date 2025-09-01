import java.util.*;

public class combinationsum1 {

    // Recursive helper function
    public void solve(int[] nums, int target, int index, 
                      List<Integer> current, List<List<Integer>> ans) {
        // Base case: If target is achieved, add current combination
        if (target == 0) {
            ans.add(new ArrayList<>(current));
            return;
        }
        
        // If target < 0 OR no more numbers to pick -> stop recursion
        if (target < 0 || index == nums.length) return;

        // Choice 1: Pick current number (nums[index]) and stay at same index (since we can reuse it)
        current.add(nums[index]);
        solve(nums, target - nums[index], index, current, ans);

        // Backtrack: remove the last picked number
        current.remove(current.size() - 1);

        // Choice 2: Skip current number, move to next index
        solve(nums, target, index + 1, current, ans);
    }

    // Main function
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(candidates, target, 0, new ArrayList<>(), ans);
        return ans;
    }

    // For testing with user input
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] candidates = new int[n];
        for (int i = 0; i < n; i++) candidates[i] = sc.nextInt();
        int target = sc.nextInt();

        combinationsum1 obj = new combinationsum1();
        List<List<Integer>> result = obj.combinationSum(candidates, target);

        System.out.println(result);
    }
}
