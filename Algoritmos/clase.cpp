#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
typedef int *pint;

// metodo merge sort, recibe un array como puntero y recibe el tamanio de este. ordena el arreglo de forma recursiva para valores n >= 9, lo que hace es dividir el arreglo en 2 partes recursivamente, de modo que cuando se obtengan los arreglos mas reducidos posibles, es decir n = 1, se empiezan a construir subarreglos de tamanio 2,3,... n recursivamente

int *merge(int *a, int n)
{
    int t;
    if (n < 9) // para un arreglo de tamanio menor a 9 se realiza selection sort
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    } // caso contrario, resulta conveniente ejecutar propiamente el merge sort
    else
    {
        int m = n / 2; // se almacena el size de los subarreglos para m y m2
        int m2 = n - m;
        int *left = new int[m]; // variables apuntadoras para arreglos m y m2 para acceder en el llamado recursivo
        int *right = new int[m2];
        for (int i = 0; i < m; i++)
        {
            left[i] = a[i];
        }
        for (int i = 0; i < m2; i++)
        {
            right[i] = a[m++];
        }
        left = merge(left, m);
        right = merge(right, m2);
        int l = 0;
        int r = 0;
        int i = 0;
        while (l < m && r < m2)
        {
            if (left[l] < right[r])
            {
                a[i++] = left[l++];
            }
            else
            {
                a[i++] = right[r++];
            }
        }
        while (l < m)
        {
            a[i++] = left[l++];
        }
        while (r < m2)
        {
            a[i++] = right[r++];
        }
        delete[] left;
        delete[] right;
    }
    return a;
}

int *quick(int *a, int n)
{
    int t;
    if (n < 9)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    else
    {
        std::srand(std::time(nullptr));
        double random_variable = ((double)std::rand()) / RAND_MAX;
        int piv = (int)(random_variable * n);
        int m = 0;
        int m2 = 0;
        int *left = new int[n];
        int *right = new int[n];
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= a[piv])
            {
                left[m++] = a[i];
            }
            else
            {
                right[m2++] = a[i];
            }
        }
        left = quick(left, m);
        right = quick(right, m2);
        int i = 0;
        int l = 0;
        while (l < m)
        {
            a[i++] = left[l++];
        }
        int r = 0;
        while (r < m2)
        {
            a[i++] = right[r++];
        }
        delete[] left;
        delete[] right;
    }
    return a;
}

int *bucket(int *a, int n)
{
    int k = 100;
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        else
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }
    }
    int length = (max - min) / k;
    pint *buck = new pint[k];
    for (int i = 0; i < k; i++)
    {
        buck[i] = new int[n];
    }

    int *c = new int[k];
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }

    int idx;
    for (int i = 0; i < n; i++)
    {
        idx = (a[i] - min) / length;
        buck[idx][c[idx]++] = a[i];
    }

    for (int i = 0; i < k; i++)
    {
        buck[i] = merge(buck[i], c[i]);
    }

    int l = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < c[i]; j++)
        {
            a[l++] = buck[i][j];
        }
    }

    delete[] c;
    for (int i = 0; i < k; i++)
    {
        delete[] buck[i];
    }
    delete[] buck;

    return a;
}

template <typename T> // plantilla de C++ que sirve para ser utilizada con cualquier tipo de dato
class Node
{
public:
    T data;

public:
    Node<T> *next;
    Node<T>(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        delete this->next;
    }
};

template <typename T>
class List
{
protected:
    Node<T> *head;

protected:
    Node<T> *tail;

protected:
    int size = 0;
    List()
    {
        head = NULL;
        tail = NULL;
    }

public:
    bool isEmpty()
    {
        return head == NULL;
    }

public:
    void push(T data)
    {
        Node<T> *aux = new Node<T>(data);
        if (isEmpty())
        {
            head = tail = aux;
        }
        else
        {
            aux->next = head;
            head = aux;
        }
        size++;
    }

public:
    void append(T data)
    {
        Node<T> *aux = new Node<T>(data);
        if (head == NULL)
        {
            head = aux;
            tail = aux;
        }
        else
        {
            tail->next = aux;
            tail = aux;
        }
        size++;
    }

public:
    bool insert(T data, int n)
    {
        if (n < 0 || n > size)
            return false;
        Node<T> *aux = new Node<T>(data);
        if (n == 0)
        {
            aux->next = head;
            head = aux;
            if (tail == NULL)
                tail = aux;
        }
        else
        {
            Node<T> *r = head;
            for (int i = 1; i <= n; i++)
                r = r->next;
            if (r == NULL)
            {
                tail->next = aux;
                tail = tail->next;
            }
            else
            {
                aux->next = r->next;
                r->next = aux;
            }
        }
        size++;
        return true;
    }

public:
    bool remove(T data)
    {
        if (head == NULL)
            return false;
        Node<T> *aux = head;
        if (head->data == data)
        {
            head = head->next;
            if (head == NULL)
                tail = NULL;
            delete aux;
        }
        else
        {
            Node<T> *aux2 = aux;
            aux = aux->next;
            while (aux != NULL && aux->data != data)
            {
                aux2 = aux;
                aux = aux->next;
            }
            if (aux == NULL)
                return false;
            aux2->next = aux->next;
            delete aux;
            if (aux2->next == NULL)
                tail = aux2;
            return true;
        }
    }

public:
    Node<T> *pop()
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            Node<T> *aux = head;
            if (head == tail)
            {
                tail = NULL;
            }
            head = head->next;
            size--;
            return aux;
        }
    }

public:
    void invert()
    {
        if (head == NULL)
            return;
        tail = head;
        Node<T> *aux2 = NULL;
        Node<T> *aux = head;
        Node<T> *aux3 = head->next;
        while (aux3 != NULL)
        {
            aux->next = aux2;
            aux2 = aux;
            aux = aux3;
            aux3 = aux2->next;
        }
        head = aux;
    }

public:
    void sort()
    {
        if (head == NULL)
            return;
        T t;
        Node<T> *aux = head;
        Node<T> *aux2;
        while (aux->next != NULL)
        {
            aux2 = aux->next;
            while (aux2 != NULL)
            {
                if (aux->data > aux2->data)
                {
                    t = aux->data;
                    aux->data = aux2->data;
                    aux2->data = t;
                }
                aux2 = aux2->next;
            }
            aux = aux->next;
        }
    }

public:
    void insertSortNode(Node<T> node)
    {
        if (head == NULL)
        {
            head = node;
            head->next = NULL;
            tail = head;
        }
        else
        {
            if (head->data > node->data)
            {
                node->next = head;
                head = node;
            }
            else
            {
                Node<T> *aux = head;
                while (aux != NULL && aux->data < node->data)
                {
                    aux = aux->next;
                }
                if (aux == NULL)
                {
                    tail->next = node;
                    node->next = NULL;
                }
                else
                {
                    node->next = aux->next;
                    aux->next = node;
                }
            }
        }
    }

public:
    void bucket(int k, int a, int b)
    {
        List<Node<T>> l = List<Node<T>>();
        for (int i = 0; i < k; i++)
        {
            l.append(List<T>());
        }
    }
};

template <typename T>
class TreeNode
{
public:
    T data;

public:
    int height = 0;

public:
    TreeNode<T> *left;

public:
    TreeNode<T> *right;
    TreeNode<T>(T data)
    {
        this->data = data;
        this->right = this->left = NULL;
    }

    ~TreeNode()
    {
        delete this->left;
        delete this->right;
    }
};

template <typename T>
class Tree
{
protected:
    TreeNode<T> *root;

protected:
    int size = 0;
    Tree()
    {
        root = NULL;
    }

    ~Tree()
    {
        if (root != NULL)
            delete root;
    }

public:
    void breadth_traverse()
    {
        if (root != NULL)
        {
            List<TreeNode<T>> queue;
            queue.append(root);
            while (!queue.isEmpty())
            {
                TreeNode<T> *aux = queue.pop()->data;
                if (aux->left != NULL)
                {
                    queue.append(aux->left);
                }
                if (aux->right != NULL)
                {
                    queue.append(aux->right);
                }
                std::cout << aux->data << ' ';
            }
        }
    }

public:
    void depth_traverse()
    {
        if (root != NULL)
        {
            List<TreeNode<T>> stack;
            stack.push(root);
            while (!stack.isEmpty())
            {
                TreeNode<T> *aux = stack.pop()->data;
                if (aux->left != NULL)
                {
                    stack.push(aux->left);
                }
                if (aux->right != NULL)
                {
                    stack.push(aux->right);
                }
                std::cout << aux->data << ' ';
            }
        }
    }

public:
    void add(T data)
    {
        TreeNode<T> *aux = root;
        if (root == NULL)
        {
            root = new TreeNode<T>(data);
        }
        else
        {
            TreeNode<T> *aux2 = NULL;
            while (aux != NULL)
            {

                aux2 = aux;
                aux->height++;
                if (data < aux->data)
                {
                    aux = aux->left;
                }
                else
                {
                    aux = aux->right;
                }
            }
            if (data < aux2->data)
            {
                aux2->left = new TreeNode<T>(data);
            }
            else
            {
                aux2->right = new TreeNode<T>(data);
            }
        }
    };
};

template <typename T>
class AVL : Tree<T>
{
    AVL(){};

public:
    void balance()
    {
    }

public:
    void add(T data)
    {
        Tree<T>::add(data);
    };
};

template <typename T>
class NTreeNode
{
public:
    int b;

public:
    int size = 0;

public:
    NTreeNode<T> *parent;

public:
    NTreeNode<T> *next;

public:
    NTreeNode<T> *prev;

    NTreeNode<T>(int b)
    {
        this->b = b;
        this->parent = NULL;
        this->next = NULL;
        this->prev = NULL;
    }

    virtual bool isFull() = 0;

    virtual NTreeNode *add(T data) = 0;
};

template <typename T>
class InnerNode : public NTreeNode<T>
{
public:
    NTreeNode<T> **children;

public:
    T *range;

    InnerNode<T>(int b) : NTreeNode<T>(b)
    {
        this->children = new NTreeNode<T>[b];
        for (int i = 0; i < b; i++)
        {
            this->children[i] = NULL;
        }
        range = new T[b - 1];
    }

    ~InnerNode()
    {
        for (int i = 0; i < this->b; i++)
        {
            if (this->children[i] != NULL)
            {
                delete this->children[i];
            }
        }
        delete[] this->range;
        delete[] this->children;
    }

public:
    NTreeNode *add(T data)
    {
    }

public:
    NTreeNode *split(NTreeNode *right)
    {
    }
};

template <typename T>
class LeafNode : public NTreeNode<T>
{
public:
    T *data;

public:
    NTreeNode<T> **children;

    LeafNode<T>(int b) : NTreeNode<T>(b)
    {
        this->data = new T[b];
        this->children = new NTreeNode<T>[b];
        for (int i = 0; i < b; i++)
        {
            this->children[i] = NULL;
        }
        this->parent = NULL;
        this->next = NULL;
        this->prev = NULL;
    }

    ~LeafNode()
    {
        delete[] this->data;
    }

public:
    NTreeNode *add(T data)
    {
        if (isFull())
        {
            // Split
            int b2 = this->b / 2;
            int n2 = this->b - b2;
            LeafNode<T> *right = new LeafNode<T>(this->b);
            for (int i = 0; i < b2; i++)
            {
                right->data[i] = this->data[i + n2];
            }
            right->size = b2;
            this->size = n2;
            this->next = right;
            right->prev = this;
            if (data < right->data[0])
            {
                this->add(data);
            }
            else
            {
                right->add(data);
            }
            // Informar al padre del split
            if (this->parent != NULL)
            {
                return this->parent->split(right);
            }
            else
            {
                InnerNode<T> *p = new InnerNode<T>(this->b);
                p->children[0] = this;
                p->children[1] = right;
                p->range[0] = right->data[0];
                this->parent = p;
                right->parent = p;
                p->size = 2;
                return p;
            }
        }
        else
        {
            // Add data into array
            int m = this->size / 2;
            int a = 0;
            int b = this->size;
            while (a < b)
            {
                if (data < this->data[m])
                {
                    b = m;
                }
                else
                {
                    a = m;
                }
                m = (a + b) / 2;
            }
            // Correr datos desde posicion (a,m,b???)
            // agregar dat en posicion ...
      this->data[?] = data;
      this->size++;
      return this;
        }
    }

public:
    bool isFull()
    {
        return this->size == this->b;
    }
};

template <typename T>
class NTree
{
public:
    NTreeNode<T> *root = NULL;

public:
    int b;

public:
    NTree(int b)
    {
        this->b = b;
    }

public:
    void add(T data)
    {
        if (root == NULL)
        {
      root = new LeafNode<T>(b);
        }
        root->add(data);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}