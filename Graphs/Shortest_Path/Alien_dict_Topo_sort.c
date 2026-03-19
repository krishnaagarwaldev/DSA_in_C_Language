#include <stdio.h>
#include <string.h>

#define MAX 26

/*
PROBLEM STATEMENT:
Given a sorted dictionary of an alien language, 
find the order of characters in the language.

APPROACH:
1. Compare adjacent words in the dictionary.
2. For the first character that differs between two words:
   - Add a directed edge from first word's char to second word's char.
3. The edges form a **DAG** of characters.
4. Perform **topological sort** on the DAG to get character order.

INTUITION:
- The relative order of first differing letters determines precedence.
- Topological sort of DAG = valid order of letters.

TIME COMPLEXITY: O(N*L + V + E)
- N = number of words
- L = max length of word
- V = characters (≤26)
- E = edges (≤V^2)
*/

int adj[MAX][MAX]; // adjacency matrix
int visited[MAX];
int n; // number of words
char words[100][100]; // dictionary words
char order[26];
int idx = 0;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < MAX; v++) {
        if (adj[u][v] && !visited[v])
            dfs(v);
    }
    order[idx++] = u + 'a'; // store in reverse topo order
}

int min(int a, int b) { return a < b ? a : b; }

void alienOrder() {
    // Build graph
    for (int i = 0; i < n - 1; i++) {
        int len = min(strlen(words[i]), strlen(words[i + 1]));
        for (int j = 0; j < len; j++) {
            if (words[i][j] != words[i + 1][j]) {
                adj[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
                break;
            }
        }
    }

    // DFS topological sort
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    idx = 0;
    for (int i = 0; i < MAX; i++) {
        // only do DFS for characters present in words
        int present = 0;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < strlen(words[j]); k++)
                if (words[j][k] - 'a' == i) present = 1;
        if (present && !visited[i])
            dfs(i);
    }

    // Print order in reverse
    printf("Alien Dictionary Order: ");
    for (int i = idx - 1; i >= 0; i--)
        printf("%c", order[i]);
    printf("\n");
}

int main() {
    n = 5;
    strcpy(words[0], "baa");
    strcpy(words[1], "abcd");
    strcpy(words[2], "abca");
    strcpy(words[3], "cab");
    strcpy(words[4], "cad");

    alienOrder();
    return 0;
}