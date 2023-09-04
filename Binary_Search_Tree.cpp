#include <iostream>
#include <queue>

using namespace std;

class bs_node{

    public:

        int data;
        bs_node * right;
        bs_node * left;
        bs_node * parent;

        bs_node(int in_data){
            data = in_data;
            right = nullptr;
            left = nullptr;
            parent = nullptr;
        }

};

class BST{

    public:

        bs_node * root;
        int nodes; 

        BST(){
            nodes = 0;
            root = nullptr;
        }

        bs_node * search(bs_node * node, int key){
            if(node->data == key){
                return node;
            }else if(key > node->data){
                if(node->right == nullptr){
                    return nullptr;
                }
                return search(node->right, key);
            }else{
                if(node->left == nullptr){
                    return nullptr;
                }
                return search(node->left, key);
            }
        }

        bs_node * minimum(bs_node * node){
            
            while(node->left != nullptr){
                node = node->left;
            }
            return node;
            
        }

        bs_node * maximum(bs_node * node){
            
            while(node->right != nullptr){
                node = node->right;
            }
            return node;
            
        }

        bs_node * successor(int key){
            if(search(root, key) == nullptr){
                return nullptr;
            }else{
                bs_node * the_node = search(root, key);
                if(the_node->right != nullptr){
                    return minimum(the_node->right);
                }else{
                    while((the_node->parent)->right == the_node){
                        the_node = the_node->parent;
                    }
                    return the_node->parent;
                }
            }
        }

        bs_node * predecessor(int key){
            if(search(root, key) == nullptr){
                return nullptr;
            }else{
                bs_node * the_node = search(root, key);
                if(the_node->left != nullptr){
                    return maximum(the_node->right);
                }else{
                    while((the_node->parent)->left == the_node){
                        the_node = the_node->parent;
                    }
                    return the_node->parent;
                }
            }
        }

        void insert(int data){
            if(nodes == 0){
                root = new bs_node(data);
                nodes++;
            }else{
                if(search(root, data) != nullptr){
                    return;
                }else{
                    bs_node * temp = root;
                    bs_node * newnode = new bs_node(data);
                    while(true){
                        if(data > temp->data){
                            if(temp->right != nullptr){
                                temp = temp->right;
                            }else{
                                temp->right = newnode;
                                newnode->parent = temp;
                                nodes++;
                                break;
                            }
                        }else if(data < temp->data){
                            if(temp->left != nullptr){
                                temp = temp->left;
                            }else{
                                temp->left = newnode;
                                newnode->parent = temp;
                                nodes++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        void delete_node(int data){
            if(search(root, data) == nullptr){
                return;
            }else{
                bs_node * the_node = search(root, data);
                if(the_node->right == nullptr && the_node->left == nullptr){
                    if(nodes == 1){
                        nodes--;
                        delete root;
                    }else{

                        if((the_node->parent)->data > the_node->data){
                            (the_node->parent)->left = nullptr;
                            delete the_node;
                            nodes--;
                        }else if((the_node->parent)->data < the_node->data){
                            (the_node->parent)->right = nullptr;
                            delete the_node;
                            nodes--;
                        }
                    }
                }else if(the_node->right != nullptr && the_node->left == nullptr){
                    if((the_node->parent)->right == the_node){

                        ((the_node)->parent)->right = the_node->right;
                        (the_node->right)->parent = the_node->parent;
                        delete the_node;
                        nodes--;

                    }else{

                        ((the_node)->parent)->left = the_node->right;
                        (the_node->right)->parent = the_node->parent;
                        delete the_node;
                        nodes--; 

                    }
                }else if(the_node->left != nullptr && the_node->right == nullptr){

                    if((the_node->parent)->right == the_node){
                        ((the_node)->parent)->right = the_node->left;
                        (the_node->right)->parent = the_node->parent;
                        delete the_node;
                        nodes--;

                    }else{

                        ((the_node)->parent)->left = the_node->left;
                        (the_node->right)->parent = the_node->parent;
                        delete the_node;
                        nodes--;  

                    }
                }else{
                    bs_node * valnode = maximum(the_node->left);
                    int d = valnode->data;
                    delete_node(d);
                    the_node->data = d;
                }
            }
        }

        void pre_order_traversal(bs_node * node, vector<int> * vec){
            if(node != nullptr){
                (*vec).push_back(node->data);
                pre_order_traversal(node->left, vec);
                pre_order_traversal(node->right, vec);
            }

        }

        void in_order_traversal(bs_node * node, vector<int> * vec){
            if(node != nullptr){
                in_order_traversal(node->left, vec);
                (*vec).push_back(node->data);
                in_order_traversal(node->right, vec);
            }
        }

        void post_order_traversal(bs_node * node, vector<int> * vec){
            if(node != nullptr){
                post_order_traversal(node->left, vec);
                post_order_traversal(node->right, vec);
                (*vec).push_back(node->data);
            }
        }

        void level_order_traversal(bs_node * node, vector<int> * vec, queue<bs_node *> * q){
            if(node != nullptr){
                (*vec).push_back(node->data);
                (*q).push(node->left);
                (*q).push(node->right);
                bs_node * newnode = (*q).front();
                (*q).pop();
                level_order_traversal(newnode, vec, q);
            }
        }

};

int main(){
    
}