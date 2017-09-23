# Draw-Binary-Tree-
Making a function that draws binary tree on to the console.


The header file assumes your node in the tree is defined as follows:

<pre>
struct node
{
	int data;
	struct node *left;
	struct node *right;

}*root=NULL;
</pre>

NOTE:
The displayTree.h header file already contains this structure definition 
so you don't need to make it again in your main program.

If you want the structure definition in the main program itself, 
comment out the defintion in the displayTree.h

_______________________________________________________



This is how the tree looks like


<img src = "https://github.com/dingusagar/Draw-Binary-Tree-/blob/master/tree.PNG?raw=true"/>

It displays average trees nicely , but gets little cozy with skewed trees.


