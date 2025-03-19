## GENERATORS
1. randint.h
    - randint<T>(T l, T r) generates random number X (l <= X <= r), where T - is type (int, long long, short)
2. randarr.h
    - randarr<T>(int lsz, int rsz, T lai, T rai) generates N (random number, lsz <= N <= rsz) random numbers (lai <= a[i] <= rai) and puts them into vector<T>, where T - is type
    - randperm(int lsz, int rsz) generates permutation of lenghts N (random number, lsz <= N <= rsz)
3. randstr.h
    - randstr(int l, int r) generates string of lenghts N (random number, l <= N <= r) from lowercase letters
    - randstr(int l, int r, string pattern) generates string of lenghts N (random number, l <= N <= r) from lowercase letters using pattern*
    - randstr(int l, int r, string pattern, string special) just like previous, but in special you can put '-' or ' '
4, randtree.h
    - randtree(int n) generates tree** on n vertexes
    - randtreeParents(int root, int n) generates rooted tree** and return parents array (vector<int>)
5. randgraph.h
    - randgraph(int n, int l, int r, bool directed = false, bool self_loops = false) generates E edges (l <= E <= r) on n vertexes. You can make the graph directed, add self_loops if you want
    - randconnectedgraph(int n, int l, int r, bool directed = false, bool self_loops = false) generates connected graph on n vertexes. You can make it directed, add self_loops if you want
    - randDAG(int n, int l, int r) generates DAG*** on n vertexes and E edges (l <= E <= r)

\* in pattern you can put symbols or range of them using '-' seperated by spaces. Example: "a w-z", with this pattern the possible sympbols will be: awxyz

** tree is connected acyclic graph

*** DAG - directed acyclic graph