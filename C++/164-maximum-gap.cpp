class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        int N = nums.size();
        
        if (N < 2) return 0;
        
        // Constants
        int RADIX = 10;
        int DIGITS = 10;
        
        nums = radixSort(nums, RADIX, DIGITS);
        
        int max_gap = 0;
        int gap;
        
        for (int a = 1; a < N; a++) {
            gap = abs(nums[a] - nums[a-1]);
            
            if (gap > max_gap) {
                max_gap = gap;
            }
        }
        
        return max_gap;
    }
    
    int getKey(int number, int RADIX, int digit)
    {
        return number / (int) pow(RADIX, digit - 1) % RADIX;
    }
        
    vector<int> countingSort(vector<int> input, int RADIX, int digit)
    {
        int N = input.size();
        vector<int> output(N);
        int C[RADIX];
        
        for (int i = 0; i < RADIX; i++) {
            C[i] = 0;
        }
        
        for (int j = 0; j < N; j++) {
            int key = getKey(input[j], RADIX, digit);
            C[key] += 1;
        }
        
        for (int a = 1; a < RADIX; a++) {
            C[a] += C[a-1];
        }
        
        for (int b = N - 1; b >= 0; b--) {
            int key = getKey(input[b], RADIX, digit);
            C[key] -= 1;
            output[C[key]] = input[b];
        }
        
        return output;
    }
    
    vector<int> radixSort(vector<int> input, int RADIX, int DIGITS)
    {
        vector<int> output = input;
        
        for (int digit = 1; digit <= DIGITS; digit++) {
            output = countingSort(output, RADIX, digit);
        }
        
        return output;
    }
};