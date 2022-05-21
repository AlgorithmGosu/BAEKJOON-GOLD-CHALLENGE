// 1991 트리 순회
// - pre-order: root->left->right
// - in-order: left->root->right
// - post-order: left->right->root


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void preorder(vector<pair<char, char>> graph[], bool visited[], int node)
{
    if (visited[node] == true || node == -1)
        return;
    
    char ch = node + 65;
    cout<<ch;
    visited[node] = true;
    
    for(int i = 0;i < graph[node].size();i++)
    {
        int left = graph[node][i].first;
        int right = graph[node][i].second;

        preorder(graph, visited, left);
        preorder(graph, visited, right);
    }
}

void inorder(vector<pair<char, char>> graph[], bool visited[], int node)
{
    if (visited[node] == true || node == -1)
        return;
    
    visited[node] = true;
    for(int i = 0;i < graph[node].size();i++)
    {
        int left = graph[node][i].first;
        int right = graph[node][i].second;

        inorder(graph, visited, left);
        
        char ch = node + 65;
        cout<<ch;
        
        inorder(graph, visited, right);
    }
}

void postorder(vector<pair<char, char>> graph[], bool visited[], int node)
{
    if (visited[node] == true || node == -1)
        return;
    
    visited[node] = true;
    
    for(int i = 0;i < graph[node].size();i++)
    {
        int left = graph[node][i].first;
        int right = graph[node][i].second;

        postorder(graph, visited, left);
        postorder(graph, visited, right);
        
        char ch = node + 65;
        cout<<ch;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // N(node)
    int N;
    cin>>N;
    
    // A:1 ~ Z: 26
    vector<pair<char, char>> graph[26];
    bool visited[26];
    
    for(int i = 0;i < N;i++)
    {
        char A, B, C;
        cin>>A>>B>>C;
        
        B = (B == '.') ? -1 : B - 65;
        C = (C == '.') ? -1 : C - 65;
        
        graph[A - 65].push_back({B, C});
    }
    
    // preorder
    fill_n(visited, 26, false);
    preorder(graph, visited, 0);
    cout<<"\n";
    
    // inorder
    fill_n(visited, 26, false);
    inorder(graph, visited, 0);
    cout<<"\n";
    
    // postorder
    fill_n(visited, 26, false);
    postorder(graph, visited, 0);
    cout<<"\n";
}

