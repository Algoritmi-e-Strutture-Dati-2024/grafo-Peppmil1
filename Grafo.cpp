#include <iostream>
#define MAX_NODI 100
#define INF 1000000000 // Indica assenza di collegamento

template <typename T>
class StrutturaGrafo {
private:
    T elementi[MAX_NODI]; // Nodi del grafo
    int matriceAdiacenza[MAX_NODI][MAX_NODI]; // Matrice di connessione
    bool nodiPresenti[MAX_NODI]; // Stato dei nodi
    int numeroNodi = 0; // Contatore dei nodi

public:
    // Costruttore
    StrutturaGrafo() {
        for (int i = 0; i < MAX_NODI; ++i) {
            nodiPresenti[i] = false;
            for (int j = 0; j < MAX_NODI; ++j) {
                matriceAdiacenza[i][j] = INF;
            }
            matriceAdiacenza[i][i] = 0; // Nessun costo tra un nodo e se stesso
        }
    }

    // Inserisce un nuovo nodo
    void inserisciNodo(const T& elemento) {
        if (numeroNodi >= MAX_NODI) {
            std::cout << "Errore: numero massimo di nodi raggiunto.\n";
            return;
        }
        for (int i = 0; i < numeroNodi; ++i) {
            if (nodiPresenti[i] && elementi[i] == elemento) {
                std::cout << "Errore: il nodo esiste già.\n";
                return;
            }
        }
        elementi[numeroNodi] = elemento;
        nodiPresenti[numeroNodi] = true;
        numeroNodi++;
    }

    // Inserisce un arco tra due nodi con un peso specifico
    void inserisciArco(const T& sorgente, const T& destinazione, int peso) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = peso;
    }

    // Rimuove un nodo
    void eliminaNodo(const T& elemento) {
        int indice = trovaIndice(elemento);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        nodiPresenti[indice] = false;
        for (int i = 0; i < MAX_NODI; ++i) {
            matriceAdiacenza[indice][i] = INF;
            matriceAdiacenza[i][indice] = INF;
        }
    }

    // Rimuove un arco tra due nodi
    void eliminaArco(const T& sorgente, const T& destinazione) {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            std::cout << "Errore: uno o entrambi i nodi non esistono.\n";
            return;
        }
        matriceAdiacenza[indiceSorgente][indiceDestinazione] = INF;
    }

    // Elenca i nodi connessi a un nodo specifico
    void mostraConnessi(const T& elemento) const {
        int indice = trovaIndice(elemento);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return;
        }
        std::cout << "Nodi connessi a " << elemento << ": ";
        for (int i = 0; i < numeroNodi; ++i) {
            if (nodiPresenti[i] && matriceAdiacenza[indice][i] != INF) {
                std::cout << elementi[i] << " (peso: " << matriceAdiacenza[indice][i] << ") ";
            }
        }
        std::cout << "\n";
    }

    // Visualizza la matrice di adiacenza
    void mostraMatrice() const {
        std::cout << "Matrice di Adiacenza:\n";
        for (int i = 0; i < numeroNodi; ++i) {
            if (!nodiPresenti[i]) continue;

            for (int j = 0; j < numeroNodi; ++j) {
                if (!nodiPresenti[j]) continue;

                if (matriceAdiacenza[i][j] == INF) {
                    std::cout << "INF ";
                } else {
                    std::cout << matriceAdiacenza[i][j] << " ";
                }
            }
            std::cout << "\n";
        }
    }

    // Verifica l'esistenza di un nodo
    bool presenzaNodo(const T& elemento) const {
        return trovaIndice(elemento) != -1;
    }

    // Verifica l'esistenza di un arco
    bool presenzaArco(const T& sorgente, const T& destinazione) const {
        int indiceSorgente = trovaIndice(sorgente);
        int indiceDestinazione = trovaIndice(destinazione);

        if (indiceSorgente == -1 || indiceDestinazione == -1) {
            return false;
        }
        return matriceAdiacenza[indiceSorgente][indiceDestinazione] != INF;
    }

    // Trova l'indice di un nodo
    int trovaIndice(const T& elemento) const {
        for (int i = 0; i < numeroNodi; ++i) {
            if (nodiPresenti[i] && elementi[i] == elemento) {
                return i;
            }
        }
        return -1;
    }

    // Individua l'arco con peso minimo da un nodo
    int arcoMinimo(const T& elemento) const {
        int indice = trovaIndice(elemento);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return -1;
        }

        int pesoMinimo = INF;
        for (int i = 0; i < numeroNodi; ++i) {
            if (nodiPresenti[i] && matriceAdiacenza[indice][i] != INF) {
                if (matriceAdiacenza[indice][i] < pesoMinimo) {
                    pesoMinimo = matriceAdiacenza[indice][i];
                }
            }
        }

        return (pesoMinimo == INF) ? -1 : pesoMinimo;
    }
};
