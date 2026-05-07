//KELVIN KAUE CARDOSO PEREIRA
//GABRIEL SANTANA MORAES

#include <iostream>
#include <stdlib.h>

using namespace std;

//FUNCOES
void DesenharTabuleiro ();

//FUNCOES PECAS BRANCAS
void peaoBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void reiBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void cavaloBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void TorreBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void BispoBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void RainhaBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);

//FUNCOES PECAS PRETAS
void peaoPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void reiPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void cavaloPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void TorrePreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void BispoPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void RainhaPreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);

//FUNCOES PARA DIFERENCIAR AS PECAS
void PecaPreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);
void escolherPeca(int& LinhaOri, int& ColunaOri, int& LinhaDes, int& ColunaDes);
void PecaBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes);

//TABULEIRO
char board[9][9] = { {' ','0', '1', '2', '3', '4', '5', '6', '7'},

                     {' ','T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'},

                     {' ','P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},

                     {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                     {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                     {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                     {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                     {' ','p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},

                     {' ','t', 'c', 'b', 'd', 'r', 'b', 'c', 't'}};
                     
                     
int main (){
    
                     
    int i = 0;
    do {
    int LinhaOri, ColunaOri, LinhaDes, ColunaDes;

    DesenharTabuleiro ();
    PecaBranca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
    
    PecaPreta( LinhaOri,  ColunaOri,  LinhaDes,  ColunaDes);

} while (i < 30);
  return 0;
  
}

//escolher a peça que vai mover
void escolherPeca(int& LinhaOri, int& ColunaOri, int& LinhaDes, int& ColunaDes){
cout << "Escolha as coordenadas de linha e coluna de origem da peça:";
    cin >> LinhaOri;
    cin >> ColunaOri;

cout << "Escolha as coordenadas de linha e coluna do destino da peça:";
    cin >> LinhaDes; 
    cin >> ColunaDes;
}

//lista de peças brancas com switch case
void PecaBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
  char pecaBranca;
  cout<<"Escolha a peca branca"<<endl;
    cin>>pecaBranca;
  
  switch(pecaBranca){
      case 'p':     
      peaoBranco(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;
      
      case 'r':     
      reiBranco(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;
      
      case 'c':     
      cavaloBranco(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;
      
      case 't':     
      TorreBranca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;
      
      case 'b':     
      BispoPreto(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;
      
      case 'd':
      RainhaBranca( LinhaOri,  ColunaOri,  LinhaDes,  ColunaDes);
      break;
      
      default:
      cout<<"nao tem essa peca"<<endl;
  }
  DesenharTabuleiro();
}

//lista de peças pretas com switch case
void PecaPreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
  char pecaPreta;
  cout<<"Escolha a peca preta"<<endl;
    cin>>pecaPreta;
  
switch(pecaPreta){
      
      case 'P':
      peaoPreto( LinhaOri,  ColunaOri,  LinhaDes,  ColunaDes);
      break;
      
      case 'R':
      reiPreto(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;

      case 'C':
      cavaloPreto(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;

      case 'T':
      TorrePreta(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;

      case 'B':
      BispoPreto(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      break;

      case 'D':
      RainhaPreta( LinhaOri,  ColunaOri,  LinhaDes,  ColunaDes);
      break;
      
      default:
      cout<<"nao tem essa peca"<<endl;
  }
  DesenharTabuleiro();
}


// Imprime o tabuleiro com as peças
void DesenharTabuleiro() {
    system("clear");

    cout << "  1 2 3 4 5 6 7 8" << endl;
    for (int i = 1; i <= 8; i++) {
        cout << i << " ";
        for (int j = 1; j <= 8; j++) {
            if ((i + j) % 2 == 0) {
                cout << "\033[47m"; // fundo branco
            } else {
                cout << "\033[40m"; // fundo preto
            }
            if (board[i][j] == '.') {
                cout << "  "; // espaço vazio
            } else {
                cout << board[i][j] << " "; // peça
            }
            cout << "\033[0m"; // reset
        }
        cout << i << endl;
    }
    cout << "  1 2 3 4 5 6 7 8" << endl;
}
//função do movimento do peao branco
void peaoBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
     
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      
    if (board[LinhaOri][ColunaOri] != 'p') {
        cout << "Movimento invalido. A posição de origem não contem um peao branco." << endl;
        return;
    }
    
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }
    //andar uma casa
    if(ColunaOri == ColunaDes && LinhaDes == LinhaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'p';
    }
    
    //andar duas casas
    if(LinhaOri == 7 && ColunaOri == ColunaDes && LinhaDes == LinhaOri-2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'p';

    }

    else
        cout << "Movimento invalido. O peão só pode andar 2 casas se estiver na linha 7." << endl;
    DesenharTabuleiro ();
}


//movimento rei branco
void reiBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
    
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    if (board[LinhaOri][ColunaOri] != 'r') {
        cout << "Movimento invalido. A posição de origem não contem um rei branco." << endl;
        return;
    }
    
     if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }
    //movimento para diagonal esquerda cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }
    
    //movimento para diagonal esquerda baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }
    
    //movimento para cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }
    
    //movimento para baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }

    //movimento para diagonal direita baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }
    
    //movimento para diagonal direita cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'r';
    }
    DesenharTabuleiro ();
}

//movimento cavalo branco
void cavaloBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
    
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    if (board[LinhaOri][ColunaOri] != 'c') {
        cout << "Movimento invalido. A posição de origem não contem um cavalo branco." << endl;
        return;
    }
    
     if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }
    //movimento em L para a esquerda cima
    if(LinhaDes == LinhaOri-2 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    //movimento em L para a direita cima
    if(LinhaDes == LinhaOri-2 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    //movimento em L para esquerda
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri+2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    //movimento em L para a direita
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri+2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    //movimento em L para baixo esquerda
    if(LinhaDes == LinhaOri+2 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    //movimento em L para baixo esquerda
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri-2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri-2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'c';
    }
        DesenharTabuleiro ();
}

//movimento Torre branca
void TorreBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
   escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    // Verifica se a posição de origem contém uma torre branca
    if (board[LinhaOri][ColunaOri] != 't') {
        cout << "Movimento invalido. A posição de origem não contém uma torre branca." << endl;
        return;
    }
    
    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para uma torre
    if (LinhaDes != LinhaOri && ColunaDes != ColunaOri) {
        cout << "Movimento invalido. A torre move apenas na horizontal ou vertical." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho da torre
    int i, j;
    if (LinhaDes == LinhaOri) {
        // Movimento na horizontal
        if (ColunaDes < ColunaOri) {
            // Movimento para a esquerda
            for (j = ColunaOri - 1; j > ColunaDes; j--) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento para a direita
            for (j = ColunaOri + 1; j < ColunaDes; j++) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    } else {
        // Movimento na vertical
        if (LinhaDes < LinhaOri) {
            // Movimento para cima
            for (i = LinhaOri - 1; i > LinhaDes; i--) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento para baixo
            for (i = LinhaOri + 1; i < LinhaDes; i++) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    }
    
    board[LinhaOri][ColunaOri] = ' ';
    board[LinhaDes][ColunaDes] = 't';
        DesenharTabuleiro ();
}
//movimento bispo branco
void BispoBranco(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
    cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    // Verifica se a posição de origem contém um bispo branco
    if (board[LinhaOri][ColunaOri] != 'b') {
        cout << "Movimento invalido. A posição de origem não contém um bispo branco." << endl;
        return;
    }

    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para um bispo
    if (abs(LinhaDes - LinhaOri) != abs(ColunaDes - ColunaOri)) {
        cout << "Movimento invalido. O bispo move apenas na diagonal." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho do bispo
    int i, j;
    if (LinhaDes > LinhaOri && ColunaDes > ColunaOri) {
        // Movimento para a direita e para baixo
        for (i = LinhaOri + 1, j = ColunaOri + 1; i < LinhaDes && j < ColunaDes; i++, j++) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
        }
    } else if (LinhaDes > LinhaOri && ColunaDes < ColunaOri) {
        // Movimento para a esquerda e para baixo
        for (i = LinhaOri + 1, j = ColunaOri - 1; i < LinhaDes && j > ColunaDes; i++, j--) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
        }
    } else if (LinhaDes < LinhaOri && ColunaDes > ColunaOri) {
        // Movimento para a direita e para cima
        for (i = LinhaOri - 1, j = ColunaOri + 1; i > LinhaDes && j < ColunaDes; i--, j++) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
    else if (LinhaDes < LinhaOri && ColunaDes < ColunaOri) {
// Movimento para a esquerda e para cima
    for (i = LinhaOri - 1, j = ColunaOri - 1; i > LinhaDes && j > ColunaDes; i--, j--) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
    else if (LinhaDes > LinhaOri && ColunaDes < ColunaOri) {
// Movimento para a esquerda e para baixo
    for (i = LinhaOri + 1, j = ColunaOri - 1; i < LinhaDes && j > ColunaDes; i++, j--) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
    else if (LinhaDes > LinhaOri && ColunaDes > ColunaOri) {
// Movimento para a direita e para baixo
    for (i = LinhaOri + 1, j = ColunaOri + 1; i < LinhaDes && j < ColunaDes; i++, j++) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
}
board[LinhaOri][ColunaOri] = ' ';
board[LinhaDes][ColunaDes] = 'b';
}
//movimento rainha branca
void RainhaBranca(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
   escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    // Verifica se a posição de origem contém uma rainha
    if (board[LinhaOri][ColunaOri] != 'd') {
        cout << "Movimento invalido. A posição de origem não contém uma rainha." << endl;
        return;
    }
    
    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para uma rainha
    if (LinhaDes != LinhaOri && ColunaDes != ColunaOri && abs(LinhaDes-LinhaOri) != abs(ColunaDes-ColunaOri)) {
        cout << "Movimento invalido. A rainha move apenas na diagonal, horizontal ou vertical." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho da rainha
    int i, j, linhaDir, colunaDir;
    if (LinhaDes == LinhaOri || ColunaDes == ColunaOri) {
        // Movimento na horizontal ou vertical
        if (LinhaDes == LinhaOri) {
            // Movimento na horizontal
            colunaDir = (ColunaDes < ColunaOri) ? -1 : 1;
            for (j = ColunaOri + colunaDir; j != ColunaDes; j += colunaDir) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento na vertical
            linhaDir = (LinhaDes < LinhaOri) ? -1 : 1;
            for (i = LinhaOri + linhaDir; i != LinhaDes; i += linhaDir) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    } else {
        // Movimento na diagonal
        linhaDir = (LinhaDes < LinhaOri) ? -1 : 1;
        colunaDir = (ColunaDes < ColunaOri) ? -1 : 1;
        i = LinhaOri + linhaDir;
        j = ColunaOri + colunaDir;
        while (i != LinhaDes && j != ColunaDes) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
            i += linhaDir;
            j += colunaDir;
        }
    }
    
    board[LinhaOri][ColunaOri] = ' ';
    board[LinhaDes][ColunaDes] = 'd';



DesenharTabuleiro ();
}
//movimento peao preto
void peaoPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
     
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);
      
    if (board[LinhaOri][ColunaOri] != 'P') {
        cout << "Movimento invalido. A posição de origem não contem um peao branco." << endl;
        return;
    }
    
     if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }
    //andar uma casas
    if(ColunaOri == ColunaDes && LinhaDes == LinhaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'P';
    }
    
    //andar duas casas
    if(LinhaOri == 2 && ColunaOri == ColunaDes && LinhaDes == LinhaOri+2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'P';

    }

    else
        cout << "Movimento invalido. O peão só pode andar 2 casas se estiver na linha 7." << endl;
    DesenharTabuleiro ();
}

//movimento rei preto
void reiPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){

    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;


    if (board[LinhaOri][ColunaOri] != 'R') {
        cout << "Movimento invalido. A posição de origem não contem um rei preto." << endl;
        return;
    }

     if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }
    //movimento para diagonal esquerda cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }

    //movimento para diagonal esquerda baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }

    //movimento para cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }

    //movimento para baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }

    //movimento para diagonal direita baixo
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }

    //movimento para diagonal direita cima
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'R';
    }
    DesenharTabuleiro ();
}

//movimento cavalo preto 
void cavaloPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){

    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;


    if (board[LinhaOri][ColunaOri] != 'C') {
        cout << "Movimento invalido. A posição de origem não contem um cavalo preto." << endl;
        return;
    }

     if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    if(LinhaDes == LinhaOri-2 && ColunaDes == ColunaOri-1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri-2 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri+2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri+2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri+2 && ColunaDes == ColunaOri+1){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri+1 && ColunaDes == ColunaOri-2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
    if(LinhaDes == LinhaOri-1 && ColunaDes == ColunaOri-2){
        board[LinhaOri][ColunaOri] = ' ';
        board[LinhaDes][ColunaDes] = 'C';
    }
        DesenharTabuleiro ();
}

//movimento Torre preta 
void TorrePreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
   escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    // Verifica se a posição de origem contém uma torre branca
    if (board[LinhaOri][ColunaOri] != 'T') {
        cout << "Movimento invalido. A posição de origem não contém uma torre preto." << endl;
        return;
    }
    
    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para uma torre
    if (LinhaDes != LinhaOri && ColunaDes != ColunaOri) {
        cout << "Movimento invalido. A torre move apenas na horizontal ou vertical." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho da torre
    int i, j;
    if (LinhaDes == LinhaOri) {
        // Movimento na horizontal
        if (ColunaDes < ColunaOri) {
            // Movimento para a esquerda
            for (j = ColunaOri - 1; j > ColunaDes; j--) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento para a direita
            for (j = ColunaOri + 1; j < ColunaDes; j++) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    } else {
        // Movimento na vertical
        if (LinhaDes < LinhaOri) {
            // Movimento para cima
            for (i = LinhaOri - 1; i > LinhaDes; i--) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento para baixo
            for (i = LinhaOri + 1; i < LinhaDes; i++) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    }
    
    board[LinhaOri][ColunaOri] = ' ';
    board[LinhaDes][ColunaDes] = 'T';
        DesenharTabuleiro ();
}
//movimento bispo preto
void BispoPreto(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
    escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
    cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    // Verifica se a posição de origem contém um bispo branco
    if (board[LinhaOri][ColunaOri] != 'B') {
        cout << "Movimento invalido. A posição de origem não contém um bispo preto." << endl;
        return;
    }

    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para um bispo
    if (abs(LinhaDes - LinhaOri) != abs(ColunaDes - ColunaOri)) {
        cout << "Movimento invalido. O bispo move apenas na diagonal." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho do bispo
    int i, j;
    if (LinhaDes > LinhaOri && ColunaDes > ColunaOri) {
        // Movimento para a direita e para baixo
        for (i = LinhaOri + 1, j = ColunaOri + 1; i < LinhaDes && j < ColunaDes; i++, j++) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
        }
    } else if (LinhaDes > LinhaOri && ColunaDes < ColunaOri) {
        // Movimento para a esquerda e para baixo
        for (i = LinhaOri + 1, j = ColunaOri - 1; i < LinhaDes && j > ColunaDes; i++, j--) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
        }
    } else if (LinhaDes < LinhaOri && ColunaDes > ColunaOri) {
        // Movimento para a direita e para cima
        for (i = LinhaOri - 1, j = ColunaOri + 1; i > LinhaDes && j < ColunaDes; i--, j++) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
else if (LinhaDes < LinhaOri && ColunaDes < ColunaOri) {
// Movimento para a esquerda e para cima
    for (i = LinhaOri - 1, j = ColunaOri - 1; i > LinhaDes && j > ColunaDes; i--, j--) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
    else if (LinhaDes > LinhaOri && ColunaDes < ColunaOri) {
// Movimento para a esquerda e para baixo
    for (i = LinhaOri + 1, j = ColunaOri - 1; i < LinhaDes && j > ColunaDes; i++, j--) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
} 
    else if (LinhaDes > LinhaOri && ColunaDes > ColunaOri) {
// Movimento para a direita e para baixo
    for (i = LinhaOri + 1, j = ColunaOri + 1; i < LinhaDes && j < ColunaDes; i++, j++) {
    if (board[i][j] != ' ') {
        cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
return;
        }
    }
}
board[LinhaOri][ColunaOri] = ' ';
board[LinhaDes][ColunaDes] = 'B';
}
//movimento rainha preta
void RainhaPreta(int LinhaOri, int ColunaOri, int LinhaDes, int ColunaDes){
   escolherPeca(LinhaOri, ColunaOri, LinhaDes, ColunaDes);

    cout <<"origem"<<LinhaOri<<ColunaOri<<endl;
        cout <<"destino"<<LinhaDes<<ColunaDes<<endl;

    
    // Verifica se a posição de origem contém uma rainha
    if (board[LinhaOri][ColunaOri] != 'D') {
        cout << "Movimento invalido. A posição de origem não contém uma rainha." << endl;
        return;
    }
    
    // Verifica se a posição de destino está vazia
    if (board[LinhaDes][ColunaDes] != ' ') {
        cout << "Movimento invalido. A posicao de destino nao esta vazia." << endl;
        return;
    }

    // Verifica se o movimento é válido para uma rainha
    if (LinhaDes != LinhaOri && ColunaDes != ColunaOri && abs(LinhaDes-LinhaOri) != abs(ColunaDes-ColunaOri)) {
        cout << "Movimento invalido. A rainha move apenas na diagonal, horizontal ou vertical." << endl;
        return;
    }

    // Verifica se há peças obstruindo o caminho da rainha
    int i, j, linhaDir, colunaDir;
    if (LinhaDes == LinhaOri || ColunaDes == ColunaOri) {
        // Movimento na horizontal ou vertical
        if (LinhaDes == LinhaOri) {
            // Movimento na horizontal
            colunaDir = (ColunaDes < ColunaOri) ? -1 : 1;
            for (j = ColunaOri + colunaDir; j != ColunaDes; j += colunaDir) {
                if (board[LinhaOri][j] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        } else {
            // Movimento na vertical
            linhaDir = (LinhaDes < LinhaOri) ? -1 : 1;
            for (i = LinhaOri + linhaDir; i != LinhaDes; i += linhaDir) {
                if (board[i][ColunaOri] != ' ') {
                    cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                    return;
                }
            }
        }
    } else {
        // Movimento na diagonal
        linhaDir = (LinhaDes < LinhaOri) ? -1 : 1;
        colunaDir = (ColunaDes < ColunaOri) ? -1 : 1;
        i = LinhaOri + linhaDir;
        j = ColunaOri + colunaDir;
        while (i != LinhaDes && j != ColunaDes) {
            if (board[i][j] != ' ') {
                cout << "Movimento invalido. Ha uma peca obstruindo o caminho." << endl;
                return;
            }
            i += linhaDir;
            j += colunaDir;
        }
    }
    
    board[LinhaOri][ColunaOri] = ' ';
    board[LinhaDes][ColunaDes] = 'D';
}
