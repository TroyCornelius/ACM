#include<iostream>
#include<cmath>
using namespace std;
template<class Type>class StackQueueTree;

template<class Type>class TreeNode
{
    friend class StackQueueTree<Type>;
    Type data;
    TreeNode<Type> *lchild,*rchild;
public:
    TreeNode(Type n);                      //构造函数
};

template<class Type>class StackQueueNode
{
    friend class StackQueueTree<Type>;
    StackQueueNode<Type> *next;
    TreeNode<Type> *ptree;
public:
    StackQueueNode(TreeNode<Type>* q);              // 构造函数
};

template<class Type>class StackQueueTree
{
    TreeNode<Type> *root,*Q;
    StackQueueNode<Type> *top,*help,*front,*rear;
    int number;
public:
    StackQueueTree();                               //构造函数
    TreeNode<Type>* GetRoot();
    void InsertNode();
    void CreateTree(TreeNode<Type>* &q,Type *p,int n);
    void Quicksort(Type *p,int l,int r);
    void firstTree(TreeNode<Type> *q);
    void middleTree(TreeNode<Type> *q);
    void lastTree(TreeNode<Type> *q);
    void DeleteTree(TreeNode<Type> *q);
    bool SortNode(TreeNode<Type> *q,Type n);
public:
    void Push(TreeNode<Type>* a);
    TreeNode<Type>* Pop();
    void MiddlePrint();
public:
    TreeNode<Type>* PopQueue();
    void Travel();
    ~StackQueueTree();
};
template<class Type>
TreeNode<Type>::TreeNode(Type n):data(n),lchild(0),rchild(0) {}
template<class Type>
StackQueueNode<Type>::StackQueueNode(TreeNode<Type>* q):next(0)
{
    ptree=q;
}

template<class Type>
StackQueueTree<Type>::StackQueueTree():Q(0),top(0),front(0),rear(0)                      //构造函数
{
    cout<<"请输入创建的树的层数。"<<endl;
    cin>>number;
    int k;
    Type *p=new Type[k=pow(2,number)-1];
    for(int i=0; i<k; i++)
    {
        cout<<"请依次输入结点的值。"<<endl;
        cin>>p[i];
    }
    CreateTree(root,p,number);
}
template<class Type>
TreeNode<Type>* StackQueueTree<Type>::GetRoot()
{
    return root;
}
template<class Type>
void StackQueueTree<Type>::InsertNode() {}
template<class Type>
void StackQueueTree<Type>::CreateTree(TreeNode<Type> *&q,Type *p,int n)
{
    static int i=0;
    if(n>0)
    {
        q=new TreeNode<Type>(p[i]);
        i++;
        CreateTree(q->lchild,p,n-1);
        CreateTree(q->rchild,p,n-1);
    }
}

template<class Type>
void StackQueueTree<Type>::firstTree(TreeNode<Type> *q)
{
    if(q!=0)
    {
        cout<<"先序遍历二叉树的结点的值为："<<q->data<<endl;
        firstTree(q->lchild);
        firstTree(q->rchild);
    }
}
template<class Type>
void StackQueueTree<Type>::middleTree(TreeNode<Type> *q)
{
    if(q!=0)
    {
        middleTree(q->lchild);
        cout<<"中序遍历二叉树的结点的值为："<<q->data<<endl;
        middleTree(q->rchild);
    }
}
template<class Type>
void StackQueueTree<Type>::lastTree(TreeNode<Type> *q)
{
    if(q!=0)
    {
        lastTree(q->lchild);
        lastTree(q->rchild);
        cout<<"后序遍历二叉树的结点的值为："<<q->data<<endl;
    }
}
template<class Type>
void StackQueueTree<Type>::DeleteTree(TreeNode<Type> *q)
{
    if(q!=0)
    {
        DeleteTree(q->lchild);
        DeleteTree(q->rchild);
        delete q;
    }
    else
        delete q;
}
template<class Type>
bool StackQueueTree<Type>::SortNode(TreeNode<Type> *q,Type n)
{
    static int k=0,j=n;
    if(j!=n)
    {
        k=0;
        j=n;
    }
    if(q!=0)
    {
        if(q->data==n)
            k=1;
        SortNode(q->lchild,n);
        SortNode(q->rchild,n);
        return k;
    }
    return k;
}


template<class Type>
void StackQueueTree<Type>::Push(TreeNode<Type>* a)
{
    help=new StackQueueNode<Type>(a);
    //  help->ptree=a;
    help->next=top;
    rear=top=help;
    while(help->next!=0)
        help=help->next;
    front=help;
}
template<class Type>
TreeNode<Type>* StackQueueTree<Type>::Pop()
{
    TreeNode<Type>* k=top->ptree;
    help=top;
    top=help->next;
    delete help;
    help=0;
    return k;
}
template<class Type>
void StackQueueTree<Type>::MiddlePrint()
{
    Q=root;
    int k=1,r=pow(2,number)-1;
    while(k<=r)
    {
        while(Q!=0)
        {
            Push(Q);
            Q=Q->lchild;
        }
        Q=Pop();
        cout<<"中序遍历二叉树的结点的值为(非递归)："<<Q->data<<endl;
        k++;
        while(k<=r)
        {
            Q=Pop();
            cout<<"中序遍历二叉树的结点的值为(非递归)："<<Q->data<<endl;
            k++;
            Q=Q->rchild;
            if(Q==0)
                continue;
            while(Q!=0)
            {
                Push(Q);
                Q=Q->lchild;
            }
            Q=Pop();
            cout<<"中序遍历二叉树的结点的值为(非递归)："<<Q->data<<endl;
            k++;
        }
    }
}
template<class Type>
TreeNode<Type>* StackQueueTree<Type>::PopQueue()
{
    TreeNode<Type>* k=front->ptree;
    help=rear;
    while(help->next!=front&&help->next!=0)
        help=help->next;
    delete front;
    front=help;
    return k;
}
template<class Type>
void StackQueueTree<Type>::Travel()
{
    Q=root;
    int k=1,r=pow(2,number)-1;
    Push(Q);
    cout<<"按层次遍历二叉树的结点的值为:"<<Q->data<<endl;
    k++;
    if(Q->lchild!=0)
    {
        //   Push(Q->lchild);
       cout<<"按层次遍历二叉树的结点的值为:"<<Q->lchild->data<<endl;
        k++;
    }
    if(Q->rchild!=0)
    {
        //   Push(Q->rchild);
        cout<<"按层次遍历二叉树的结点的值为:"<<Q->rchild->data<<endl;
        k++;
    }
    while(k<=r)
    {
        //     Q=PopQueue();
        if(Q->lchild!=0)
        {
            //         Push(Q->lchild);
            cout<<"按层次遍历二叉树的结点的值为:"<<Q->lchild->data<<endl;
            k++;
        }
        if(Q->rchild!=0)
        {
            //         Push(Q->rchild);
           cout<<"按层次遍历二叉树的结点的值为:"<<Q->rchild->data<<endl;
            k++;
        }
    }
}
template<class Type>
StackQueueTree<Type>::~StackQueueTree()
{
    DeleteTree(root);
    root=0;
    while(top!=0)
    {
        help=top;
        top=help->next;
        delete help;
    }
    while(rear!=front)
    {
        help=rear;
        rear=help->next;
        delete help;
    }
    delete rear;
    help=rear=front=0;
}
int main()
{
    StackQueueTree<int> a;
    a.firstTree(a.GetRoot());
    cout<<endl;
    a.middleTree(a.GetRoot());
    cout<<endl;
    a.lastTree(a.GetRoot());
    int k;
    cout<<"Please input the number of tree's node."<<endl;
    cin>>k;
    if(a.SortNode(a.GetRoot(),k))
        cout<<"Exist."<<endl;
    else
        cout<<"Doesn't exist."<<endl;
    cout<<"Please input the number of tree's node."<<endl;
    cin>>k;
    if(a.SortNode(a.GetRoot(),k))
        cout<<"Exist."<<endl;
    else
        cout<<"Doesn't exist."<<endl;
    a.firstTree(a.GetRoot());
    cout<<endl;
    a.middleTree(a.GetRoot());
    cout<<endl;
    a.lastTree(a.GetRoot());
    cout<<endl;
    a.MiddlePrint();
    cout<<endl;
    a.Travel();
    return 0;
}
