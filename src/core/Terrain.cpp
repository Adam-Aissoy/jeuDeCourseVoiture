#include "Terrain.h"
#include <cassert>

const char m_terrain1[15][21] = {
 "####################",
 "#..................#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#........##........#",
 "#..................#",
 "####################"
};

const char m_terrain2[15][21] = {
 "####################",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "#..................#",
 "####################"
};



const char m_terrain3[17][23] = {
	"GGGGGBBBBBBBBBBGGGGGGG", //16
	"GGGGH..........IGGGGGG", //15
	"GGBH............DGGGGG", //14
	"GH..............DGGGGG", //13
	"C.........EAF...DGGGGG", //12
	"C.........DGC....BBBBG", //11	
	"C......AAAGGC........D", //10
	"GF......DGGGGA.......D", //9
	"GGBBB...DGGGGGAAAF...D", //8
	"GH.....EGBBBBBBBGC...D", //7
	"C.....EGH.......BH...D", //6
	"C...EAGH.............D", //5
	"C..DBBH..............D", //4
	"C...@.......EF.......D", //3.5
	"C...@......EGC.......D", //3
	"C...@.....EGGGAAAAAAAG", //2
	"GAAAAAAAAAGGGGGGGGGGGG" //1
};

/* test push */
Terrain::Terrain () {
	
	//test terrain 3 
	m_dimx = 22;
	m_dimy = 17;
	
	//m_dimx = 20;
	//m_dimy = 15;
	for(int x=0;x<m_dimx;++x)
		for(int y=0;y<m_dimy;++y)
		{
			switch(m_terrain3[m_dimy-1-y][x])
			//switch(m_terrain1[m_dimy-1-y][x])
			{
				case '#': m_ter[x][y] = WALL; break;
				case '.': m_ter[x][y] = DOT; break;
				case ' ': m_ter[x][y] = SPACE; break;
				case '0': m_ter[x][y] = ROUE; break;
				case 'G': m_ter[x][y] = GRASS; break;

				case 'A': m_ter[x][y] = HAUT; break;
				case 'B': m_ter[x][y] = BAS; break;
				case 'C': m_ter[x][y] = GAUCHE; break;
				case 'D': m_ter[x][y] = DROITE; break;

				case 'E': m_ter[x][y] = DIAGHD; break;
				case 'F': m_ter[x][y] = DIAGHG; break;
				case 'I': m_ter[x][y] = DIAGBD; break;
				case 'H': m_ter[x][y] = DIAGBG; break;
				case '@': m_ter[x][y] = DAMIER; break;
			}
			// m_ter[x][y] = m_terrain1[m_dimy-1-y][x];
		}
}

bool Terrain::estPositionPersoValide (const int x, const int y) const {
	return ((x>=0) && (x<m_dimx) && (y>=0) && (y<m_dimy) && (m_ter[x][y] == '.'  || m_ter[x][y] == '@'));
}

// (m_ter[x][y]!='#'&& m_ter[x][y]!='0' && m_ter[x][y]!='G' && m_ter[x][y]!='A' && m_ter[x][y]!='B' 
	//&& m_ter[x][y]!='C' && m_ter[x][y]!='D' && m_ter[x][y]!='E'&& m_ter[x][y]!='F'&& m_ter[x][y]!='I'&& m_ter[x][y]!='H')
void Terrain::mangePastille (const int x, const int y) {
	assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	//m_ter[x][y]=SPACE;
}
/*
int Terrain::grille(){
	for(int x=0;x<m_dimx;++x)
        for(int y=0;y<m_dimy;++y)
            if(m_ter[x][y]==' ')
                return x;
    return -1;
}

*/
int Terrain::grille(const int x, const int y) const {
	assert(x>=0);
    assert(y>=0);
    assert(x<m_dimx);
    assert(y<m_dimy);
    return m_ter[x][y];
}