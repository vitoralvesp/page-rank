/**
 * @brief Estrutura de dados para representar um grafo usando uma matriz de adjacência.
 * @param num_vertices Número de vértices no grafo.
 * @param adj_matrix Matriz de adjacência representando as conexões entre os vértices. 
 */
typedef struct Graph {
    int num_vertices;
    int **adj_matrix;
} Graph;

/**
 * @brief Cria um grafo com um número especificado de vértices.
 * @param num_vertices Número de vértices no grafo.
 * @return Ponteiro para o grafo criado.
 */
Graph* create_graph(int num_vertices);

/**
 * @brief Adiciona uma aresta direcionada de um vértice para outro no grafo.
 * @param graph Ponteiro para o grafo.
 * @param src Vértice de origem.
 * @param dest Vértice de destino.
 */
void add_edge(Graph* graph, int src, int dest);

/**
 * @brief Libera a memória alocada para o grafo.
 * @param graph Ponteiro para o grafo a ser liberado.
 */
void free_graph(Graph* graph);

/**
 * @brief Imprime a matriz de adjacência do grafo.
 * @param graph Ponteiro para o grafo.
 */
void print_graph(Graph* graph);

/**
 * @brief Lê um grafo de um arquivo.
 * @param filepath Caminho do arquivo contendo a representação do grafo.
 * @return Ponteiro para o grafo lido.
 */
Graph* read_graph_from_file(const char* filepath);

/**
 * @brief Escreve a matriz de adjacência do grafo em um arquivo.
 * @param graph Ponteiro para o grafo.
 * @param filepath Caminho do arquivo onde a matriz será escrita.
 */
void write_graph_to_file(Graph* graph, const char* filepath);

/**
 * @brief Calcula o PageRank dos vértices do grafo.
 * @param graph Ponteiro para o grafo.
 * @param damping_factor Fator de amortecimento (geralmente 0.85).
 * @param max_iterations Número máximo de iterações para o cálculo.
 * @param tolerance Tolerância para a convergência do algoritmo.
 * @return Vetor contendo os valores de PageRank para cada vértice.
 */
double* calculate_pagerank(Graph* graph, double damping_factor, int max_iterations, double tolerance);

/**
 * @brief Libera a memória alocada para o vetor de PageRank.
 * @param pagerank Vetor de PageRank a ser liberado.
 */
void free_pagerank(double* pagerank);

/**
 * @brief Imprime os valores de PageRank dos vértices.
 * @param pagerank Vetor contendo os valores de PageRank.
 * @param num_vertices Número de vértices no grafo.
 */
void print_pagerank(double* pagerank, int num_vertices);

/**
 * @brief Salva os valores de PageRank em um arquivo.
 * @param pagerank Vetor contendo os valores de PageRank.
 * @param num_vertices Número de vértices no grafo.
 * @param filepath Caminho do arquivo onde os valores serão salvos.
 */
void save_pagerank_to_file(double* pagerank, int num_vertices, const char* filepath);

