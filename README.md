# Practice Tree Ordering 

This is a tool that should help you practice determining the structure of a tree from having 2 of the orderings we discussed in class.
This is essentially just a modification of the AVL Tree from lab9. In order of this to work you MUST fill in your implementations from lab9, as I did not want to include mine in order to avoid an honor code violation.

## Instructions
	
I am just uploading the code for this so you must compile it on your own machine. I just used: 

```
g++ -std=c++14 -Wall -Werror -Wvla -Wextra -pedantic -Wconversion *.cpp
```

When you run the program it a couple arguments although I did not use getopt for this so they aren't required, but if you don't put them, the only output will be a tree structure itself.

Possible arguments inculde: "post", "pre", "in", "level" 

```
./a.out in level
```

Will output the pre, and postordering and then when you are ready you can enter any character to have the tree printed out.

It is valid to put 3 or more orderings in and it is valid to put none in. 

## Other

To download either use :
```
git clone https://github.com/esolarz/Tree-Practice-.git
```


or just download it via the github page, but I think you might need to make a github account to install


At the moment the code only make a tree with 10 numbers, from 0 to 9 if you want to make a larger or smaller tree feel free to change it to your liking

As I said earlier I used the AVL tree from lab9, but that also could mean there are certain cases that are not going to be represented by this program, so there may be other things you need to study. I just used the AVL tree because it had the most prewritten code for printing out trees, and I don't really want to mess with it very much, and I also didn't want to spend that much time writing this.
If you want a tree that is not self balancing, I'm sure that the insert function can be adjusted to not use the rotate functions. 

If anything is unclear or your have improvements/suggestions email me at esolarz@umich.edu



