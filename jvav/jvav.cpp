#include<bits/stdc++.h>
using namespace std;

map<string,string> replaceMap;//�滻map,����"pbulci->public"
vector<string> keys;//jvav�ؼ������� 

inline void add(string jvavCode,string javaCode){
	replaceMap[jvavCode]=javaCode;
	keys.push_back(jvavCode);
}

inline void init(){
	/*���η�*/
	add("pbulci","public");
	add("pvitare","private");
	add("pteredoct","protected"); 
	add("fnail","final");
	add("sitact","static");
	
	/*��/����*/
	add("viod","void");
	add("itn","int");
	add("boloena","boolean");
	add("sorht","short");
	add("lnog","long");
	add("carh","char");
	add("bety","byte");
	add("dlebou","double");
	
	add("Viod","void");
	add("Irtgeen","Integer");
	add("Boloena","Boolean");
	add("Sorht","Short");
	add("Lnog","Long");
	add("Carteharc","Character"); 
	add("Sigtrn","String");
	add("Bety","Byte");
	add("Dlebou","Double");
	
	add("Lsit","List");
	add("Ayrars","Arrays"); 
	add("Ayrar","Array"); 
	add("Octbje","Object");
	
	/*����*/
	add("jvav","java");
	add("lnag","lang"); 
	add("calss","class");
	add("ifatecre","interface");
	add("etxends","extends");
	add("@Oriveder","@Override");
	//add("","");
}

int main(){
	init();
}
