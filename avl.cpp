#include<bits/stdc++.h>
using namespace std;

template<typename t>class tree;

template<typename t>class node{
    friend class tree<t>;
    public:
        t data;
        int height;
        node<t> *left;
        node<t> *right;
};

template <typename t>class tree{
  private:  
    node<t> *root;

    int height(node<t> *ptr){
        if(ptr == nullptr) return 0;
        return ptr->height;
    }

    int getbal(node<t>*ptr){
        if(ptr==nullptr) return 0;
        return (height(ptr->left)-height(ptr->right));
    }

    node<t>*right(node<t>*y){
        node<t>*x = y->left;
        node<t>*temp = x->right;
        x->right = y;
        y->left = temp;
        y->height = max(height(y->left),height(y->right))+1;
        x->height = max(height(x->left),height(x->right))+1;
        return x;
    }

    node<t>*left(node<t>*x){
        node<t>*y = x->right;
        node<t>*temp = y->left;
        y->left = x;
        x->right = temp;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
        return y; 
    }

    node<t>* insert(node<t>*ptr,t val){
        if(ptr==nullptr) return new node<t>(val);
        else if(val<ptr->data) ptr->left = insert(ptr->left,val);
        else if(val>ptr->data) ptr->right = insert(ptr->right,val);
        else{
            cout<<"dup"<<endl;
            return ptr;
        }
        ptr->height = max(height(ptr->left),height(ptr->right))+1;
        int balance = getbal(ptr);
        if(balance>1){
            if(val<ptr->left->data) return right(ptr);
            else if(val>ptr->left->data){
                ptr->left = left(ptr->left);
                return right(ptr);
            }
        }
        if(balance<-1){
            if(val>ptr->right->data) return left(ptr);
            else if(val<ptr->right->data){
                ptr->right = right(ptr->right);
                return left(ptr);
            }
        }
        return ptr;
    }
    void inorder(node<t>*ptr){
        if(ptr==nullptr) return ;
        inorder(ptr->left);
        cout << ptr->data <<" ";
        inorder(ptr->right);
    }

    void search(node<t>*ptr,t val){
        int depth{};
        while(ptr!=nullptr){
            depth++;
            if(ptr->data==val){
                cout<<val<<" bound at :"<<depth<<endl;
                return ;
            }
            else if(val>ptr->data) ptr=ptr->right;
            else if(val<ptr->data) ptr=ptr->left;
        }
        cout << "Element is not found"<<endl;
    }

    void print(node<t>*ptr,string ind,bool last){
        if(ptr!=nullptr){
            cout<<ind;
            if(last){
                cout<<"R---";
                ind+="    ";
            }
            else{
                cout<<"L----";
                ind+="     ";
            }
            cout<<ptr->data<<endl;
            print(ptr->left,ind,false);
            print(ptr->right,ind,true);
        }
    }

    node<t>*minnode(node<t>*ptr){
        while(ptr->left!=nullptr) ptr=ptr->left;
        return ptr;
    }

    node<t>*del(node<t>*ptr,t d){
        if(ptr==nullptr) return nullptr;
        else if(d < ptr->data) ptr->left = del(ptr->left,d);
        else if(d > ptr->data) ptr->right = del(ptr->right,d);
        else{
            if(ptr->left==nullptr || ptr->right==nullptr){
                node<t>*temp = (ptr->left)?(ptr->left):(ptr->right);
                if(temp==nullptr){
                    temp = ptr;
                    ptr=nullptr;
                }
                else{
                    *ptr = *temp;
                }
                free(temp);
            }
            else{
                node<t>*temp = minnode(ptr->right);
                ptr->data = temp->data;
                ptr->right = del(ptr->right,temp->data);
            }
        }
        if(ptr==nullptr) return nullptr;
        ptr->height = max(height(ptr->left),height(ptr->right))+1;
        int balance = getbal(ptr);
        if(balance>1){
            if(getbal(ptr->left)>=0) return right(ptr);
            else{
                ptr->left = left(ptr->left);
                return right(ptr);
            }
        }
        if(balance<-1){
            if(getbal(ptr->right)<=0) return left(ptr);
            else{
                ptr->right = right(ptr->right);
                return left(ptr);
            }
        }
        return ptr;
    }
  public:
    tree():root(nullptr){}
    void ins(t d){
        root = insert(root,d);
    }
    void in(){
        inorder(root);
    }
    void se(t d){
        search(root,d);
    }
    void pr(string ind,bool last){
        print(root,ind,last);
    }
    void de(t d){
        root = del(root,d);
    }
};

int main(){
    tree<int> t;
    t.ins(1); 
    t.ins(2);
    t.ins(3);
    t.ins(4);
    t.ins(5);
    t.ins(6);
    t.pr("",true);
    t.se(6);
    t.in();
    t.pr("",true);
    return 0;
}