#include "AVL_tree.h"
#include <assert.h>

int main() {
    AVLTree first_tree;
    // Insert using new keys.
    std::cout << "Inserting 3 pairs: " << std::endl;
    first_tree.insert(8002, "Joe Morrison");
    first_tree.insert(8004, "Jack Lewis");
    first_tree.insert(8001, "Tim Hardy");
    std::cout << "Check first_tree's height. It must be 2: " << std::endl;
    assert(first_tree.height(first_tree.getRoot()) == 2);
    std::cout << "Okay. Passed. " << std::endl;

    std::cout << "\nPrinting first_tree (In-Order) after inserting 3 nodes...\n";
    std::cout << "It is Expected to dispaly (8001 Tim Hardy) (8002 Joe Morrison) (8004 Jack Lowis). " << std::endl;
    first_tree.inorder(first_tree.getRoot());
    
    // Pretend that a user is trying to find data by some keys.
    std::cout << "\n\nLet's try to find two keys in the first tree: 8001 and 8000...\n";
    std::cout << "It is expected to find 8001 and NOT to find 8000.\n";
    
    first_tree.find(8001);
    if(first_tree.cursor_key() && first_tree.cursor_key() == 8001)
        std::cout << "Key 8001 was found...\n";
    else
        std::cout << "Key 8001 NOT found...\n";
    
    first_tree.find(8000);
    
    if(first_tree.cursor_ok() && first_tree.cursor_key() == 8000)
        std::cout << "Key 8000 was found...\n";
    else
        std::cout << "Key 8000 NOT found...\n";
    
    //test copying
 
    std::cout << "\nTest Copying, using Copy Ctor..." << std::endl;
    AVLTree second_tree(first_tree);
    std::cout << "Using assert to check second_tree's data value:\n";
    assert(second_tree.cursor_datum() == "Joe Morrison");
    std::cout << "Okay. Passed" << std::endl;
    
    std::cout << "Expected key/value pairs in second_tree: (8001 Tim Hardy) (8002 Joe Morrison) (8004 Jack Lowis). " << std::endl;
    first_tree.inorder(first_tree.getRoot());
    
    std::cout << "\n\nInserting more key/data pairs into first_tree..." << std::endl;
    first_tree.insert(8000, "Ali Neda");
    first_tree.insert(8003, "Jim Sanders");
    std::cout << "Check first-tree's height. It must be 3: " << std::endl;
    assert(first_tree.height(first_tree.getRoot()) == 3);
    std::cout << "Okay. Passed" << std::endl;
    std::cout << std::endl << "Display first_tree nodes in-order:\n";
    first_tree.inorder(first_tree.getRoot());
    
    std::cout << std::endl << "\nDisplay second_tree nodes in-order: \n";
    first_tree.inorder(second_tree.getRoot());
    
    std::cout << std::endl << "\nMore insersions into first_tree and second_tree" << std::endl;
    first_tree.insert(1001, "Jack");
    first_tree.insert(2002, "Tim");
    first_tree.insert(3003, "Carol");
    
    second_tree.insert(4004, "Allen");
    second_tree.insert(5005, "Russ");
    second_tree.insert(2525, "Mike");

    std::cout << "\nValues and keys in the first_tree after new 3 insersions" << std::endl;
    std::cout << "In-Order:" << std::endl;
    first_tree.inorder(first_tree.getRoot());
    
    std::cout << std::endl << "Pre-Order:" << std::endl;
    first_tree.preorder(first_tree.getRoot());

    std::cout << std::endl << "Post-Order:" << std::endl;
    first_tree.postorder(first_tree.getRoot());
    
    std::cout << "\n\nValues and keys in second_tree after 3 new insersions" << std::endl;
    std::cout << "In-Order:" << std::endl;
    first_tree.inorder(second_tree.getRoot());
    
    std::cout << std::endl << "Pre-Order:" << std::endl;
    first_tree.preorder(second_tree.getRoot());

    std::cout << std::endl << "Post-Order:" << std::endl;
    first_tree.postorder(second_tree.getRoot());
    std::cout << std::endl;
    
    std::cout << "\nTest Copying, using Assignment Operator..." << std::endl;
    AVLTree third_tree;

    third_tree = second_tree;
    std::cout << "Using assert to check third_tree's data value:\n";
    assert(third_tree.cursor_datum() == "Russ");
    std::cout << "Okay. Passed" << std::endl;
    
    std::cout << "Expected key/value pairs in third_tree: (2525, Mike) (4004, Allen) (5005, Russ) (8001, Tim Hardy) (8002, Joe Morrison) (8004, Jack Lewis)." << std::endl;
    third_tree.inorder(third_tree.getRoot());
    std::cout << std::endl << "Program Ends..." << std::endl;
    return 0;
}
