#ifndef MANTO_DE_ENCHANTRIX
#define MANTO_DE_ENCHANTRIX

#include "armadura.h"

class MantoDeEnchantix : public Armadura {
    public:
        MantoDeEnchantix() : Armadura("Manto de Enchantix", "Aumenta defesa em 40% por 3 turnos.") {}
        void aplicarEfeito(Personagem& alvo) override{
             alvo.aumentarDefesaTemporaria(0.4, 3);
        }
};

#endif