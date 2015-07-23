# BST-DoubleLinkedList-conversion
This program converts a binary search tree into a double linked list while traversiong it in a breadth 
first manner whith the root being the first element in the linked list

The number of inputs to be given is taken from the user at the beginning of the program.
Now the inputs have to be given for the tree. As the inputs are given the tree is formed 
for each input the enterIntoTree() function is called and the enterd value is entered into
the tree.
Once this is done the convert function is called which traverses the tree created in a breadth
first manner where the nodes at the bottom right are traversed and according to the level of the tree
the nodes are converted into a double linked list. The previous value of the tree node is stored
in a temporary variable 
Once the entire tree is converted to a double linked list the converted linked list is traversed as
a double queue.
