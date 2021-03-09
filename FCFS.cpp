#include <iostream>
#include <vector>
using namespace std;


//------------------------------Node Structure for a single process--------------------------------------// 
struct node{//structure of the node 

    //---------------------------------process variables------------------------------//

    //data array and supplemental

    int * data;//given data array
    int datasize;//size of the array
    int internalCount;//array iterator
    int totaltime;//addition of the array elements (burst+i/o)
    
    //process information 

    string name;//name of the process(P1-P8)
    int contextSwitch;//number of context switches
    int responsetime ;//time the process started
    int turnaroundtime;//time the process ended

    //--------------------------data structures variables----------------------------//

    struct node * next;
    struct node * prev;
};

//------------------------------linked list class--------------------------------------// 
class linked_list{
    // structure for the link list that will contain the functions for 
    // creation, traversal, and delition. 
    //set the structs for the head and tail 
    public: 

    node *head,*tail;

    linked_list();//constructor

    int nodecntr();//counts the number of nodes in the list

    void create_node(string name, int data[], int datasize);//create node and inserts it at the end
    
    void sethead(node* newhead);//sets a new head 


    void display();//data display method
    void displayAdj(int pos);//displays the values of the, and adjacent to the given position

    node* gethead();//get hed method
    node* gettail();

  
};

//----------------------------methods definition------------------------------------//

linked_list::linked_list(){//set the head of the node to null atuomatically 
    
    head=NULL; 
    tail=NULL; 
}

void linked_list::create_node(string name, int data[], int datasize){//create node function definition

node *tmp = new node;
tmp->name = name;
tmp->datasize = datasize;
tmp->data = data;
tmp->internalCount = 0;
tmp->totaltime = 0;
tmp->contextSwitch = 0;
tmp->responsetime = -1;
tmp->turnaroundtime = -1;
tmp->prev = NULL;
tmp->next = NULL;

if (head == NULL){//creates initial node
    head = tmp;
    tail = tmp;
}else{//adds a node to the tail
    
    tail->next = tmp;
    tmp->prev = tail;
    tail = tmp;
}

cout<<tmp->name<<" created"<<endl;
}

void linked_list::display(){

    int count = 1;
    node* tmp;//creates a temporary node that will traverse the list
    tmp = head;//set the addesss to the head of the list
    if(tmp == NULL){//fail-safe in case the list is empty
        cout<<"\nThe list is empty\n";
        return;
    }

    cout<<endl;

    while(tmp != NULL){//the while loop will traverse the list
        cout<<" "<<tmp->name;//displays the data
        tmp = tmp->next;//moves to the next node
        count++;
    }
}
node * linked_list::gethead(){ 

    return head; 

}

node * linked_list::gettail(){

    node * tmp;
    tmp = gethead();

    if(tmp == NULL){

        return tmp;

    }else if(tmp->next == NULL){

        return tmp;

    }

    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tail = tmp;
    return tail;


}



//-------------------------------------Main Function------------------------------------------------//

int main (){
     //cpu time, I/O time, cpu, I/O, cpu....
    int P1[] = {6, 21, 9, 28, 5, 26, 4, 22, 3, 41, 6, 45, 4, 27, 8 , 27, 3};
    int P2[] = {19, 48, 16, 32, 17, 29, 6, 44, 8, 34, 21, 34, 19, 39, 10, 31, 7};
    int P3[] = {12, 14, 6, 21, 3, 29, 7, 45, 8, 54, 11, 44, 9};
    int P4[] = {11, 45, 5, 41, 6, 45, 8, 51, 4, 61, 13, 54, 11, 61, 10};
    int P5[] = {16, 22, 15, 21, 12, 31, 14, 26, 13, 31, 16, 18, 12, 21, 10, 33, 11};
    int P6[] = {20, 31, 22, 30, 25, 29, 11, 44, 17, 34, 18, 31, 6, 22, 16};
    int P7[] = {3, 44, 7, 24, 6, 34, 5, 54, 4, 24, 7, 44, 6, 54, 5, 21, 6, 43, 4};
    int P8[] = {15, 50, 4, 23, 11, 31, 4, 31, 3, 47, 5, 21, 8, 31, 6, 44, 9};

    linked_list wqueue;//waiting queue 
    linked_list ioqueue;//i/o ququqe
    linked_list results; //results queue
    wqueue.create_node("P1", P1, 17);
    wqueue.create_node("P2", P2, 17);
    wqueue.create_node("P3", P3, 13);
    wqueue.create_node("P4", P4, 15);
    wqueue.create_node("P5", P5, 17);
    wqueue.create_node("P6", P6, 15);
    wqueue.create_node("P7", P7, 19);
    wqueue.create_node("P8", P8, 17);

    node *tmp;
    node *deletetemp;
    node *wqueuetail = wqueue.gettail();
    node *cpu = wqueue.gethead();//we get the head of the wqueue. This will represent our cpu
    node *iohead = ioqueue.gethead();//head of the i/o queue
    node *iotail = ioqueue.gettail();
    node *resulttail = results.gettail();
    
    int externalcounter = 0;//our clock     
    
    while(cpu!=NULL || iohead!=NULL){//
    iotail = ioqueue.gettail();
    wqueuetail = wqueue.gettail();
    

    
    if(cpu != NULL){//process the cpu if not empty

       //cout<<"In cpu: "<<cpu->name<<"\t"<<cpu->data[cpu->internalCount]<<endl;


        if(cpu->responsetime <= -1){cpu->responsetime = externalcounter;}


        if(cpu->data[cpu->internalCount] == 0){

            cpu->internalCount++; 
            cout<<cpu->name<<"  "<<externalcounter<<endl;

            if(cpu->internalCount == cpu->datasize){

                if(cpu->next == NULL){
                    
                    cpu->turnaroundtime = cpu->totaltime;
                   // cout<<cpu->name<<" Deleted"<<endl;

                    if(results.head == NULL){

                    results.head == cpu;

                    }

                    resulttail = cpu;
                    resulttail->next = NULL;
                    resulttail = resulttail->next;
                    deletetemp = cpu;
                    cpu=NULL;
                    delete deletetemp;

                }else{
                
                cpu->turnaroundtime = cpu->totaltime;
               // cout<<cpu->name<<" "<<endl;
                deletetemp = cpu;
                resulttail = cpu;
                cpu = cpu->next;
                resulttail->next = NULL;
                resulttail = resulttail->next;
                if(cpu != NULL){
                cpu->prev = NULL;}
                delete deletetemp;
            
            }
        }else{
            cpu->contextSwitch++;
           // cout<<"\n"<<cpu->name<<endl;
            if(ioqueue.gethead() == NULL){//if the i/o queue is empty

                iohead = cpu;
                iotail = cpu;

                cpu = cpu->next;
                if(cpu!=NULL){
                cpu->prev = NULL;
                }
                iohead->next = NULL; 
                iohead->prev = NULL;

            }else{//if the i/o queue is populated

                iotail->next = cpu;
                cpu = cpu->next;
                if(cpu != NULL){
                cpu->prev = NULL;
                }
                iotail->next->prev = iotail;
                iotail=iotail->next;
                iotail->next = NULL;

            }

           // cout<<"\ncontextswitch"<<endl;

        }

        } 
        if(cpu!= NULL) { 
            cpu->data[cpu->internalCount]--;
            cpu->totaltime++;
        }
        }



    if(iohead != NULL){//process the i/o queue if not empty
        
        ioqueue.head = iohead;
        tmp = iohead;

        while(tmp != NULL){//tmp will go trough the full i/o queue

           // cout<<"In I/O: "<<tmp->name<<"\t"<<tmp->data[tmp->internalCount]<<endl;

            if(tmp->data[tmp->internalCount] == 0){

                tmp->internalCount++;
                //tmp->data;
                //detach node tmp depending of where it is on the list
                    if(tmp->prev != NULL && tmp->next !=NULL){//if temp is in the middle

                        tmp->next->prev = tmp->prev;
                        tmp->prev ->next = tmp->next;

                    }else if(tmp->prev != NULL && tmp->next == NULL){//if temp is at the end

                        tmp->prev->next = tmp->next;

                    }else if(tmp->prev == NULL && tmp->next != NULL){//if temp is the head and the queue is not empty

                        iohead = tmp->next;
                        iohead->prev = NULL;
                    }else if(tmp->prev == NULL && tmp->next == NULL){//if temp is the head and the queue is empty

                        iohead = NULL;
                    }
                    
                    if(wqueue.gethead() == NULL){//if cpu is empty

                        cpu = tmp;
                        wqueuetail = tmp;
                        tmp = tmp->next;
                        cpu->prev = NULL;
                        cpu->next = NULL;


                    }else{//if there is processes in the waiting queue

                        wqueuetail->next = tmp;
                        tmp = tmp->next;
                        wqueuetail->next->prev = wqueuetail;
                        wqueuetail = wqueuetail->next;
                        wqueuetail->next = NULL;

                    }
               // }

            }else{
                tmp->data[tmp->internalCount]--;
                tmp->totaltime++;
                tmp = tmp->next;

            }

        }

    }
    wqueue.head= cpu;
    ioqueue.head = iohead;
    cout<<"\nwqueue: ";
    wqueue.display();
    cout<<endl;
    cout<<"\ni/o: ";
    ioqueue.display();
    cout<<endl;
    cout<<"time: "<<externalcounter<<endl;
    externalcounter++;
    
        
    }

    cout << "\n\n" << externalcounter <<endl;
    results.display();


return 0;
}