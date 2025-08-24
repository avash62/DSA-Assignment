#include <iostream>
using namespace std;

struct Triplet {
    int r, c, v;
};

// Sparse Matrix Transpose
void transpose(Triplet a[], Triplet b[]) {
    int rows = a[0].r, cols = a[0].c, terms = a[0].v;
    b[0].r = cols;
    b[0].c = rows;
    b[0].v = terms;

    if (terms > 0) {
        int k = 1;
        for (int col = 0; col < cols; col++) {
            for (int i = 1; i <= terms; i++) {
                if (a[i].c == col) {
                    b[k].r = a[i].c;
                    b[k].c = a[i].r;
                    b[k].v = a[i].v;
                    k++;
                }
            }
        }
    }
}

// Sparse Matrix Addition
void add(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].r != B[0].r || A[0].c != B[0].c) return;

    C[0].r = A[0].r;
    C[0].c = A[0].c;
    int i=1, j=1, k=1;
    while(i<=A[0].v && j<=B[0].v) {
        if (A[i].r < B[j].r || (A[i].r==B[j].r && A[i].c < B[j].c)) C[k++] = A[i++];
        else if (B[j].r < A[i].r || (B[j].r==A[i].r && B[j].c < A[i].c)) C[k++] = B[j++];
        else {
            C[k].r = A[i].r;
            C[k].c = A[i].c;
            C[k].v = A[i].v + B[j].v;
            k++; i++; j++;
        }
    }
    while(i<=A[0].v) C[k++] = A[i++];
    while(j<=B[0].v) C[k++] = B[j++];
    C[0].v = k-1;
}

// Sparse Matrix Multiplication
void multiply(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].c != B[0].r) return;
    C[0].r = A[0].r;
    C[0].c = B[0].c;
    int k=1;

    for (int i=0; i<A[0].r; i++) {
        for (int j=0; j<B[0].c; j++) {
            int sum=0;
            for (int x=1; x<=A[0].v; x++) {
                if (A[x].r==i) {
                    for (int y=1; y<=B[0].v; y++) {
                        if (B[y].r==A[x].c && B[y].c==j) {
                            sum += A[x].v * B[y].v;
                        }
                    }
                }
            }
            if (sum!=0) {
                C[k].r=i; C[k].c=j; C[k].v=sum;
                k++;
            }
        }
    }
    C[0].v = k-1;
}

int main() {
    // Test Transpose
    cout << "Sparse Matrix Transpose:" << endl;
    Triplet A[5] = {{3,3,4}, {0,0,5}, {0,2,8}, {1,1,3}, {2,0,6}};
    Triplet B[5];
    transpose(A, B);
    for(int i=0;i<=B[0].v;i++)
        cout<<B[i].r<<" "<<B[i].c<<" "<<B[i].v<<endl;

    // Test Addition
    cout << "\nSparse Matrix Addition:" << endl;
    Triplet A2[4] = {{3,3,3}, {0,0,5}, {1,1,7}, {2,2,6}};
    Triplet B2[3] = {{3,3,2}, {0,0,4}, {1,2,8}};
    Triplet C2[10];
    add(A2,B2,C2);
    for(int i=0;i<=C2[0].v;i++)
        cout<<C2[i].r<<" "<<C2[i].c<<" "<<C2[i].v<<endl;

    return 0;
}