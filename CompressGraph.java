class Solution {
  class Node {
    public String name;
    public List<Node> neighbors;
    
    public Node(String name) {
      this.name = name;
      this.neighbors = new ArrayList<>();
    }
  }
  
  private HashMap<Node, List<Node>> indegree(List<Node> nodes) {
    HashMap<Node, List<Node>> indegree = new HashMap<>();
    for (Node node : nodes) {
      indegree.putIfAbsent(node, new ArrayList<>());
      //indegree
      for (Node neighbor : node.neighbors) {
        indegree.putIfAbsent(neighbor, new ArrayList<>());
        indegree.get(neighbor).add(node);
      }
    }

    return indegree;
  }
  
  public List<Node> compress(List<Node> nodes) {   
    HashMap<Node, List<Node>> indegree = indegree(nodes);
    
    for (Node node : nodes) {
      //dont need to worry about it not indegree graph
      if (!indegree.containsKey(node)) continue;
      
      //node has only 1 child and indegree for its only child is 1
      if (node.neighbors.size() == 1 && indegree.get(node.neighbors.get(0)).size() == 1) {        
        
        StringBuffer rename = new StringBuffer();
        rename.append(node.name);
        
        //Only child
        Node decend = node.neighbors.get(0);
        
        //move forward as long as we see 1:1 chain
        while (indegree.get(decend).size() == 1) {
          rename.append(decend.name);
          indegree.remove(decend);  
          
          //make sure we only move forward if it's an only child
          if (decend.neighbors.size() != 1) break;
          decend = decend.neighbors.get(0);
        }
        
        //Rename and update neighbors
        Node merge = new Node(rename.toString());
        merge.neighbors = decend.neighbors;
        
        // incoming to merge (parents of node)
        indegree.put(merge, indegree.get(node));

        // incoming from merge (to  grandchildren of node)
        for (Node grandchild : decend.neighbors) {
          indegree.put(grandchild, Arrays.asList(merge));
        }

        // set parents by removing current node, and add the new merged node
        for (Node parents : indegree.get(node)) {
          parents.neighbors.remove(node);
          parents.neighbors.add(merge);
        }

        //remove node and its only child
        indegree.remove(node);
        //indegree.remove(decend);
      }
    }
    
    return new ArrayList<>(indegree.keySet());
  }
}
