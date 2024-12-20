#include <iostream>
#include "StrutturaGrafo.cpp" // Inclusione della classe per la gestione del grafo

int main() {
    // Inizializzazione del grafo
    StrutturaGrafo<int> rete;

    // Inserimento dei nodi (valori numerici interi)
    rete.inserisciNodo(1);
    rete.inserisciNodo(2);
    rete.inserisciNodo(3);
    rete.inserisciNodo(4);
    rete.inserisciNodo(5);

    // Collegamento dei nodi tramite archi con relativi pesi
    rete.inserisciArco(1, 2, 5);
    rete.inserisciArco(1, 3, 3);
    rete.inserisciArco(2, 4, 2);
    rete.inserisciArco(3, 5, 4);
    rete.inserisciArco(4, 5, 1);
    rete.inserisciArco(5, 2, 6);

    // Visualizzazione della rappresentazione del grafo
    rete.mostraMatriceAdiacenza();

    // Controllo dell'esistenza di un nodo
    std::cout << "Il nodo 3 è presente nella rete? " << (rete.presenzaNodo(3) ? "Sì" : "No") << std::endl;

    // Controllo dell'esistenza di un collegamento
    std::cout << "Esiste un collegamento tra 1 e 2? " << (rete.presenzaCollegamento(1, 2) ? "Sì" : "No") << std::endl;
    std::cout << "Esiste un collegamento tra 1 e 4? " << (rete.presenzaCollegamento(1, 4) ? "Sì" : "No") << std::endl;

    // Elenco dei nodi collegati a un nodo specifico
    rete.visualizzaNodiConnessi(1);

    // Rimozione di un collegamento
    rete.eliminaCollegamento(1, 2);
    std::cout << "Matrice di adiacenza dopo la rimozione del collegamento tra 1 e 2:" << std::endl;
    rete.mostraMatriceAdiacenza();

    // Rimozione di un nodo
    rete.eliminaNodo(3);
    std::cout << "Matrice di adiacenza dopo l'eliminazione del nodo 3:" << std::endl;
    rete.mostraMatriceAdiacenza();

    // Inserimento di un nuovo nodo e collegamento
    rete.inserisciNodo(6);
    rete.inserisciArco(5, 6, 7);
    std::cout << "Matrice di adiacenza dopo l'aggiunta del nodo 6 e del collegamento tra 5 e 6:" << std::endl;
    rete.mostraMatriceAdiacenza();

    // Verifica della connettività tra due nodi
    std::cout << "Il nodo 1 è connesso al nodo 5? " << (rete.presenzaCollegamento(1, 5) ? "Sì" : "No") << std::endl;

    // Individuazione del collegamento con peso minimo per un nodo
    int pesoMinimo = rete.collegamentoMinimo(5);
    if (pesoMinimo != -1) {
        std::cout << "Il collegamento con peso minimo da 5 ha peso: " << pesoMinimo << std::endl;
    } else {
        std::cout << "Non ci sono collegamenti uscenti dal nodo 5." << std::endl;
    }

    return 0;
}
