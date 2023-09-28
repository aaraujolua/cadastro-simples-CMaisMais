#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Definição da estrutura Usuario para armazenar informações do usuário
struct Usuario {
    string name;
    int age;
    float weight;
    float height;
};

// Função para calcular o IMC (Índice de Massa Corporal)
float CalculateBMI(float weight, float height) {
    return weight / (height * height);
}

int main() {
    vector<Usuario> usuarios; // Vetor para armazenar os usuários

    while (true) {
        // Exibe o menu de opções
        cout << "BEM VINDO! SELECIONE UM DOS NUMEROS A SEGUIR, DIGITANDO LOGO ABAIXO" << endl;
        cout << "1. Cadastrar usuario" << endl;
        cout << "2. Usuarios cadastrados" << endl;
        cout << "3. Encontrar usuario" << endl;
        cout << "4. Deletar usuario" << endl;
        cout << "5. Sair do programa" << endl;

        int option;

        while (true) {
            // Solicita a entrada do usuário e verifica se é um número válido
            if (cin >> option) {
                break;
            }
            else {
                cout << "Entrada invalida. Por favor, insira um numero." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (option) {
        case 1: {
            Usuario usuario;
            cout << "Nome: ";
            cin >> usuario.name;

            while (true) {
                cout << "Idade: ";
                if (cin >> usuario.age) {
                    break;
                }
                else {
                    cout << "Entrada invalida para idade. Por favor, insira um numero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Peso: ";
                if (cin >> usuario.weight) {
                    break;
                }
                else {
                    cout << "Entrada invalida para peso. Por favor, insira um numero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            while (true) {
                cout << "Altura: ";
                if (cin >> usuario.height) {
                    break;
                }
                else {
                    cout << "Entrada invalida para altura. Por favor, insira um numero." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            usuarios.push_back(usuario); // Adiciona o usuário ao vetor
            cout << "Usuario cadastrado com sucesso!" << endl;
            break;
        }
        case 2: {
            if (usuarios.empty()) {
                cout << "Ainda nao existem usuarios cadastrados nesse sistema." << endl;
            }
            else {
                cout << "Lista de usuarios cadastrados:" << endl;
                for (const Usuario& usuario : usuarios) {
                    // Exibe informações do usuário e calcula o IMC
                    cout << "Nome: " << usuario.name << endl;
                    cout << "Idade: " << usuario.age << endl;
                    cout << fixed << setprecision(2) << "IMC: " << CalculateBMI(usuario.weight, usuario.height) << endl;
                }
            }
            break;
        }
        case 3: {
            cout << "Digite o nome do usuario que deseja encontrar: ";
            string searchName;
            cin >> searchName;

            bool found = false;
            for (const Usuario& usuario : usuarios) {
                if (usuario.name == searchName) {
                    // Exibe informações do usuário encontrado
                    cout << "Nome: " << usuario.name << endl;
                    cout << "Idade: " << usuario.age << endl;
                    cout << fixed << setprecision(2) << "IMC: " << CalculateBMI(usuario.weight, usuario.height) << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Esse usuario nao existe no sistema." << endl;
            }
            break;
        }
        case 4: {
            if (usuarios.empty()) {
                cout << "Ainda nao existem usuarios cadastrados nesse sistema." << endl;
            }
            else {
                cout << "Digite o nome do usuario que deseja excluir: ";
                string deleteUsuario;
                cin >> deleteUsuario;

                bool found = false;
                for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
                    if (it->name == deleteUsuario) {
                        it = usuarios.erase(it); // Remove o usuário encontrado
                        cout << "Usuario excluido com sucesso!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Esse usuario nao existe no sistema." << endl;
                }
            }
            break;
        }
        case 5: {
            cout << "Saindo do programa." << endl;
            return 0;
        }
        default:
            cout << "Desculpe, esse numero nao existe no menu :(" << endl;
            break;
        }
    }

    return 0;
}