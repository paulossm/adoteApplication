#ifndef FAMILIA_H
#define FAMILIA_H

#include <Wt/WContainerWidget>


class Familia : public Wt::WContainerWidget
{
    public:
        Familia();
        virtual ~Familia();
    private:
        struct Membros {
            std::string nome;
            std::string parentesco;
        };

        void novoMembro();
        void excluirMembro();
        void atualizarMembros();
};

#endif // FAMILIA_H
