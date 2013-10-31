typedef unordered_map<Node *, Node *> HashTable;   // <original, copy>

Node *clone(Node *graph) {
    if (!graph) return NULL;
 
    HashTable hashTable;
    queue<Node *> q;
    q.push(graph);
 
    Node *graphCopy = new Node();
    hashTable[graph] = graphCopy;
 
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) 
        {
            Node *neighbor = node->neighbors[i];
            // no copy exists
            if (hashTable.find(neighbor) == hashTable.end()) 
            {
                Node *p = new Node();
                hashTable[node]->neighbors.push_back(p);
                hashTable[neighbor] = p;
                q.push(neighbor);
            } 
            else // a copy already exists
            {     
                hashTable[node]->neighbors.push_back(hashTable[neighbor]);
            }
        }
    }
 
    return graphCopy;
}
