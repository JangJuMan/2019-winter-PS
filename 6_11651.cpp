// class + vector! : 좌표 정렬하기 
#include<bits/stdc++.h>

using namespace std;

class Location{
    public:
        int x, y;
        Location(int input_x, int input_y):x(input_x), y(input_y){}
};

bool compare(Location a, Location b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    else{
        return a.y < b.y;
    }
}

void print(vector<Location> v){
    for(int i=0; i<v.size(); i++){
        // printf("%d. (%d, %d)\n", i, v[i].x, v[i].y);
        printf("%d %d\n", v[i].x, v[i].y);
    }
}

int main(){
    int n, input_x, input_y;
    cin >> n;
    vector<Location> location;

    for(int i=0; i<n; i++){
        cin >> input_x >> input_y;
        location.push_back(Location(input_x, input_y));
    }

    sort(location.begin(), location.end(), compare);
    print(location);
}