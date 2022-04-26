#include <fstream>
#include <iostream>
#include <iomanip>
#include "Graph.h"
struct Color{
    int r;
    int g;
    int b;
   
};
std::ostream &operator<<(std::ostream&stream, const Color &c){
    return stream<<"#" <<std::hex <<std::setw(2)<<std::setfill('0')<< c.r<<std::setw(2)<<std::setfill('0')<<c.g<<std::setw(2)<<std::setfill('0')<<c.b<<std::setw(0)<<std::dec;
}
Color hue(int deg){
    
    deg= (deg+360)%360;
    int V = 255;
    int a = V * (deg%60)/60;
    int Vd = V - a;
    switch((deg/60)%6){
        case 0:
            return Color{V,a,0};
        case 1:
            return Color{Vd,V,0};
        case 2:
            return Color{0,V,a};
        case 3:
            return Color{0,Vd,V};
        case 4:
            return Color{a,0,V};
        case 5:
            return Color{V,0,Vd};
        default:
            return Color{0,0,0};
    }
}
Graph::Graph(int n){
    edges.resize(n,std::vector<int>(n,-1));
}
void Graph::AddEdge(int a,int b,int w){
    edges[a][b] = w;
}
void Graph::IllustratePath(std::string s){
    std::fstream file (s,std::ios_base::out);
    file<<"window.prog=`\n";
    for(int i=0;i<edges.size();i++){
        file<<i<<std::endl;
    }
    file<<"draw\n";
    for(int i=0;i<edges.size();i++){
        for(int j=0;j<edges[i].size();j++){
            if(i!=j&& edges[i][j]!=-1){
                file<<i<<"->"<<j;
                if(edges[i][j] != 1)
                    file <<",label="<<edges[i][j];
                file << std::endl;
            }
        }
    }
    file << "pause" <<std::endl;
    Kosaraju(file);

    file << "pause" <<std::endl;
    file <<"`"<<std::endl;
}
void Graph::dfs1(std::fstream &file,int v){
    visited[v] = true;
    file << v << ",color=yellow"<<std::endl;
    file << "w,500"<<std::endl;
    for(int i = 0;i<edges[v].size();i++){
        if(edges[v][i] != -1 && !visited[i])
            dfs1(file,i);
    }
    file << v << ",color=red,label="<<v<<";order["<<order.size()<<"]"<<std::endl;
    file << "w,1000"<<std::endl;
    order.push_back(v);
}
void Graph::dfs2(std::fstream &file,int v){
    visited[v] = true;
    components.back().push_back(v);
    file << v << ",color="<<hue(360*components.size()/edges.size())<<std::endl;
    file << "w,1000"<<std::endl;
    for(int i = 0;i<edges.size();i++){
        if(edges[i][v] != -1 && !visited[i]){
            dfs2(file,i);
        }
    }

}
void Graph::Kosaraju(std::fstream& file){
    visited.resize(edges.size(),false);
    for(int i=0;i<edges.size();i++){
        if(!visited[i]){
            dfs1(file,i);
        }
    }
    visited.assign(visited.size(),false);
    for(int i = order.size()-1;i>=0;i--){

        int v = order[i];
        if(!visited[v]){
            components.push_back(std::vector<int>());
            dfs2(file,v);
        }

    }
}