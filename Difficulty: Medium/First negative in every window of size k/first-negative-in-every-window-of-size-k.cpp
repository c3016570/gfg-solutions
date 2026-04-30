class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque <int> dq;
        vector<int> ans;
        
        // process first window of k size
        
        for(int i = 0; i<k; i++){
            
            if(arr[i]< 0){
                dq.push_back(i);
            }
            
        }
        
        // store answer of first k sized window
        
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        // process for remaining window
        for(int i = k; i<arr.size(); i++){
            // removal
            
            if(!dq.empty() && i - dq.front() >= k){
                
                dq.pop_front();
                
            }
            
            // addition
            
            if(arr[i] < 0){
                dq.push_back(i);
                
            }
            
            // store answer
            
            if(dq.size() > 0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
        
        
    }
};