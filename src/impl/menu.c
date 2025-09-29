#include <stdio.h>
#include "./header/menu.h"
#include "./header/graph.h"

void write_data(Graph *graph, char *filepath, int size) {
    FILE *file = fopen(filepath, "w");
    if (!file) {
        perror(">> erro ao abrir arquivo");
        return;
    }

    fprintf(file, ">> numero de vertices: %d\n", graph->num_vertices);
    fprintf(file, ">> matriz de adjacencia:\n");

    for (int i = 0; i < graph->num_vertices && i < size; i++) {
        for (int j = 0; j < graph->num_vertices && j < size; j++) {
            fprintf(file, "%d ", graph->adj_matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void menu_add_edge(Graph *graph, int start, int end) {
    add_edge(graph, start, end);
}

void menu_add_vertices(Graph *graph, int num_vertices) {
    add_vertices(graph, num_vertices);
}

void menu_remove_edges(Graph *graph, int start, int end) {
    remove_edge(graph, start, end);
}

void menu_remove_vertices(Graph *graph, int num_vertices) {
    remove_vertices(graph, num_vertices);
}

void menu_free_graph(Graph *graph) {
    free_graph(graph);
}

void menu_print_graph(Graph* graph) {
    print_graph(graph);
}

void exit(Graph* graph) {
    printf(">> encerrando o programa...\n");
    menu_free_graph(graph);
    exit(0);
}