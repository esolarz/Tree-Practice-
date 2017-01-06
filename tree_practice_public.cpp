#include <iostream>

//For printing out the trees
#include <vector>
#include <utility>
#include <functional>

//for using shuffle
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>


// probably useful
int max(int x, int y) {
    return x > y ? x : y;
}

class AVL {
public:
    struct Node {
        int datum;
        int height;
        Node* left;
        Node* right;
        int left_height() {
            return left ? left->height : 0;
        }
        int right_height() {
            return right ? right->height : 0;
        }
        int balance() {
            return left_height() - right_height();
        }
        // when the height of its children change, call this function to
        // recalculate the height of this node, the parent
        void fix_height() {
            height = 1 + max(left_height(), right_height());
        }
    };
    void insert(int datum);
    const Node* search(int datum, bool print_path = false) const;
    ~AVL();

    // a debugging method that will print the tree for you
    // (use it to inspect small trees, if you want)
    void debug_print_tree() {
        debug_print_node(0, root);
    }

    // NOTE: this function is really complicated
    // don't worry too much about how it works
    // TODO: support 3+ digit numbers
    void print_diagram() {
        struct pos {
            int depth;
            int parent_dir;
        };
        std::vector<std::pair<int, pos>> points;
        std::function<void(Node*, pos p)> traverse_depth = [&](Node* n, pos p) {
            if (n == nullptr) {
                return; }
            traverse_depth(n->left, {p.depth+1, 1});
            points.push_back(std::pair<int, pos>({n->datum, p}));
            traverse_depth(n->right, {p.depth+1, -1});
        };
        traverse_depth(root, {0, 0});
        // points is now filled
        int width = 2 * (int)points.size();
        int height = 0;
        for (int i = 0; i < (int)points.size(); i++) {
            height = max(height, points[i].second.depth);
        }
        height *= 2;
        height++;
        // now, we can build the buffer:
        std::vector<std::vector<char>> buffer(width, std::vector<char>(height, ' '));
        // add the numbers
        for (int i = 0; i < (int)points.size(); i++) {
            int n = points[i].first;
            int d = points[i].second.depth;
            buffer[2*i+1][d*2] = char((n % 10) + '0');
            if (n >= 10) {
                // note: will truncate 3+ digit numbers to their last 2 digits
                buffer[2*i+0][d*2] = char((n / 10) % 10 + '0');
            }
        }
        // add the corner edges
        for (int i = 0; i < (int)points.size(); i++) {
            int d = points[i].second.depth;
            int dir = points[i].second.parent_dir;
            if (dir == 0) {
                continue; // root
            }
            if (points[i + dir].second.depth == d-1) {
                // adjacent parent
                buffer[2*i + (dir > 0 ? 2 : 0)][d*2-1] = (dir > 0 ? '/' : '\\');
            } else {
                int c = 2*i + (dir > 0 ? 2 : -1);
                buffer[c][d*2-1] = (dir > 0 ? '/' : '\\');
                buffer[c + dir][d*2-2] = '-';
                for (int j = i+2*dir; points[j].second.depth != d-1; j += dir) {
                    buffer[2*j][d*2-2] = '-';
                    buffer[2*j+1][d*2-2] = '-';
                }

            }
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                std::cout << buffer[x][y];
            }
            std::cout << std::endl;
        }
    }

    Node* get_root() const{
   	return root; 
    }

    void postorder(Node* node) const;
    void inorder(Node* node) const;
    void preorder(Node* node ) const;
    void levelOrder(Node* node) const; 
    void process_node(Node* node) const;
private:
    Node* root = nullptr;
    size_t size = 0;

    // insert_node returns the increase in height for the provided tree
    Node* insert_node(Node* node, int datum);

    // search_node returns the node, or nullptr
    const Node* search_node(const Node* node, int datum, bool print_path) const;

    // these return the new top node after rotation
    Node* rotate_left(Node* node);
    Node* rotate_right(Node* node);
    void destroy_node(Node* node);

    //MY CUSTOM functions

    void debug_print_node(int depth, Node* node) {
        if (node == nullptr) {
            return;
        }
        debug_print_node(depth+1, node->left);
        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }
        std::cout << node->datum << std::endl;
        debug_print_node(depth+1, node->right);
    }

};

const AVL::Node* AVL::search(int datum, bool print_path) const {
    // just a regular BST search
    return search_node(root, datum, print_path);
}

// search_node searches for 'datum' in the subtree rooted at 'node'.
// if the node cannot be found, it returns nullptr.
const AVL::Node* AVL::search_node(const AVL::Node* node, int datum, bool print_path) const {
    if (node == nullptr) {
        if (print_path) {
            std::cout << "M" << std::endl;
        }
        return nullptr; // not found (no node here)
    }
    if (node->datum == datum) {
        // found the target
        if (print_path) {
            std::cout << "X" << std::endl;
        }
        return node;
    }
    if (datum < node->datum) {
        // left subtree, since smaller than current node
        if (print_path) {
            std::cout << "L";
        }
        return search_node(node->left, datum, print_path);
    } else {
        if (print_path) {
            std::cout << "R";
        }
        // right subtree, since larger than current node
        return search_node(node->right, datum, print_path);
    }
}

void AVL::insert(int datum) {
    root = insert_node(root, datum);
}

// insert_node returns the new root of this subtree after inserting datum.
AVL::Node* AVL::insert_node(AVL::Node* node, int datum) {
    if (node == nullptr) {
        // at a leaf position in the tree, so create a new node
        return new Node { datum, 1, nullptr, nullptr }; // it has height 1
    }
    //I am pretty sure that the starter code had more code here than this, but it shouldn't matter if you finished the lab
    //
    //TODO: YOUR CODE HERE
    //TODO: YOUR CODE HERE
    //TODO: YOUR CODE HERE
    //TODO: YOUR CODE HERE
    //TODO: YOUR CODE HERE
    //TODO: YOUR CODE HERE
    
    return node;
}

// rotate_left performs a left rotation; it returns the new 'root' of the rotated subtree
// (remember to update the heights of nodes!)
// you may assume that it has a right child
AVL::Node* AVL::rotate_left(AVL::Node* node) {
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
}

// rotate_right performs a right rotation; it returns the new 'root' of the rotated subtree
// (remember to update the heights of nodes!)
// you may assume that it has a left child
AVL::Node* AVL::rotate_right(AVL::Node* node) {
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
	//TODO: YOUR CODE HERE
}

AVL::~AVL() {
    destroy_node(root);
}

void AVL::destroy_node(AVL::Node* node) {
    if (node == nullptr) {
        return;
    }
    destroy_node(node->left);
    destroy_node(node->right);
    delete node;
}

void AVL::process_node(Node* node) const {
	std::cout<<" "<<node->datum<<" ";
}
void AVL::preorder(Node* node) const{
	if(node == nullptr)
		return;

	process_node(node);
	preorder(node->left);
	preorder(node->right);
}
void AVL::postorder(Node* node) const{
	if(node == nullptr)
		return;

	postorder(node->left);
	postorder(node->right);
	process_node(node);
}
void AVL::inorder(Node* node) const{
	if(node == nullptr)
		return;
	inorder(node->left);
	process_node(node);
	inorder(node->right);
}

void AVL::levelOrder(Node* node) const{
	std::queue<Node*> children;
	children.push(node);
	while(!children.empty()){
		process_node(children.front());	
		if(children.front()->left)	
			children.push(children.front()->left);
		if(children.front()->right)	
			children.push(children.front()->right);
		children.pop();
	}
}

int main(int argc, char* argv[]){
	std::vector<int> random_tree_nodes(10);
	std::iota(random_tree_nodes.begin(),random_tree_nodes.end(),0);
	
	//shuffle code adapted from cplusplus.com page on shuffle
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); 

	shuffle (random_tree_nodes.begin(),random_tree_nodes.end(),std::default_random_engine(seed));

	AVL random_tree;
	for(int i : random_tree_nodes)
		random_tree.insert(i);	
	
	//print the selected orderings
	for( int n = 1; n<argc;++n ){
		std::string opt(argv[n]);
		if(opt == "post"){
			std::cout<<"postorder: ";
			random_tree.postorder(random_tree.get_root());
			std::cout<<std::endl;
		}	
		else if(opt == "pre"){
			std::cout<<"preorder: ";
			random_tree.preorder(random_tree.get_root());
			std::cout<<std::endl;
		}
		else if(opt == "in"){
			std::cout<<"inorder: ";
			random_tree.inorder(random_tree.get_root());
			std::cout<<std::endl;
		}
		else if(opt == "level"){
			std::cout<<"level Order: ";
			random_tree.levelOrder(random_tree.get_root());
			std::cout<<std::endl;
		}
	}		

	
	std::cout<<"Enter any character when you are ready to see the tree structure"<<std::endl;
	std::string opt;
	std::cin>>opt;

	//show tree structure;
	random_tree.print_diagram();
}
