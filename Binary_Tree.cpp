#include <iostream>

using namespace std;

class bs_node{

    public:

        int data;
        bs_node * right;
        bs_node * left;

        bs_node(int in_data){
            data = in_data;
            right = nullptr;
            left = nullptr;
        }

};

class BST{

    private:
        bs_node * root;
        int nodes;
    
    public:
        BST(){
            nodes = 0;
            root = nullptr;
        }

        

        bool search(bs_node * node, int key){
            if(node->data == key){
                return true;
            }else if(key > node->data){
                if(node->right == nullptr){
                    return false;
                }
                return search(node->right, key);
            }else{
                if(node->left == nullptr){
                    return false;
                }
                return search(node->left, key);
            }
        }


        bool search(int key){
            if(root == nullptr){
                return false;
            }else{
                if(root->data == key){
                    return true;
                }else if(key > root->data){
                    if(root->right == nullptr){
                        return false;
                    }
                    return search(root->right, key);
                }else{
                    if(root->left == nullptr){
                        return false;
                    }
                    return search(root->left, key);
                }
            }
        }

        


};

int main(){

}