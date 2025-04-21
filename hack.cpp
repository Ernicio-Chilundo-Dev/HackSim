#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>
#include <fstream>
#include  <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;

vector<string> loadFakeCode (const string& filename){
    ifstream file(filename);
    vector<string>lines;
    string line;

    while(getline(file, line)){
        lines.push_back(line);
    }

    return lines;
}

void typeFakeCode(const vector<string>& code){
    int row = 0;
    size_t LineIndex = 0;
    
    srand(time(0));

    while (true)
    {
        int ch = getch();//Espera um tecla
        if (ch == 27) break; // tecl ESC para sair

        //Mostra de 1-3 linhas por tecla
        int lineToPrint = rand() % 3 + 1; // gera tres numeros aleatorios sempre que a variavel lineToPrint for executda
        for(int i =0; i < lineToPrint; ++i){
            if (LineIndex < code.size())
            {
                mvprintw(row++,0,"%s", code[LineIndex++].c_str());
                refresh();
                usleep(20000);

                if (row >= LINES)
                {
                    clear();
                    row = 0;
                }
                
            }
            
        }
        
    }
    
}

int main(){
    initscr(); // Inicia o ncurses.h
    noecho(); // Nao mostra tecls
    cbreak(); // Modo direto
    curs_set(0); //Escnde o cursor
    keypad(stdscr, TRUE); // Inicia teclas especiais

    auto code = loadFakeCode("fake_code.txt");

    mvprintw(0,0,"====== Hacker Type ======");
    mvprintw(1,0,"Pressione qualquer tecla para 'Hacker'... (ESC par sair)");
    refresh();
    getch();
    clear();

    typeFakeCode(code);

    endwin(); // Finaliza o ncurses

    return 0;
}