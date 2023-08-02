#include<bits/stdc++.h>
using namespace std;
class node
{
    int nodeNum, private_x ,cr;
    string name;
    public:
    node(int Num, int c, int p, string n) {
        nodeNum = Num;
        private_x = p;
        cr = c;
        name = n;
    }
    int getNodeNum(){
        return nodeNum;
    }
    void setNodeNum(int Num){
        nodeNum = Num;
    }
    int getPriv(){
        return private_x;
    }
    void setPriv(int p){
        private_x = p;
    }
    int getCr(){
        return cr;
    }
    void setCr(int c){
        cr = c;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    static node setNode(int Num, int c, int p, string n){
        return (node(Num, c,p, n));
    }
};

int showDeps(vector<node> x,int y)
{
        y--;
        string k = " << ";
        if(y == 0) return 0;
        if((x.at(y)).getPriv() == 0) k = "";
        cout << (x.at(y).getName());
        cout << k;
        return (x.at(y).getCr() + showDeps(x,x.at(y).getPriv()));
}

int main()
{
        vector<node> Graph;
        Graph.push_back(node(1,0,0,"CS 101"));
        Graph.push_back(node(2,3,1,"CS 102"));
        Graph.push_back(node(3,0,0,"CS 103"));
        Graph.push_back(node(4,2,1,"CS 201"));
        Graph.push_back(node(4,1,2,"CS 201"));
        Graph.push_back(node(4,4,3,"CS 201"));
        Graph.push_back(node(5,5,4,"CS 501"));
        Graph.push_back(node(6,3,4,"CS 502"));
        Graph.push_back(node(7,6,5,"CS 660"));
        Graph.push_back(node(7,3,6,"CS 660"));

        int x;
        cout << "1. CS 101\n2. CS 102\n3. CS 103\n4. CS 201\n5. CS 501\n6. CS 502\n7. CS 660\n\n";
        cout << "Choose a subject: ";
        cin >> x;
        if(x > 7 || x < 1){
            cout<<"WRONG INPUT";
            return 0;
        }
        int cr = showDeps(Graph,x);
        cout << "\nTotal credit cost: " << cr << "\n";
}
