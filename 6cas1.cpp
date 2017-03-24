#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;
int RuznychPismen(string);
int PocetSlov(string);
string PrvniSlovo(string, int); 
string theLongestWord(string);

int main(){
	
	string s = "Alena ma 2 ruce.";
cout<<"RuznychPismen: "<<RuznychPismen(s)<<'\n'; 
cout<<"PocetSlov: "<<PocetSlov(s)<<'\n'; 
cout<<"PrvniSlovo on current position: "<<PrvniSlovo(s, 2)<<'\n'; 
cout<<"theLongestWord: "<<theLongestWord(s)<<'\n'; 

	return 0; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string theLongestWord(string str){
	//copy elements from string to char array;
	char *arr = new char[str.length()];	
	strcpy(arr, str.c_str());
	int quantitySpaces = 0;

	
//deleting not letters
	for(int j=0; arr[j]!=NULL;++j){
		if(isspace(arr[j])) quantitySpaces++;
		if(isdigit(arr[j]) || ispunct(arr[j])){
			for(int k=j; arr[k]!=NULL;++k) arr[k]=arr[k+2];
		}
}

//spliting on words by " "
	string *words = new string[quantitySpaces+1];
	int count=0;
	for(int i=0; arr[i]!=NULL; ++i){
		if(!isspace(arr[i])){
			words[count]+=arr[i];
		}	
		else{
			++count;
		}
	}

	//looking for the longest word
	string max=words[0];
	for(int i=1;i<count;++i){
		if(strlen(words[i].c_str())>strlen(max.c_str()))
		max=words[i];
	}
	delete [] arr;
	delete [] words;
	arr=NULL;
	words=NULL;
	
	return max;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string PrvniSlovo(string str, int position){
	string result;

	//copy elements from string to char array;
	char *arr = new char[str.length()];	
	strcpy(arr, str.c_str());
	
	//deleting not letters
			for(int j=0; arr[j]!=NULL;++j){
		if(isdigit(arr[j])){
			for(int k=j; arr[k]!=NULL;++k) arr[k]=arr[k+2];
		}
}

//if arr[position] is a letter, then return word, in which located this letter
if(isalpha(arr[position])){
	for(int i=position; !isspace(arr[i]) && i>=0; --i){	
		if(isspace(arr[i-1]) || i==0){
			for(int j=i; !isspace(arr[j]) && arr[j+1]!=NULL; ++j)result+=arr[j];
		}
	}

}

//if arr[position] is a space, then return word, which located next(more right)
if(isspace(arr[position])){
	for(int i=position+1; !isspace(arr[i]) && arr[i+1]!=NULL; ++i)result+=arr[i];
}	
	delete [] arr;
	arr=NULL;
	
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int PocetSlov(string str){
	int result=0;	
	
		//copy elements from string to char array;
	char *arr = new char[str.length()];	
	strcpy(arr, str.c_str());
	
	//deleting not leters
		for(int j=0; arr[j]!=NULL;++j){
		if(isdigit(arr[j]) || ispunct(arr[j])){
			for(int k=j; arr[k]!=NULL;++k) arr[k]=arr[k+2];
		}
		if(!isalpha(arr[j])){
			result+=1;
		}
}
	delete [] arr;
	arr=NULL;
	
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int RuznychPismen(string str)  {

	int quantity=0;
	int result=0;
	int repeat=0;
	
	//copy elements from string to char array;
	char *arr = new char[str.length()];	
	strcpy(arr, str.c_str());
	
	
	for(int i=0; arr[i]!=NULL;++i){
		
		//change the all symbols to lower case for compare with each other
		arr[i]=tolower(arr[i]); 
			
	//check,if symbol is not a letter, then delete it	
	for(int j=0; arr[j]!=NULL;++j){
		if(!isalpha(arr[i])){
			for(int k=i; arr[k]!=NULL;++k) arr[k]=arr[k+1];
		}
	}
}

//check, if symbol repeat or not
	for(int i=0; arr[i]!=NULL; ++i){
		quantity+=1;    //number of all elements
		
		for(int j=i-1;j>=0;j--){
			if(arr[j]==arr[i]){
		 	repeat+=1; //number of repeats
		 	break;
			}
			
		}
	}	
	result = quantity-repeat;//number of unique symbols
	
	delete [] arr;
	arr=NULL;
	
	return result;
}
