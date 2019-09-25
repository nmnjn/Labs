/* Helper function for getLevel().  
It returns level of the data if data is 
present in tree, otherwise returns 0.*/
int getLevelUtil(struct node *node,  
                 int data, int level) 
{ 
    if (node == NULL) 
        return 0; 
  
    if (node -> data == data) 
        return level; 
  
    int downlevel = getLevelUtil(node -> left,  
                                 data, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(node->right,  
                             data, level + 1); 
    return downlevel; 
} 
  
/* Returns level of given data value */
int getLevel(struct node *node, int data) 
{ 
    return getLevelUtil(node, data, 1); 
} 

/* Compute the "maxDepth" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}
