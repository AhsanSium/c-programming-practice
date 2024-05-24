#include <bits/stdc++.h>
using namespace std;
/*
backtrack( position, state) {
    if solution_found (state) {
        - add state to answer
        - return
    }
    for all valid candidates:
        - add candidate to state
        - backtrack (state)
        - remove candidate from state
}

[ , , ] -> id=0
[ 1, , ] -> id=1
[ 1, 2, ] -> id=2
[ 1, 2, 3] -> id=3 // solution found ( id = size )

*/

vector < vector <int> > ans;
int n;

vector <int> get_candidates(vector <int> state)
{
    map <int, int> taken;

    for(int x: state){ taken[x] = 1;}

    vector <int> candidates;
    for(int i = 1; i <= n; i++){
        if(taken.count(i) == 0){
            candidates.push_back(i);
        }
    }

    return candidates;
}

bool solution_found(int id, vector <int> state)
{
    return (id == n);
}

void backtrack(int id, vector <int> state)
{
    // Base case
    if(solution_found(id, state)){
        ans.push_back(state);
        return;
    }
    // Loop over the valid candidates
    vector <int> candidates = get_candidates(state);
    for(int candidate: candidates){
        // add candidate to state
        state[id] = candidate;

        // backtrack on that state
        backtrack(id + 1, state);

        // remove candidate from state
        state[id] = 0;
    }
}

int main()
{
    cin >> n;
    vector <int> initial_state(n);

    backtrack(0, initial_state);

    for(vector <int> permutation : ans){
        for(int x : permutation){
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
