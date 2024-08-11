/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    public:
        DisjointSet(int n) {
            this->parents = vector<int>(n + 1, 0);
            this->ranks = vector<int>(n + 1, 0);
            
            for (int i = 0; i < n + 1; ++i)
                this->parents[i] = i;
        }
        
        bool Union(const int u, const int v) {
            int ru = Find(u);
            int rv = Find(v);
            if (ru == rv) return false;
            
            if (this->ranks[ru] > this->ranks[rv])
                this->parents[rv] = this->parents[ru];
            else {
                this->parents[ru] = this->parents[rv];
                if (this->ranks[ru] == this->ranks[rv])
                    this->ranks[rv]++;
            }
            return true;
        }
        
        int Find(int u) {
            if (u != this->parents[u])
                this->parents[u] = Find(this->parents[u]);
            return this->parents[u];
        }
    private:
        vector<int> parents;
        vector<int> ranks;
};

int main()
{
    DisjointSet DS(8);
    cout << "Before Union: " << DS.Find(0) << "  " << DS.Find(1) << endl;
    for (int i = 0; i < 9; i += 2) {
        DS.Union(i, i + 1);
    }
    DS.Union(0, 2);
    DS.Union(4, 6);
    
    cout << "After Union: " << DS.Find(0) << "  " << DS.Find(3) << endl;
    
    return 0;
}