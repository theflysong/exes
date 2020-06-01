#include<bits/stdc++.h>
using namespace std;

map<string,string> replaceMap;//�滻map,����"pbulci->public"
vector<string> keys;//jvav�ؼ������� 

inline void replaceAll(string &str,const string old1,const string new1){//�滻���� 
	while(str.find(old1)!=-1){
    	str.replace(str.find(old1),old1.length(),new1);
	}
}

inline void add(string jvavCode,string javaCode){//����һ��jvav�ؼ��� 
	replaceMap[jvavCode]=javaCode;
	keys.push_back(jvavCode);
}

inline void init(){//��ʼ���������Ĺؼ��ְ�����Ĺؼ��֣�����Ǹ��ؼ�����add  �����Ĺؼ�������Ӧ��java���������Ĺؼ��֣�����Ǹ��ؼ�����add 
	/*��/����*/
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
	
	/*�����*/
	add("calss","class");
	add("ifatecre","interface");
	add("etxends","extends");
	add("imenemptls","implements"); 
	add("tish","this");
	add("nwe","new");  
	add("itorpm","import");
	add("pagacke","package");
	add("nevati","native");
	
	/*�������*/
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
	
	/*���η�*/
	add("pbulci","public");
	add("pvitare","private");
	add("pteredoct","protected"); 
	add("fnail","final");
	add("sitact","static");
	add("atsabrct","abstract");
	add("trinsetan","transient");
	add("vatilole","volatile");
	
	/*ע��*/
	add("@Oriveder","@Override");
	
	/*����*/
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

inline void getCode(string& str){//���jvav���� 
	while(!fin.eof()){
		str+=fin.get();
	}
	str=str.substr(0,str.length()-1);
}

void compiler(int argc,char *argv[]){//������ 
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
		cout<<"����Ĳ�������!";
		return 1;
	}
	string opt(argv[2]); 
	if(opt=="-o"){
		compiler(argc,argv);
	}
	else if(opt=="-h"){
		cout<<"���еĲ�����:\n";
		cout<<"-h: ��ð���\n";
		cout<<"-o: ��jvav��������java����\n";
	}
	else{
		cout<<"����Ĳ�������";
		return 1; 
	}
	return 0;
}
