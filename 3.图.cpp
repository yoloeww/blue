#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include<stack>
using namespace std;


class Node;

class Edge {
public:
    int weight;
    Node* from;
    Node* to;

    Edge(int w, Node* from, Node* to) : weight(w), from(from), to(to) {

    }
};

class Node {
public:
    int value;
    int in; // 入度
    int out; // 出度
    vector<Node*> nexts; // 指向的边
    vector<Edge*> edges;
    Node(int value, int in, int out) : value(value), in(in), out(out) {

    }
    Node(int value) : value(value) {

    }

};

class Graph {
public:
    unordered_map<int, Node*> nodes;
    unordered_set<Edge*> edges;


    Graph() {
        nodes = unordered_map<int, Node*>();
        edges = unordered_set<Edge*>();
    }

};
Graph createGraph(vector<vector<int>>& matrix) {
    Graph graph;
    for (size_t i = 0; i < matrix.size(); i++) {
        int weight = matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];
        if (graph.nodes.find(from) == graph.nodes.end()) {
            Node* fromNode = new Node(from);
            graph.nodes[from] = fromNode;
        }
        if (graph.nodes.find(to) == graph.nodes.end()) {
            Node* toNode = new Node(to);
            graph.nodes[to] = toNode;
        }
        Node* fromNode = graph.nodes[from];
        Node* toNode = graph.nodes[to];
        fromNode->out++;
        toNode->in++;
        Edge* newEdge = new Edge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(newEdge);
        graph.edges.insert(newEdge);
    }
    return graph;
}
void deepFirstTraversal(Node * node) {
    if (node == nullptr) {
        return;
    }
    stack<Node*> stack;
    unordered_set<Node*> set;
    stack.push(node);
    set.insert(node);
    while (!stack.empty()) {
        Node* cur = stack.top();
        stack.pop();
        cout << cur->value << " ";
        for (Node* next : cur->nexts) {
            if (set.find(next) == set.end()) {
                stack.push(cur);
                stack.push(next);
                set.insert(next);
                cout << next->value << " ";
                break;
            }
        }
    }
}
int main() {
    vector<vector<int>> a;
    int n, m;
    cin >> n >> m;
    a.resize(n);          //4列
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= m; j++) {
            int c, b;
            cin >> c >> b;
            a[i][j] = c;
            a[i][j + 1] = b;
        }
    }
    for (size_t i = 0; i < a.size(); i++) {
        a[i].resize(m);          //4列
        for (size_t j = 0; j < a[i].size(); j++) {
            int x;
            cin >> x;
            a[i][j] = x;           //赋值
        }
    }
    Graph g = createGraph(a);
    for (auto x : g.nodes)//遍历整个map，输出key及其对应的value值
        cout << x.first << "  " << x.second << endl;

    for (auto edge : g.edges) {
        cout << edge << endl;
    }

    return 0;
}
