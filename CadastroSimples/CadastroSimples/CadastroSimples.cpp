#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Defini��o da estrutura Usuario para armazenar informa��es do usu�rio
struct Usuario {
    string name;
    int age;
    float weight;
    float height;
};

// Fun��o para calcular o IMC (�ndice de Massa Corporal)
float CalculateBMI(float weight, float height) {
    return weight / (height * height);
}

int main() {
    vector<Usuario> usuarios; // Vetor para armazenar os usu�rios

    while (true) {
        // Exibe o menu de op��es
        cout << "BEM VINDO! SELECIONE UM DOS NUMEROS A SEGUIR, DIGITANDO LOGO ABAIXO" << endl;
        cout << "1. Cadastrar usuario" << endl;
        cout << "2. Usuarios cadastrados" << endl;
        cout << "3. Encontrar usuario" << endl;
        cout << "4. Deletar usuario" << endl;
        cout << "5. Sair do programa" << endl;

        int option;

        while (true) {
            // Solicita a entrada do usu�rio e verifica se � um n�mero v�lido
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
            usuarios.push_back(usuario); // Adiciona o usu�rio ao vetor
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
                    // Exibe informa��es do usu�rio e calcula o IMC
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
                    // Exibe informa��es do usu�rio encontrado
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
                        it = usuarios.erase(it); // Remove o usu�rio encontrado
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