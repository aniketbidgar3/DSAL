#include<iostream>
#include<string>
using namespace std;

struct node{
    node* next;
    int vertex;
};

int n;
node *L[20];
int visited[10];
string landmark[10];

class AdjacencyMatrix{


    public:
        int G[10][10];
        int j;

        AdjacencyMatrix(){
            for(int i=0;i<n;i++){
                visited[i]=0;
            }
        }

        void DFS_AM(int i,string str){
            cout<<'\n'<<landmark[i];
            visited[i]=1;

            for(int j=0;j<n;j++){
                if(!visited[j] && G[i][j]==1){
                    DFS_AM(j,landmark[j]);
                }
            }

        }


        void create(){
            int i,j;
            cout<<"\nEnter No of Landmarks : ";
            cin>>n;

            for(int i=0;i<n;i++){
                cout<<"Enter Landmark : ";
                cin>>landmark[i];
            }

            cout<<"\nEnter Adjacency Matrix of Graph : "<<'\n';

            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    cin>>G[i][j];
                }

                //cout<<'\n';
            }
        }





};

class AdjacencyList{
    public:

    void read_graph(){
        int i,vi,vj,edges;
        cout<<"Enter No Of vertices: ";
        cin>>n;

        for(i=0;i<n;i++){
            L[i]=NULL;
            cout<<"Enter No of edges: ";
            cin>>edges;

            for(i=0;i<edges;i++){
                cout<<"\nEnter an edge(u,v): ";
                cin>>vi>>vj;
                insert(vi,vj);
            }


        }


    }

    void insert(int vi, int vj){
        node *p,*q;
        q = new node;
        q->vertex=vj;
        q->next=NULL;

        if(L[vi]==NULL){
            L[vi]=q;
        }

        else{
            p=L[vi];
            while(p->next!=NULL){
                p=p->next;
            }

        p->next=q;

        }



    }

    void DFS_AL(int i){
        node *p;
        cout<<i<<'\n';
        p=L[i];
        visited[i]=1;

        while(p!=NULL){
            i = p->vertex;
            if(!visited[i]){
                DFS_AL(i);
            }

            p = p->next;

        }

    }

};


int main(){
    
    
    
    
    AdjacencyMatrix A;
    int ch;

    while(1){
    
    cout<<"\n\n**********************MENU**********************\n\n1.Create\n2.DFS\n3.Exit\n\n";
    cout<<"Enter Choice : ";
    cin>>ch;

    switch(ch){
        case 1:
            A.create();
            break;

        case 2:
            A.DFS_AM(0,landmark[0]);
            break;

        case 3:
            exit(0);

        default:
            cout<<"Enter valid choice !! "<<'\n';
        }
    }

    return 0;
}









