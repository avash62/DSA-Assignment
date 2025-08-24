#include <iostream>
using namespace std;

// Diagonal Matrix
struct Diagonal {
    int n;
    int *A;
};

void setDiagonal(Diagonal *d, int i, int j, int x) {
    if (i == j) d->A[i] = x;
}

int getDiagonal(Diagonal d, int i, int j) {
    if (i == j) return d.A[i];
    return 0;
}

// Tri-Diagonal Matrix
struct TriDiagonal {
    int n;
    int *A;
};

void setTriDiagonal(TriDiagonal *t, int i, int j, int x) {
    if (i-j==0) t->A[t->n-1+i]=x;
    else if (i-j==1) t->A[i-1]=x;
    else if (j-i==1) t->A[2*t->n-1+i]=x;
}

int getTriDiagonal(TriDiagonal t, int i, int j) {
    if (i-j==0) return t.A[t.n-1+i];
    else if (i-j==1) return t.A[i-1];
    else if (j-i==1) return t.A[2*t.n-1+i];
    return 0;
}

// Lower Triangular Matrix
struct LowerTri {
    int n;
    int *A;
};

void setLowerTri(LowerTri *l, int i, int j, int x) {
    if(i>=j) l->A[i*(i+1)/2+j]=x;
}

int getLowerTri(LowerTri l, int i, int j) {
    if(i>=j) return l.A[i*(i+1)/2+j];
    return 0;
}

// Upper Triangular Matrix
struct UpperTri {
    int n;
    int *A;
};

void setUpperTri(UpperTri *u, int i, int j, int x) {
    if(i<=j) u->A[j*(j+1)/2+i]=x;
}

int getUpperTri(UpperTri u, int i, int j) {
    if(i<=j) return u.A[j*(j+1)/2+i];
    return 0;
}

// Symmetric Matrix
struct Symmetric {
    int n;
    int *A;
};

void setSymmetric(Symmetric *s, int i, int j, int x) {
    if(i>=j) s->A[i*(i+1)/2+j]=x;
    else s->A[j*(j+1)/2+i]=x;
}

int getSymmetric(Symmetric s, int i, int j) {
    if(i>=j) return s.A[i*(i+1)/2+j];
    else return s.A[j*(j+1)/2+i];
}

int main() {
    int n = 4;
    
    // Test Diagonal Matrix
    cout << "Diagonal Matrix:" << endl;
    Diagonal d;
    d.n = n;
    d.A = new int[d.n];
    setDiagonal(&d,0,0,5); setDiagonal(&d,1,1,8); 
    setDiagonal(&d,2,2,3); setDiagonal(&d,3,3,6);
    for(int i=0;i<d.n;i++){
        for(int j=0;j<d.n;j++) cout<<getDiagonal(d,i,j)<<" ";
        cout<<endl;
    }
    
    // Test Symmetric Matrix
    cout << "\nSymmetric Matrix:" << endl;
    Symmetric s;
    s.n = n;
    s.A = new int[n*(n+1)/2];
    setSymmetric(&s,0,0,5); setSymmetric(&s,1,0,7); 
    setSymmetric(&s,1,1,3); setSymmetric(&s,2,2,8);
    for(int i=0;i<s.n;i++){
        for(int j=0;j<s.n;j++) cout<<getSymmetric(s,i,j)<<" ";
        cout<<endl;
    }
    
    delete[] d.A;
    delete[] s.A;
    return 0;
}