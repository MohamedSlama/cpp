#include <iostream>
#include <vector>
using namespace std;

//Macros
#define LOOP(x,n) for(int x=0;x<n;x++)
#define VECTOR(T1,T2) vector<pair<T1,T2>>

//Table
const short letters_size = 26;
string letters[letters_size]= {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
const short number_size = 10; 
string numbers[number_size]={"1","2","3","4","5","6","7","8","9","0"};
const short operation_size = 7;
string operation[operation_size]={"/","*","-","+","=","%"};
//const short block_size = 4;
//char blocks[block_size]={'{','}','(',')'};
const short identifier_size = 3;
string identifier[identifier_size] = {"int" , "float" , "string"};
const short comparison_size = 4;
string comparison[comparison_size] = {"==" , "<=" , ">=" ,"<>"};


//Functions
VECTOR(string,short) split(string input);
VECTOR(string,string) check(vector<pair<string,short>>);

bool WordCheck(string,string[],const short);

bool IsDigit(string);
bool IsLetter(string);

int main(int argc, char **argv)
{	
	//Input
	//string input = "int x = 4 + <> >= == 4546f45 <= 556786745 + y - float * koko int string float";
	string input = "int x=4+<> >= == 4546f45 <= 556786745+y-float*koko int string float";
	cout << input << endl;
	cout << "######################################" << endl;
	
	//Split
	VECTOR(string,short) vect;
	vect = split(input);
	
	//Check	
	VECTOR(string,string) result = check(vect);
	
	for(pair<string,string> temp : result)
	{
		cout << temp.first << " : " << temp.second << endl;
	}
	
	
	cout << "######################################" << endl;
	return 0;
}

VECTOR(string,short) split(string input){
	short location =0;
	string value = "";
	bool flag = false;
	VECTOR(string,short) vect;
	LOOP(i,input.length()){
		if(input[i]==' ' || WordCheck(string(input[i],1),operation,operation_size)){flag = true; continue;}
		else{
			if(flag){
				//cout << value << endl;
				pair<string,short> result (value,location);
				vect.push_back(result);
				value = ""; location +=1; flag = false;
			}
			value += input[i];
			
		}
	}
	pair<string,short> result (value,location);
	vect.push_back(result);
	return vect;
}



VECTOR(string,string) check(VECTOR(string,short) vect)
{
	VECTOR(string,string) result;
	
	pair<string,string> IdTemp;
	string word;
	
	for(pair<string,int> InputTemp: vect)
	{
		word = InputTemp.first;
		
		// Check small word
		if(word.length() < 3)
		{
			if(WordCheck(word,operation,operation_size)){
				IdTemp.first = word;
				IdTemp.second = "Operation";
				result.push_back(IdTemp);
			}
			else if(WordCheck(word,numbers,number_size)){
				IdTemp.first = word;
				IdTemp.second = "Digit";
				result.push_back(IdTemp);
			}
			else if(WordCheck(word,letters,letters_size)){
				IdTemp.first = word;
				IdTemp.second = "Character";
				result.push_back(IdTemp);
			}
			else if(WordCheck(word,comparison,comparison_size)){
				IdTemp.first = word;
				IdTemp.second = "Comparison";
				result.push_back(IdTemp);
			}
			else{
				IdTemp.first = word;
				IdTemp.second = "Not Valid";
				result.push_back(IdTemp);
			}
		}
		
		// Check Identifier
		else if(WordCheck(word,identifier,identifier_size)){
			IdTemp.first = word;
			IdTemp.second = "Identifier";
			result.push_back(IdTemp);
		}
		
		// Check Word
		else
		{
			if(IsDigit(word))
			{
				IdTemp.first = word;
				IdTemp.second = "Number";
				result.push_back(IdTemp);
			}
			else if(IsLetter(word))
			{
				IdTemp.first = word;
				IdTemp.second = "Word";
				result.push_back(IdTemp);
			}
			else{
				IdTemp.first = word;
				IdTemp.second = "Not Valid";
				result.push_back(IdTemp);
			}
		}
	}
	return result;
}

bool WordCheck(string input,string Arr[],const short SIZE)
{
	LOOP(x,SIZE){
		if(input == Arr[x])
		{
			return true;
		}
	}
	return false;
}

bool IsDigit(string word)
{
	LOOP(i,word.length())
	{
		if(!WordCheck(string(1,word[i]),numbers,number_size))
			return false;
	}
	return true;
}

bool IsLetter(string word)
{
	if(!WordCheck(string(1,word[0]),numbers,number_size))
	{
		return false;
	}
	LOOP(i,word.length())
	{
		if( !WordCheck(string(1,word[i]),letters,letters_size) ||
			!WordCheck(string(1,word[i]),numbers,number_size)
		)
			return false;

	}
	return true;
}
