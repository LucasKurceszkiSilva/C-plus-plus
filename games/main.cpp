#include <iostream>
#include <vector>
#include <string>

#include <cstdlib>
#include <ctime>

#include <windows.h>

int hits = 0;

class Ball{
    private:
        float velx, vely, posx, posy;
        std::vector<float> valoresx = { -1.0f, -.8f, .8f, 1.0f };
        int idx = rand() % valoresx.size();
        std::vector<float> valoresy = { -.4f, -0.1f, 0.0f, 0.1f, .4f };
        int idy = rand() % valoresx.size();
    public:
    void setup(std::vector<std::vector<char>>& mat){
        velx=valoresx[idx];
        vely=valoresy[idy];
        posx=(rand() % 24)+20;
        posy=(rand() % 11)+2;

        mat[posy][posx]='o';
    }
    void move(std::vector<std::vector<char>>& mat, int w, int h){
        mat[(int)posy][(int)posx] = ' ';
        float nextx = posx + velx;
        float nexty = posy + vely;
        if (mat[(int)posy][(int)nextx] == '|' || mat[(int)posy][(int)nextx] == 'I') {
            velx = -velx;
            hits++;
            idy = rand() % valoresx.size();
            vely=valoresy[idy];
            if(velx>0){
                posx++;
            }else{
                posx--;
            }
            Beep(800, 100);
        } else {
            posx = nextx;
        }
        if (nexty < 1 || nexty > h - 1) {
            vely = -vely;
            Beep(800, 100);
        } else {
            posy = nexty;
        }
        mat[(int)posy][(int)posx] = 'o';
    }
};

class Player{
    private:
        char x, y;
        int posy=8, posx;
    public:
        void setup(char a, char b, int c, std::vector<std::vector<char>>& mat){
            x=a;
            y=b;
            posx=c;
            mat[posy-1][posx]='|';
            mat[posy][posx]='|';
            mat[posy+1][posx]='|';
        }
        void move(std::vector<std::vector<char>>& mat, int h){
            if(posy>2 && GetAsyncKeyState(x) & 0x8000){
                mat[posy+1][posx]=' ';
                posy--;
                mat[posy-1][posx]='|';
            }else if(posy<h-3 && GetAsyncKeyState(y) & 0x8000){
                mat[posy-1][posx]=' ';
                posy++;
                mat[posy+1][posx]='|';
            }else{
                mat[posy-1][posx]='|';
                mat[posy][posx]='|';
                mat[posy+1][posx]='|';
            }
        }
};

void matrixsetup(std::vector<std::vector<char>>& mat, int w, int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            mat[i][j] = ' ';
        }
    }
    for(int i=0;i<w;i++){
        mat[0][i]='-';
        mat[h-1][i]='-';
    }
    for(int j=0;j<h;j++){
        mat[j][0]='I';
        mat[j][w-1]='I';
    }
    mat[0][0]='0';
    mat[0][w-1]='0';
    mat[h-1][0]='0';
    mat[h-1][w-1]='0';
}

void matrixrender(std::vector<std::vector<char>>& mat, int w, int h){
    std::string show;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            show+=mat[i][j];
        }
        show+='\n';
    }
    std::cout << show;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    bool loop=true;
    int w = 90, h = 17;
    Ball bola;
    Player p1;
    Player p2;

    std::vector<std::vector<char>> mat(h, std::vector<char>(w));

    matrixsetup(mat, w, h);
    std::srand(std::time(nullptr));
    bola.setup(mat);
    p1.setup('W', 'S', 4, mat);
    p2.setup('O', 'L', w-5, mat);
    
    while(loop){
        p1.move(mat, h);
        p2.move(mat, h);
        bola.move(mat, w, h);
        system("cls");
        matrixrender(mat, w, h);
        Sleep(40);

    }
    return 0;
}