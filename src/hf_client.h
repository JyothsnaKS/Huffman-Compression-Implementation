/*Binary Search Tree*/
typedef struct tree
{  char c;
	int f;
  struct tree *left,*right;
} tree;

/*Heap*/
typedef struct node{
	char c;
	int f;
	struct node*left,*right;
}node;

tree *new,*temp,*r;
node * h[100];
node*root;
int t; // total no. of bits in the compressed file
int a; // sum of frequency of all characters in the given text file
int pos,count; // total no. of unique characters
int z; // last index of bit string
FILE * hfcode;
FILE * decomp;
FILE * actualdecomp;

void inorder(tree*,char*,int*);
int convertBinaryToDecimal(int*, int);
void insert(char);
void init(char*c,int*f);
void minheapify();
void adjust();
void combine();
void printCodes(node*,int*,int);
int printChar(node*,int*,int);