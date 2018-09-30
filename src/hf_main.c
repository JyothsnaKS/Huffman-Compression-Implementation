#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "hf_client.h"
#include "hf_file_read.c"
#include "hf2.c"

void inorder(tree*r,char*c,int*f){
	if(r!=NULL){
		inorder(r->left,c,f);
		c[pos]=r->c;
		f[pos]=r->f;
		pos++;
		inorder(r->right,c,f);
	}
}

/*convert bit strings to the corresponding decimal number*/
int convertBinaryToDecimal(int*finalarr, int i){
	
    int decimalNumber = 0,j=z-i-1;
    while (i<z){
		//printf("%d ",finalarr[i]);
		decimalNumber += finalarr[i]*pow(2,j);
        ++i;
		--j;
    }
	//printf("%d\n",decimalNumber);
    putc(decimalNumber,actualdecomp);
}

void main(int**argv,char**argc){
	char ch;
	int noc=0;
	FILE * file;
	file=fopen(argc[1],"r");
	hfcode=fopen("hfcode.txt","w");
	decomp=fopen("decompressed.txt","w");
	actualdecomp=fopen("actualdecomp.txt","w");

	if(file){
		while((ch=getc(file))!=EOF){ // read input text file
				insert(ch);
				noc++;
		}
		
		int finalarr[noc*20];
		char c[100];
		int f[100],arr[100],cnt,dc;
		inorder(r,c,f);
		
		int i,bitcount=0,start=0;
		count=cnt=pos;
		
		init(c,f);
		minheapify();
		combine();
		root=h[0];
		printCodes(root,arr,0);
		
		fclose(file);
		file=fopen(argc[1],"r");
		
		for(i=0;i<cnt;i++)
			a+=f[i];
		printf("$\n%2.2f",t/a/8.0*100);
		
		/*generate a bit string of Huffman codes for the given text file*/
		while((ch=getc(file))!=EOF){
			fclose(hfcode);
			hfcode=fopen("hfcode.txt","r");
			while((dc=getc(hfcode))!=EOF){
				if(dc==ch){
					dc=getc(hfcode);
					
					while((dc=getc(hfcode))!='\n'){
						finalarr[z]=dc-48;
						z++;
						bitcount++;
						if(bitcount==8){
							convertBinaryToDecimal(finalarr,start);
							start=z;
							bitcount=0;
						}
					}
					break;
				}
				else
					while((dc=getc(hfcode))!='\n');
			}
		}
		convertBinaryToDecimal(finalarr,start);
		fclose(actualdecomp);
		
		/*to create a compressed text file*/
		for(i=0;i<z;i++)
			putc(finalarr[i]+48,decomp);	

		printf("\n");
		printChar(root,finalarr,0);
	}
	else
		printf("File could not opened\n");
	fclose(file);	
}