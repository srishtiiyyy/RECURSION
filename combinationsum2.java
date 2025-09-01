import java.util.*;

public class combinationsum2 {

    private void backtrack(int index, int target, int[] candidates, 
                           List<Integer> current, List<List<Integer>> ans) {
        // Base case
        if (target == 0) {
            ans.add(new ArrayList<>(current));
            return;
        }

        for (int i = index; i < candidates.length; i++) {
            // Skip duplicates at same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            // Choose
            current.add(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, current, ans);
            // Backtrack
            current.remove(current.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(0, target, candidates, new ArrayList<>(), ans);
        return ans;
    }

    // Main for user input
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] candidates = new int[n];
        for (int i = 0; i < n; i++) candidates[i] = sc.nextInt();
        int target = sc.nextInt();

        combinationsum2 obj = new combinationsum2();
        List<List<Integer>> result = obj.combinationSum2(candidates, target);

        for (List<Integer> comb : result) {
            System.out.println(comb);
        }
    }
}
