import java.util.*;
public class Main {
  static class Graph{
    int V;
    LinkedList<Integer> adjListArr[];

    Graph(int V){
      this.V=V;
      adjListArr = new LinkedList[V];
      for(int i = 0; i < V ; i++){
        adjListArr[i] = new LinkedList<>();
      }
    }
  }

  static void printGraph(Graph g){
    int i;
    for(i=0;i<g.V;i++){
      System.out.println("Adjacency list of "+i);
      for(Integer j: g.adjListArr[i]){
         System.out.print(j);
         System.out.print("->");
      }
      System.out.println();
    }
  }

  static void addedge(Graph g, int s, int d){
    g.adjListArr[s].addFirst(d);
    g.adjListArr[d].addFirst(s);
  }

  public static void main(String[] args) {
    System.out.println("Enter number of vertices ");
    Scanner in = new Scanner(System.in);
    int V=in.nextInt();
    Graph g= new Graph(V);
    System.out.println("Enter edges(-1 to stop) ");
    int s,d;
    s=in.nextInt();
    while(s!=-1)
    {
      d=in.nextInt();
      addedge(g,s,d);
      s=in.nextInt();
    }
    printGraph(g);
  }
}
