#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{

    struct TreeNode ptr = *root;

    inorderTraversal(ptr.left, NULL);
    printf("%i \n",ptr.val);

    if (ptr.right != NULL)
    {
        inorderTraversal(ptr.right, NULL);
        printf("%i \n",ptr.val);
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    return 0;
}
