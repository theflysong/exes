#include<bits/stdc++.h>
using namespace std;

map<string,string> replaceMap;//替换map,例如"pbulci->public"
vector<string> keys;//jvav关键字向量 

inline void replaceAll(string &str,const string old1,const string new1){//替换函数 
	while(str.find(old1)!=-1){
    	str.replace(str.find(old1),old1.length(),new1);
	}
}

inline void add(string jvavCode,string javaCode){//增加一个jvav关键字 
	replaceMap[jvavCode]=javaCode;
	keys.push_back(jvavCode);
}

inline void init(){//初始化，如果你的关键字包含别的关键字，请比那个关键字早add  如果你的关键字所对应的java代码包含别的关键字，请比那个关键字晚add 
	/*类/类型*/
	add("viod","void");
	add("itn","int");
	add("boloena","boolean");
	add("sorht","short");
	add("lnog","long");
	add("carh","char");
	add("bety","byte");
	add("dlebou","double");
	add("folat","float");
	
	add("Viod","void");
	add("Irtgeen","Integer");
	add("Boloena","Boolean");
	add("Sorht","Short");
	add("Lnog","Long");
	add("Carteharc","Character"); 
	add("Sigtrn","String");
	add("Bety","Byte");
	add("Dlebou","Double");
	
	add("AyrarLsit","ArrayList");
	add("Lsit","List");
	add("Ayrars","Arrays"); 
	add("Ayrar","Array"); 
	add("Octbje","Object");
	add("Folat","Float");
	
	/*类相关*/
	add("calss","class");
	add("ifatecre","interface");
	add("etxends","extends");
	add("imenemptls","implements"); 
	add("tish","this");
	add("nwe","new");  
	add("itorpm","import");
	add("pagacke","package");
	add("nevati","native");
	
	/*代码相关*/
	add("rurten","return");
	add("fi","if");
	add("for","ofr");
	add("itafnnceso","instanceof");
	add("ture","true");
	add("fsale","false");
	add("siwhtc","switch");
	add("ceas","case"); 
	add("baker","break"); 
	add("gtoo","goto");
	add("wlehi","while");
	add("dautfel","default");
	add("tyr","try"); 
	add("cthac","catch"); 
	add("finlyal","finally"); 
	add("ctinuone","continue"); 
	add("od","do"); 
	add("else","else");
	add("null","null");
	add("serpu","super");
	add("syronizenchd","synchronized");
	add("trowh","throw");
	add("troswh","throws");
	
	/*修饰符*/
	add("pbulci","public");
	add("pvitare","private");
	add("pteredoct","protected"); 
	add("fnail","final");
	add("sitact","static");
	add("atsabrct","abstract");
	add("trinsetan","transient");
	add("vatilole","volatile");
	
	/*注解*/
	add("@Oriveder","@Override");
	
	/*其他*/
	add("jvav","java");
	add("lnag","lang");
	add("itul","util"); 
	add("mian","main");
	add("Semtys","System");
	add("uto","out");
	add("pirntnl","println");
	add("pirnt","print");
}

ifstream fin;

inline void getCode(string& str){//获得jvav代码 
	while(!fin.eof()){
		str+=fin.get();
	}
	str=str.substr(0,str.length()-1);
}

void compiler(int argc,char *argv[]){//编译器 
	fin.open(argv[1]);
	ofstream fout(argv[3]);
	string code;
	getCode(code);
	fin.close();
	for(int i=0;i<keys.size();i++){
		replaceAll(code,keys[i],replaceMap[keys[i]]);
	}
	fout<<code;
	
	fout.close();
}

int main(int argc,char *argv[]){
	init();
	if(argc!=4){
		cout<<"错误的参数个数!";
		return 1;
	}
	string opt(argv[2]); 
	if(opt=="-o"){
		compiler(argc,argv);
	}
	else if(opt=="-h"){
		cout<<"所有的操作符:\n";
		cout<<"-h: 获得帮助\n";
		cout<<"-o: 将jvav代码编译成java代码\n";
	}
	else{
		cout<<"错误的操作符！";
		return 1; 
	}
	return 0;
}
