#include <iostream>
#include <map>
#include <set>
/* Adjacency list for a (non-directional) graph implimentation */

template <class T>
class adj_list
{
  public:
   void add_node (T data);
   void add_edge(T first, T second);
   void remove_node (const struct node &n);
   void remove_edge (const struct node &n, const struct node &u);
   void dfs();
   void bfs();
   void print_list() const;
    
  private:
   std::map<T, std::set<T>> graph;

};

template <class T>
void adj_list<T>::add_node(T data)
{
  std::set<T> s;
  graph.insert(std::make_pair(data, s));
}

template <class T>
void adj_list<T>::add_edge(T first, T second)
{
  graph[first].insert(second);
 
}

template <class T>
void adj_list<T>:: print_list() const
{
  //print out adjacency list
  for (auto i : graph)
  {
    std::cout<<i.first<<" ";
    for (auto it = i.second.begin(); 
         it!=i.second.end(); ++it) 
    {
      std::cout<<*it<<" ";
    }
   std::cout<<std::endl;
  }
}
int main()
{
  adj_list<int> example; 
  
  for (int i = 1; i<=5; i++)
   example.add_node(i);

  example.add_edge(1,2);
  example.add_edge(1,4);
  example.add_edge(2,1);
  example.add_edge(2,4);
  example.add_edge(2,5);
  example.add_edge(3,4);
  example.add_edge(4,2);
  example.add_edge(4,4);
  example.add_edge(4,1);
  example.add_edge(4,2);
  example.add_edge(5,2);

  example.print_list();

  return 0;
}

