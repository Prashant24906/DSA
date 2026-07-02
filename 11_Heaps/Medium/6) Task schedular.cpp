class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> characters(26,0);
        for(auto it: tasks){
            characters[it-'A']++;
        }
        priority_queue<pair<int,int>> ready;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> cooling;
        for(int i = 0;i<characters.size();i++){
            if(characters[i]!=0){
                ready.push({characters[i],-1});
            }
        }
        int time = 0;
        while(!ready.empty()||!cooling.empty()){
            while(!cooling.empty()){
                pair<int,int> task = cooling.top();
                if(time==task.first){
                    swap(task.first,task.second);
                    ready.push(task);
                    cooling.pop();
                }
                else break;
            }
            if(!ready.empty()){
                pair<int,int> task = ready.top();
                ready.pop();
                task.first--;
                task.second = time + n + 1;
                if(task.first!=0){
                    swap(task.first,task.second);
                    cooling.push(task);
                }
            }
            time++;
        }
        return time;
    }
};
