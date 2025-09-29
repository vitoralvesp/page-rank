#include "graph.h"

/** 
 * @brief Opção de escrever dados em um arquivo.
 * @param graph Ponteiro para o grafo.
 * @param filepath Caminho do arquivo onde os dados serão escritos.
 * @param size Tamanho dos dados a serem escritos.
 */
void write_data(Graph *graph, char *filepath, int size);

/**
 * @brief Adiciona uma aresta ao grafo.
 * @param graph Ponteiro para o grafo.
 * @param start Vértice de origem.
 * @param end Vértice de destino.
 */
void menu_add_edge(Graph* graph, int start, int end);

/**
 * @brief Adiciona vértices ao grafo.
 * @param graph Ponteiro para o grafo.
 * @param num_vertices Número de vértices a serem adicionados.
 */
void menu_add_vertices(Graph* graph, int num_vertices);

/**
 * @brief Remove uma aresta do grafo.
 * @param graph Ponteiro para o grafo.
 * @param start Vértice de origem.
 * @param end Vértice de destino.
 */
void remove_edge(Graph* graph, int start, int end);

/**
 * @brief Remove vértices do grafo.
 * @param graph Ponteiro para o grafo.
 * @param num_vertices Número de vértices a serem removidos.
 */
void menu_remove_vertices(Graph* graph, int num_vertices);

/**
 * @brief Libera a memória alocada para o grafo.
 * @param graph Ponteiro para o grafo a ser liberado.
 */
void menu_free_graph(Graph* graph);

/**
 * @brief Imprime o grafo.
 * @param graph Ponteiro para o grafo.
 */
void menu_print_graph(Graph* graph);

/**
 * @brief Demonstra a conectividade de um grafo.
 */
void graph_conectivity(Graph *graph);

/**
 * @brief Demonstra o conteúdo do arquivo
 * @param filepath Caminho do arquivo
 * @param size Tamanho do arquivo
 */
void show_file_content(char *filepath, int size);

/**
 * @brief Encerra o programa.
 */
void exit();