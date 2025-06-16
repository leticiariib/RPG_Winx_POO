#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

template <typename T>
class Inventario {
    vector<T> itens;

    public:
        void adicionarItem(const T& item) {
            itens.push_back(item);
            cout << "Item '" << item.getNome() << "' adicionado ao inventário.\n";
        }

        void removerItem(const string& nome) {
            for (auto it = itens.begin(); it != itens.end(); ++it) {
                if (it->getNome() == nome) {
                    itens.erase(it);
                    cout << "Item '" << nome << "' removido do inventário.\n";
                    return;
                }
            }
            cout << "Item '" << nome << "' não encontrado no inventário.\n";
        }

        void mostrarItens() const {
            if (itens.empty()) {
                cout << "Inventário vazio.\n";
                return;
            }
            cout << "Itens no inventário:\n";
            for (const auto& item : itens) {
                item.mostrarInfo();
                cout << "------------------------\n";
            }
        }
};

#endif