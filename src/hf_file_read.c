/*Binary search tree to find the uniques characters and their frequency from the given text file*/
void insert(char x){
	new=(tree*)malloc(sizeof(tree));
	new->c=x;
	new->f=1;
	new->left=new->right=NULL;
	
	if(r==NULL)
		r=new;
	else{
		temp=r;
		int flag=1;
		while(flag){
			if(x==temp->c){temp->f=temp->f+1;break;}
			if(x<temp->c && temp->left==NULL){
				temp->left=new;
				break;
			}
			else if(x>temp->c && temp->right==NULL){
				temp->right=new;
				break;
			}
			if(x<temp->c)temp=temp->left;
			else temp=temp->right;
		}
	}
}

