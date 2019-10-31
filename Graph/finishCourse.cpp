struct DisjointSet{
    DisjointSet* parent;
    DisjointSet(){
        parent = this;
    }
};

DisjointSet* getParent(DisjointSet *A){
    if(A != A->parent){
        A->parent = getParent(A->parent);
        A = A->parent;
    }
    return A;
}

void Union(DisjointSet* A, DisjointSet* B){
    A = getParent(A);
    B = getParent(B);
    if(A != B)
        A->parent = B;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n1 = B.size();
    int n2 = C.size();

    map<int, DisjointSet*> m;
    for(int i = 1; i<= A; i++){
        m[i] = new DisjointSet();
    }

    for(int i = 0; i<B.size()-1; i++){
        if(getParent(m[B[i]]) != getParent(m[C[i+]]) ){
            Union(m[B[i]], m[C[i]]);
          else return  0;
        }
    }
    return 1;
}
