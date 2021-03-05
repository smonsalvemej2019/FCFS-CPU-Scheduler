int P1[] = {6, 21, 9, 28,4, 5, 26, 4, 22, 3, 41, 6, 45, 4, 27, 8 , 27, 3};

linked_list wqueue; //initializes a new linked list with only one node and the input data P1
wqueue.create_node(P1);
linked_list io;//the io will get more use on later developement

node * in = wqueue.gethead();//gets head
node * out = io.gethead();
int internalcounter = 0;//iterator
int externalcounter = 0;
int datasize = sizeof(P1)/sizeof(P1[0]);//size of the array


while( in != NULL || out !=NULL ){//driver loop


if(in->data[internalcounter] == 0){//if the data in position n is 0 then n+1

    internalcounter++;//iterator++
    cout<< "\n\n";

}
if(internalcounter == datasize){//if the iterator is equal to array size then break conmditiom

    in = NULL;

}else{//else output data, decrease value of data -1 and add increases the global counbter by 1 

    cout<<in->data[internalcounter]<< "  ";
    in->data[internalcounter]--;
    externalcounter++;

}



}

cout << "\n\n" << externalcounter <<endl; //output of the counter which should be equal to the number of characters in display