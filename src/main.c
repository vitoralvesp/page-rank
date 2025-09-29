/**
 * @brief Este programa corresponde a implementação do algoritmo PageRank para o projeto 1 de teoria dos grafos.
 * @author Vitor Alves Pereira - 10410862
 * @date 2025/2
 */
#include <stdio.h>
#include <stdlib.h>
#include "./header/menu.h"
#include "./header/graph.h"

int main() {
    Graph *graph = NULL;
    int choice;

    do {
        printf("---\nMENU\n");
        printf("1. criar grafo\n");
        printf("2. adicionar vertices\n");
        printf("3. adicionar aresta\n");
        printf("4. remover aresta\n");
        printf("5. remover vertices\n");
        printf("6. imprimir grafo\n");
        printf("7. verificar conectividade\n");
        printf("8. calcular PageRank\n");
        printf("9. salvar grafo em arquivo\n");
        printf("10. mostrar arquivo salvo\n");
        printf("11. sair\n");
        printf(">> escolha uma opção: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int v;
            printf(">> numero de vertices: ");
            scanf("%d", &v);
            if (graph) free_graph(graph);
            graph = create_graph(v);

        } else if (choice == 2) {
            int v;
            printf(">> quantidade de vertices a adicionar: ");
            scanf("%d", &v);
            add_vertices(graph, v);

        } else if (choice == 3) {
            int u, v;
            printf(">> inserir a origem e destino na forma (origem destino): ");
            scanf("%d %d", &u, &v);
            add_edge(graph, u, v);

        } else if (choice == 4) {
            int u, v;
            printf(">> inserir a origem e destino na forma (origem destino): ");
            scanf("%d %d", &u, &v);
            remove_edge(graph, u, v);

        } else if (choice == 5) {
            int v;
            printf(">> insira a quantidade de vertices a remover: ");
            scanf("%d", &v);
            remove_vertices(graph, v);

        } else if (choice == 6) {
            print_graph(graph);

        } else if (choice == 7) {
            graph_conectivity(graph);

        } else if (choice == 8) {
            double *pr = calculate_pagerank(graph, 0.85, 100, 1e-6);
            print_pagerank(pr, graph->num_vertices);
            free_pagerank(pr);

        } else if (choice == 9) {
            char path[100];
            printf(">> insira o caminho do arquivo: ");
            scanf("%s", path);
            write_data(graph, path, graph->num_vertices);

        } else if (choice == 10) {
            char path[100];
            printf(">> insira o caminho do arquivo: ");
            scanf("%s", path);
            show_file_content(path, 1000);
        }

    } while (choice != 11);

    exit(graph);

    return 0;
}
