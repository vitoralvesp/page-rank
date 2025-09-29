#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* create_graph(int num_vertices) {
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int*) calloc(num_vertices, sizeof(int));
    }
    return graph;
}

void add_edge(Graph* graph, int start, int end) {
    if (start >= graph->num_vertices || end >= graph->num_vertices || start < 0 || end < 0) {
        printf(">> vertices invalidos!\n");
        return;
    }
    graph->adj_matrix[start][end] = 1;
    graph->adj_matrix[end][start] = 1;
}

void add_vertices(Graph* graph, int num_vertices) {
    int old_size = graph->num_vertices;
    int new_size = old_size + num_vertices;

    graph->adj_matrix = (int**) realloc(graph->adj_matrix, new_size * sizeof(int*));
    for (int i = 0; i < new_size; i++) {
        graph->adj_matrix[i] = (int*) realloc(graph->adj_matrix[i], new_size * sizeof(int));
    }

    for (int i = old_size; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            graph->adj_matrix[i][j] = 0;
            graph->adj_matrix[j][i] = 0;
        }
    }

    graph->num_vertices = new_size;
}

void remove_edge(Graph* graph, int start, int end) {
    if (start >= graph->num_vertices || end >= graph->num_vertices || start < 0 || end < 0) {
        printf(">> vertices invalidos!\n");
        return;
    }
    graph->adj_matrix[start][end] = 0;
    graph->adj_matrix[end][start] = 0;
}

void remove_vertices(Graph* graph, int num_vertices) {
    if (num_vertices >= graph->num_vertices) {
        printf(">> remocao invalida!\n");
        return;
    }

    int new_size = graph->num_vertices - num_vertices;

    for (int i = new_size; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }

    graph->adj_matrix = (int**) realloc(graph->adj_matrix, new_size * sizeof(int*));
    graph->num_vertices = new_size;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void print_graph(Graph* graph) {
    printf(">> numero de vertices: %d\n", graph->num_vertices);
    printf(">> matriz de adjacencia:\n");

    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void dfs(Graph *graph, int v, int *visited) {
    visited[v] = 1;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[v][i] && !visited[i]) dfs(graph, i, visited);
    }
}

void graph_conectivity(Graph *graph) {
    if (graph->num_vertices == 0) {
        printf(">> o grafo não possui vertices.\n");
        return;
    }

    int *visited = (int*) calloc(graph->num_vertices, sizeof(int));
    if (!visited) {
        perror(">> erro de alocacao em graph_conectivity");
        return;
    }

    dfs(graph, 0, visited);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            printf(">> o grafo é conexo.\n");
            free(visited);
            return;
        }
    }

    printf(">> o grafo é conexo.\n");
}
free(visited);

double* calculate_pagerank(Graph* graph, double damping_factor, int max_iterations, double tolerance) {
    int n = graph->num_vertices;
    double *rank = (double*) malloc(n * sizeof(double));
    double *new_rank = (double*) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) rank[i] = 1.0 / n;

    for (int iter = 0; iter < max_iterations; iter++) {
        for (int i = 0; i < n; i++) new_rank[i] = (1.0 - damping_factor) / n;

        for (int j = 0; j < n; j++) {
            int out_degree = 0;
            for (int k = 0; k < n; k++) {
                if (graph->adj_matrix[j][k]) out_degree++;
            }

            if (out_degree == 0) continue;

            for (int k = 0; k < n; k++) {
                if (graph->adj_matrix[j][k]) {
                    new_rank[k] += damping_factor * (rank[j] / out_degree);
                }
            }
        }

        double diff = 0.0;
        for (int i = 0; i < n; i++) diff += fabs(new_rank[i] - rank[i]);
        if (diff < tolerance) break;

        for (int i = 0; i < n; i++) rank[i] = new_rank[i];
    }

    free(new_rank);
    return rank;
}

void free_pagerank(double* pagerank) {
    free(pagerank);
}

void print_pagerank(double* pagerank, int num_vertices) {
    printf("Valores de PageRank:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertice %d: %.6f\n", i, pagerank[i]);
    }
}

void save_pagerank_to_file(double* pagerank, int num_vertices, const char* filepath) {
    FILE *file = fopen(filepath, "w");
    if (!file) {
        perror("Erro ao salvar PageRank");
        return;
    }

    for (int i = 0; i < num_vertices; i++) {
        fprintf(file, "Vertice %d: %.6f\n", i, pagerank[i]);
    }

    fclose(file);
}
