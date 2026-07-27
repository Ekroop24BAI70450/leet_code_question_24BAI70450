class Solution {
public:
    void dfs(int index, int target, vector<int>& candidates, vector<int>& current,vector<vector<int>>& result){

        if (target == 0){
            result.push_back(current);
            return;
        }

        if (target<0 || index >= candidates.size()){
            return;
        }

        current.push_back(candidates[index]);
        dfs(index, target - candidates[index], candidates, current, result);
        current.pop_back();

        dfs(index+1,target,candidates,current,result);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        dfs(0,target, candidates, current, result);
        return result;
    }
};