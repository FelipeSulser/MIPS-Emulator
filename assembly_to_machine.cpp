#include <iostream>
#include <stdint.h>
#include <string>
#include <cstddef>
#include <vector>
#include <fstream>


using namespace std;

void removeChar(string& str, char character)
{
 size_t pos;
 while( (pos=str.find(character)) != string::npos )
      str.erase(pos, 1);
}

size_t split_header(const std::string &txt, std::vector<std::string> &strs, char ch){
	size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    
    strs.push_back( txt.substr( initialPos, pos - initialPos ) );
    initialPos = pos + 1;

    pos = txt.find( ch, initialPos );
    
    // Add the last one
    strs.push_back( txt.substr( initialPos,  txt.size()  - initialPos + 1 ) );

    return strs.size();
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

uint32_t convert_add_to_machinecode(vector<string> &strs){
	uint32_t code = 32; // 32 for add code
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	removeChar(strs[2],'$');
	num = stoi(strs[2]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	return code;
}

uint32_t convert_addi_to_machinecode(vector<string> &strs){
	uint32_t code = 536870912; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[2]);
	code |= imm;
	return code; 
}
uint32_t convert_addiu_to_machinecode(vector<string> &strs){
	uint32_t code = 603979776; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[2]);
	code |= imm;
	return code;
}

uint32_t convert_addu_to_machinecode(vector<string> &strs){
	
	uint32_t code = 33; // 32 for add code
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	removeChar(strs[2],'$');
	num = stoi(strs[2]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	

	return code;
}

uint32_t convert_and_to_machinecode(vector<string> &strs){
	uint32_t code = 36; // 32 for add code
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	removeChar(strs[2],'$');
	num = stoi(strs[2]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	return code;
}

uint32_t convert_andi_to_machinecode(vector<string> &strs){
	uint32_t code = 805306368; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[2]);
	code |= imm;
	return code;
}

uint32_t convert_beq_to_machinecode(vector<string> &strs){
	uint32_t code = 268435456; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	removeChar(strs[1],'$');
	num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[2]);
	code |= imm;
	return code;
}

uint32_t convert_bne_to_machinecode(vector<string> &strs){
	uint32_t code = 335544320; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	removeChar(strs[1],'$');
	num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[2]);
	code |= imm;
	return code;
}
uint32_t convert_jr_to_machinecode(vector<string> &strs){
	uint32_t code = 8; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	
	
	return code;
}

uint32_t convert_j_to_machinecode(vector<string> &strs){
	uint32_t code = 134217728; // prefix for addi
	int shift_start = 21;
	
	//removeChar(strs[0],'$');
	uint32_t num = stoi(strs[0]);
	code |= num;
	
	
	return code;
}
uint32_t convert_jal_to_machinecode(vector<string> &strs){
	uint32_t code = 201326592; // prefix for addi
	int shift_start = 21;
	
	//removeChar(strs[0],'$');
	uint32_t num = stoi(strs[0]); // check if this number > 26 bit
	code |= num;
	
	
	return code;
}

uint32_t convert_bgez_to_machinecode(vector<string> &strs){
	uint32_t code = 67108864; // prefix for addi
	int shift_start = 21;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	
	code |= ((code >> shift_start) | 1)<< shift_start;
	shift_start -= 5;

	int imm = stoi(strs[1]);
	code |= imm;
	return code;
}

unsigned get_offset(string & s){
	vector<string> splitted;
	split(s, splitted, '(');
	unsigned val = stoi(splitted[0]);
	return val;
}

unsigned get_val(string & s){
	unsigned first = s.find('(');
	unsigned last = s.find(')');
	string strNew = s.substr (first+1,last-first-1);
	removeChar(strNew,'$');
	return stoi(strNew);
}
uint32_t convert_lb_to_machinecode(vector<string> &strs){
	uint32_t code = 2147483648; // prefix for addi
	int shift_start = 21 - 5;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start = 21;
	
	unsigned offset = get_offset(strs[1]);
	unsigned regval = get_val(strs[1]);

	code |= ((code >> shift_start) | regval)<< shift_start;

	code |= offset;
	return code;
}

uint32_t convert_lw_to_machinecode(vector<string> &strs){
	uint32_t code = 2348810240; // prefix for addi
	int shift_start = 21 - 5;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start = 21;
	
	unsigned offset = get_offset(strs[1]);
	unsigned regval = get_val(strs[1]);

	code |= ((code >> shift_start) | regval)<< shift_start;

	code |= offset;
	return code;
}
uint32_t convert_noop_to_machinecode(){
	return 0;
}

uint32_t convert_syscall_to_machinecode(){
	return 12;
}

uint32_t convert_or_to_machinecode(vector<string> &strs){
	uint32_t code = 37; // 32 for add code
	int shift_start = 21;
	
	removeChar(strs[1],'$');
	int num = stoi(strs[1]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;

	removeChar(strs[2],'$');
	num = stoi(strs[2]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	removeChar(strs[0],'$');
	num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start -= 5;
	return code;
}
uint32_t convert_sb_to_machinecode(vector<string> &strs){
	uint32_t code = 2684354560; // prefix for addi
	int shift_start = 21 - 5;
	
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start = 21;
	
	unsigned offset = get_offset(strs[1]);
	unsigned regval = get_val(strs[1]);

	code |= ((code >> shift_start) | regval)<< shift_start;

	code |= offset;
	return code;
}

uint32_t convert_sw_to_machinecode(vector<string> &strs){
	uint32_t code = 2885681152; // prefix for addi
	int shift_start = 21 - 5;
	cout<<"here"<<endl;
	removeChar(strs[0],'$');
	int num = stoi(strs[0]);
	code |= ((code >> shift_start) | num)<< shift_start;
	shift_start = 21;
	
	unsigned offset = get_offset(strs[1]);
	unsigned regval = get_val(strs[1]);

	code |= ((code >> shift_start) | regval)<< shift_start;

	code |= offset;
	return code;
}


uint32_t convert_to_machinecode(string &name){
	vector<string> strs;
	uint32_t output;
	split_header(name, strs, ' ');
	string op = strs[0];
	vector<string> arguments;
	if(strs.size() > 1){
		removeChar(strs[1], ' ');
		
		split(strs[1], arguments, ',');
	}
	if(op == "add"){
		output = convert_add_to_machinecode(arguments);
	}else if(op == "addi"){
		output = convert_addi_to_machinecode(arguments);
	}else if(op == "addiu"){
		output = convert_addiu_to_machinecode(arguments);
	}else if(op == "addu"){
		output = convert_addu_to_machinecode(arguments);
	}else if(op == "and"){
		output = convert_and_to_machinecode(arguments);
	}else if(op == "andi"){
		output = convert_andi_to_machinecode(arguments);
	}else if(op == "beq"){
		output = convert_beq_to_machinecode(arguments);
	}else if(op == "bgez"){
		output = convert_bgez_to_machinecode(arguments);
	}else if(op == "bne"){
		output = convert_bne_to_machinecode(arguments);
	}else if(op == "j"){
		output = convert_j_to_machinecode(arguments);
	}else if(op == "jal"){
		output = convert_jal_to_machinecode(arguments);
	}else if(op == "jr"){
		output = convert_jr_to_machinecode(arguments);
	}else if(op == "lb"){
		output = convert_lb_to_machinecode(arguments);
	}else if(op == "lw"){
		output = convert_lw_to_machinecode(arguments);
	}else if(op == "noop"){
		output = convert_noop_to_machinecode();
	}else if(op == "or"){
		output = convert_or_to_machinecode(arguments);
	}else if(op == "sb"){
		output = convert_sb_to_machinecode(arguments);
	}else if(op == "sw"){
		output = convert_sw_to_machinecode(arguments);
	}else if(op == "syscall"){
		output = convert_syscall_to_machinecode();
	} 




	return output;
}


int main(int argc, char *argv[]){
	if(argc < 2){
		cout<<"Please add file containing assembly code"<<endl;
		return 0;
	}
	string filename = argv[1];
	ifstream file (filename);
	if(!file){
		cout<<"Unable to open file"<<endl;
		return 0;
	}
	string sent;
	while (getline(file, sent)){
		uint32_t instruction = convert_to_machinecode(sent);
		cout<<instruction<<endl;
	}
	return 0;
}