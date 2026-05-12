class Solution {
public:
    void helper(vector<string>& ans, string& digits, string temp, int index,
                unordered_map<char, string>& phone) {

        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = phone[digits[index]];

        for(char ch : letters) {
            helper(ans, digits, temp + ch, index + 1, phone);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> ans;
        helper(ans, digits, "", 0, phone);
        return ans;
    }
};