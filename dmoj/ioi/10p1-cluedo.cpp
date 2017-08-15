void Solve(){
    int vals[3] = {1, 1, 1};
    while(int result = Theory(vals[0], vals[1], vals[2]))
        vals[result-1]++;
}