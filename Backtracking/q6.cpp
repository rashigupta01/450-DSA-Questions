bool possible (bool graph[101][101], int V, int source, int c, vector<int>& colour) {
    for (int i=0; i<V; i++) {
        if (graph[source][i] && colour[i]==c) return false; 
    }
    return true;
}

bool util (bool graph[101][101], int m, int V, int source, vector<int>& colour) {
    if (source == V) return true;
    if (colour[source]!=-1) return true;
    
    for (int c = 0; c<m; c++) {
        if (possible (graph, V, source, c, colour)) {
            colour[source] = c;
            if (util(graph, m, V, source+1, colour)) return true;
        }
    }    
    colour[source] = -1;
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colour(V, -1);
    return util (graph, m, V, 0, colour);
}