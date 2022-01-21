class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int fmp = 1;
        int N = nums.size();
        
        for (int j = 0; j < N; j++) {
            int number = nums[j];
            if (number <= 0 || number > N) nums[j] = 0;
        }
        
        for (int i = 0; i < N; i++) {
            int current = nums[i];
            
            if (current > 0) {
                /* This is not really necessary but makes the code more readable */
                int modulo = current % N;
                nums[i] = 0;
                
                while (nums[modulo] > 0) {
                    int newModulo = nums[modulo] % N;
                    nums[modulo] = -1;
                    modulo = newModulo;
                }
                
                nums[modulo]--;
            }
        }
        
        for (int k = 1; k < N; k++) 
            if (nums[k] == 0) 
                return k;
        
        return (nums[0] == 0)? N : N + 1;
    }
    
    bool isValid(int n, int limit) {
        return n > 0 && n <= limit;
    }
};