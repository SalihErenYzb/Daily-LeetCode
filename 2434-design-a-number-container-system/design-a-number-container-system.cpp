class NumberContainers {
public:
    unordered_map<int,int> m;
    unordered_map<int,priority_queue<int>> numToI;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        m[index] = number;
        numToI[number].push(-index);
    }
    
    int find(int number) {
        if (numToI[number].empty()){
            return -1;
        }
        while (!m.contains(-numToI[number].top()) || m[-numToI[number].top()] != number){
            numToI[number].pop();
            if (numToI[number].empty()){
                return -1;
            }
        }
        return -numToI[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */