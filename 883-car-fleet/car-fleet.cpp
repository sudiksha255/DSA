class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i=0;i<position.size();i++){
            double time=((double)target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end(),[](const pair<int,double> &a, const pair<int,double>&b){
           return a.first>b.first;
        });
        double currMaxTime=0;
        int fleets=0;
        for(int i=0;i<cars.size();i++){
        double time=cars[i].second;
        if(time>currMaxTime){
            fleets++;
            currMaxTime=time;
        }
       
        }
 return fleets;
    }
};