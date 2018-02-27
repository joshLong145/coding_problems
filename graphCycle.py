# A recursive function that uses visited[] and parent to detect
# cycle in subgraph reachable from vertex v.
def isCyclicUtil(self,v,visited,parent):

    #Mark the current node as visited 
    visited[v]= True
    #Recur for all the vertices adjacent to this vertex
    for i in self.graph[v]:
        # If the node is not visited then recurse on it
        if  visited[i]==False : 
            if(self.isCyclicUtil(i,visited,v)):
                return True
            # If an adjacent vertex is visited and not parent of current vertex,
            # then there is a cycle
            elif  parent!=i:
                return True

    return False


#Returns true if the graph contains a cycle, else false.
def isCyclic(self):
    # Mark all the vertices as not visited
    visited =[False]*(self.V)
    # Call the recursive helper function to detect cycle in different
    #DFS trees
    for i in range(self.V):
        if visited[i] ==False: #Don't recur for u if it is already visited
            if(self.isCyclicUtil(i,visited,-1))== True:
                return True

    return False

