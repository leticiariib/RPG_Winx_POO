#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <vector>
#include <string>
#include "inventario/item.h" 

using namespace std;

template <typename T> 
class Inventario {
    vector<T> itens;

public:
    ~Inventario() {
        for (T item : itens) {
            delete item;
        }
        itens.clear();
    }

    void adicionarItem(T item) { 
        itens.push_back(item);
        cout << "Item '" << item->getNome() << "' adicionado ao inventário.\n";
    }

    T getItem(int indice) {
        if (indice >= 0 && indice < itens.size()) {
            return itens[indice];
        }
        return nullptr; 
    }

    void removerItem(int indice) {
        if (indice >= 0 && indice < itens.size()) {
            T item = itens[indice];
            cout << "Item '" << item->getNome() << "' consumido e removido do inventário.\n";
            delete item; 
            itens.erase(itens.begin() + indice);
        }
    }

    void mostrarItens() const {
        if (itens.empty()) {
            cout << "Inventário vazio.\n";
            return;
        }
        cout << "\n--- Itens no Inventário ---\n";
        for (int i = 0; i < itens.size(); ++i) {
            cout << i + 1 << ". ";
            itens[i]->mostrarInfo(); 
            cout << "------------------------\n";
        }
    }
    
    int getTamanho() const {
        return itens.size();
    }
};

#endif