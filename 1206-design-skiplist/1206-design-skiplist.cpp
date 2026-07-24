struct Node{
    int val;
    vector<Node*> forward;

    Node(int value,int level){
        val=value;
        forward=vector<Node*>(level+1,nullptr);
    }

};

class Skiplist {
public:
    static const int MAX_LEVEL=16;
    Node* head;
    int level;

    Skiplist(){
        level=0;
        head=new Node(-1,MAX_LEVEL);
    }

    int randomLevel(){
        int lvl=0;
        while((rand()&1)&&lvl<MAX_LEVEL){
            lvl++;
        }
        return lvl;
    }
    
    bool search(int target) {
        Node* curr=head;
        for(int i=level;i>=0;i--){
            while(curr->forward[i]&&curr->forward[i]->val<target){
                curr=curr->forward[i];
            }
        }
        curr=curr->forward[0];
        return (curr&&curr->val==target);
    }
    
    void add(int num) {
        vector<Node*> update(MAX_LEVEL+1);
        Node* curr=head;
        for(int i=level;i>=0;i--){
            while(curr->forward[i]&&curr->forward[i]->val<num){
                curr=curr->forward[i];
            }
            update[i]=curr;
        }

        int newLevel=randomLevel();
        if(newLevel>level){
            for(int i=level+1;i<=newLevel;i++){
                update[i]=head;
            }
            level=newLevel;
        }
        Node* newNode=new Node(num,newLevel);
        for(int i=0;i<=newLevel;i++){
            newNode->forward[i]=update[i]->forward[i];
            update[i]->forward[i]=newNode;
        }
    }
    
    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL+1);
        Node* curr=head;
        for(int i=level;i>=0;i--){
            while(curr->forward[i]&&curr->forward[i]->val<num){
                curr=curr->forward[i];
            }
            update[i]=curr;
        }

        curr=curr->forward[0];
        if(!curr||curr->val!=num){
            return false;
        }
        for(int i=0;i<=level;i++){
            if(update[i]->forward[i]!=curr) break;
            update[i]->forward[i]=curr->forward[i];
        }

        delete curr;
        while(level>0&&head->forward[level]==nullptr){
            level--;
        }

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */