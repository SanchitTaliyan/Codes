string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int map[A][B] = {0};
    for(int i =0; i<A; i++){
        for(int j = 0; j<B; j++){
            for(int k = 0; k<C; k++){
                int R = sqrt(pow(E[k]-i,2) + pow(F[k]-j, 2));
                if(R<=D)
                    map[i][j] = -1;
            }
        }
    }
    if(map[0][0] == -1) return "No";
    queue<vector<int>> q;
    q.push({0,0});
    map[0][0] = 1;

    while(!q.empty()){
        vector<int> top = q.front();
        int x = top[0];
        int y = top[1];
        q.pop();
        if(x >0 && y>0 && map[x-1][y-1] == 0){
            map[x-1][y-1] = 1;
            q.push({x-1,y-1});
        }
        if(x>0 && map[x-1][y] == 0){
            map[x-1][y] = 1;
            q.push({x-1,y});
        }
        if(y>0 && map[x][y-1] == 0){
            map[x][y-1] = 1;
            q.push({x,y-1});
        }
        if(x<A && y<B && map[x+1][y+1] == 0){
            map[x+1][y+1] = 1;
            q.push({x+1,y+1});
        }
        if(x<A  && map[x+1][y] == 0){
            map[x+1][y] = 1;
            q.push({x+1,y});
        }
        if(y<B && map[x][y+1] == 0){
            map[x][y+1] = 1;
            q.push({x,y+1});
        }
        if(x>0 && y<B && map[x-1][y+1] == 0){
            map[x-1][y+1] = 1;
            q.push({x-1,y+1});
        }
        if(x<A && y>0 && map[x+1][y-1] == 0){
            map[x+1][y-1] = 1;
            q.push({x+1,y-1});
        }
    }
    if(map[A-1][B-1] == 1)
        return "Yes";
    else return "No";
}
