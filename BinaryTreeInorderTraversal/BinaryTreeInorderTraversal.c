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
    printf(ptr.val);

    if (ptr.left != NULL)
    {
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
