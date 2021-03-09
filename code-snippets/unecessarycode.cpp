  /* if(tmp->internalCount == tmp->datasize){
                
                    if(tmp->prev != NULL && tmp->next !=NULL){//if temp is in the middle

                        tmp->next->prev = tmp->prev;
                        tmp->prev ->next = tmp->next;

                        //cout<<"\n"<<tmp->name<<"done"<<endl;
                        
                        deletetemp = tmp;
                        tmp = tmp->next;
                        delete deletetemp;

                    }else if(tmp->prev != NULL && tmp->next == NULL){//if temp is at the end

                        tmp->prev->next = tmp->next;
                       // cout<<"\n"<<tmp->name<<"done"<<endl;
                        deletetemp = tmp;
                        tmp = tmp->next;
                        delete deletetemp;
    
                    }else if(tmp->prev == NULL && tmp->next != NULL){//if temp is the head and the queue is not empty

                        iohead = tmp->next;
                        iohead->prev = NULL;
                        deletetemp = tmp;
                        //cout<<"\n"<<tmp->name<<"done"<<endl;
                        tmp = tmp->next;
                        delete deletetemp;
                    }else if(tmp->prev == NULL && tmp->next == NULL){

                        iohead = NULL;
                        deletetemp = tmp;
                        tmp=NULL;
                       // cout<<"\n"<<tmp->name<<"done"<<endl;
                        delete deletetemp;
                    }

                
                }else{*/
