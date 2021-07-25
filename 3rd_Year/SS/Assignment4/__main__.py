# Required libraries
import argparse

# In built Data Structures
from register import RegList
from condition_code import CCList
from assembler_directive import ADList
from declarative_statement import DLList
from imperative_statement import ISList

# Other Data Structures
from symbol import Symbol
from pool import Pool
from literal import Literal


#In built Data Structures
CCList = CCList()
ADList = ADList()
DLList = DLList()
ISList = ISList()
RegList = RegList()

# Program Counter
PC = 0

# Stack for Origin PC 
PCLIST = []

# Literal List, Symbol List, Pool List
LLIST = []
SLIST = []
PLIST = []



def find_literal_by_name(name):
    for i in range(len(LLIST)):
        if LLIST[i].name==name:
            return i
    return None

def find_symbol_by_name(name):
    for i in range(len(SLIST)):
        if SLIST[i].name==name:
            return i
    return None

# END Command is used
SAFE_END = False

if __name__ == '__main__':

    # Parsing FilePath as Arguments
    parser = argparse.ArgumentParser(description="Generates Target Code for Assembly Source Code")
    parser.add_argument('file_path',metavar='filePath',help='File Path to Assembly Source Code')
    args = parser.parse_args()
    file_path = args.file_path


    # Parsing the File
    try:
        with open(file_path,'r') as f:
            lines = f.readlines() # lines = List of lines in file f
            line_count = 0
            for line in lines:
                line_count = line_count + 1

                line = line.upper().replace('\n','').replace('\t','').replace(' ','').replace(',','')
                decoded_line = line.split('-')
                if len(decoded_line)!=4:
                    raise Exception('4 Parameters required in each assembly statement!')
                
                print(decoded_line)
                label = decoded_line[0]
                operator = decoded_line[1]
                operand1 = decoded_line[2]
                operand2 = decoded_line[3]

                # Parsing Label
                if(label!=''):
                    idx = find_symbol_by_name(label)
                    if idx is None:
                        sym = Symbol(label)
                        sym.address = PC
                        SLIST.append(sym)
                    else:
                        pass
                
                # Parsing Operator
                if ISList.find_is_by_mnemonic(operator) is not None:

                    IS = ISList.find_is_by_mnemonic(operator)

                    # Checking Parameter Count
                    params = IS.params
                    if(params==0 and (operand1!='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==1 and (operand1=='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==2 and (operand1=='' or operand2=='')):
                            raise Exception('Invalid Operand Count for Operator!')

                    PC = PC + 1
                elif ADList.find_ad_by_mnemonic(operator) is not None:

                    AD = ADList.find_ad_by_mnemonic(operator)

                    # Checking Parameter Count
                    params = AD.params
                    if(params==0 and (operand1!='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==1 and (operand1=='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==2 and (operand1=='' or operand2=='')):
                            raise Exception('Invalid Operand Count for Operator!')

                    if AD.mnemonicOpcode=='START':
                        PC = int(operand1)
                    elif AD.mnemonicOpcode=='ORIGIN':
                        PCLIST.append(PC)
                        PC = int(operand1)
                    elif AD.mnemonicOpcode=='STOP':
                        if len(PCLIST<=0):
                            raise Exception('Invalid Operator! STOP called before ORIGIN!')
                        PC = PCLIST[len(PCLIST)-1]
                        PCLIST.pop(len(PCLIST)-1)
                    elif AD.mnemonicOpcode=='EQU':
                        idx = find_symbol_by_name(label)                            
                        SLIST[idx].linked = True
                        SLIST[idx].link = operand1
                    elif AD.mnemonicOpcode=='LTORG':
                        literal_pointer = -1

                        for i in range(len(LLIST)):
                            if(LLIST[i].address==-1):
                                if literal_pointer==-1:
                                    literal_pointer = i
                                LLIST[i].address = PC
                                PC = PC + 1
                        
                        if literal_pointer!=-1:
                            PLIST.append(Pool(literal_pointer))
                    elif AD.mnemonicOpcode=='END':
                        SAFE_END = True
                        literal_pointer = -1

                        for i in range(len(LLIST)):
                            if(LLIST[i].address==-1):
                                if literal_pointer==-1:
                                    literal_pointer = i
                                LLIST[i].address = PC
                                PC = PC + 1
                        
                        if literal_pointer!=-1:
                            PLIST.append(Pool(literal_pointer))
                elif DLList.find_dl_by_mnemonic(operator) is not None:
                    
                    DL = DLList.find_dl_by_mnemonic(operator)
                    # Checking Parameter Count
                    params = DL.params
                    if(params==0 and (operand1!='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==1 and (operand1=='' or operand2!='')):
                            raise Exception('Invalid Operand Count for Operator!')
                    elif(params==2 and (operand1=='' or operand2=='')):
                            raise Exception('Invalid Operand Count for Operator!')

                    if DL.mnemonicOpcode=='DS':
                        length = int(operand1)
                        idx = find_symbol_by_name(label)
                        if SLIST[idx].address!=-1:
                            raise Exception('Duplicate Symbol Declaration!')
                        SLIST[idx].address = PC
                        SLIST[idx].length = length
                        PC = PC + length
                    elif DL.mnemonicOpcode=='DC':
                        value = int(operand1)
                        idx = find_symbol_by_name(label)
                        if SLIST[idx].address!=-1:
                            raise Exception('Duplicate Symbol Declaration!')
                        SLIST[idx].address = PC
                        SLIST[idx].value = value
                        SLIST[idx].length = 1
                        PC = PC + 1
                else:
                    raise Exception('Invalid Operator! Operator not recognized!')
                
                # Parsing Operand1
                if operand1=='':
                    pass
                elif RegList.find_reg_by_mnemonic(operand1) is not None:
                    pass
                else:
                    # TODO Sanitize Operand (Not Required by the Assignment)
                    if operand1.startswith('='):
                        if find_literal_by_name(operand1) is None:
                            LLIST.append(Literal(operand1))
                    else:
                        try:
                            value = int(operand1)
                        except:
                            if find_symbol_by_name(operand1) is None:
                                SLIST.append(Symbol(operand1))

                # Parsing Operand2
                if operand2=='':
                    pass
                elif RegList.find_reg_by_mnemonic(operand2) is not None:
                    pass
                else:
                    # TODO Sanitize Operand (Not Required by the Assignment)
                    if operand2.startswith('='):
                        if find_literal_by_name(operand2) is None:
                            LLIST.append(Literal(operand2))
                    else:    
                        try:
                            value = int(operand2)
                        except:
                            if find_symbol_by_name(operand2) is None:
                                SLIST.append(Symbol(operand2))                  
        

        if SAFE_END!=True:
            raise Exception('Program not Ended with END Statement!')
        
        for i in range(len(SLIST)):
            if SLIST[i].linked:
                idx = find_symbol_by_name(SLIST[i].link)
                SLIST[i].value = SLIST[idx].address

    except Exception as e:
        print('Error in Line',line_count,':',end=' ')
        print(e)
        exit(0)
            

print('')
print('')
print('SYMBOL TABLE')
print('Sr. No\t\tName\t\tAddress\t\tValue\t\tLength\t\t')

for i in range(len(SLIST)):
    print(i+1,end='\t\t')
    print(SLIST[i].name,end='\t\t')
    print(SLIST[i].address,end='\t\t')
    print(SLIST[i].value,end='\t\t')
    print(SLIST[i].length)


print('')
print('')
print('LITERAL TABLE')
print('Sr. No\t\tName\t\tAddress')

for i in range(len(LLIST)):
    print(i+1,end='\t\t')
    print(LLIST[i].name,end='\t\t')
    print(LLIST[i].address)


print('')
print('')
print('POOL TABLE')
print('Sr. No\t\tLiteral Pointer')

for i in range(len(PLIST)):
    print(i+1,end='\t\t')
    print(PLIST[i].literal_pointer+1)


print('')
print('')
print('Variant 1 Intermediate Code')
with open(file_path,'r') as f:
    lines = f.readlines() # lines = List of lines in file f
    line_count = 0
    for line in lines:
        line_count = line_count + 1

        line = line.upper().replace('\n','').replace('\t','').replace(' ','').replace(',','')
        decoded_line = line.split('-')
        if len(decoded_line)!=4:
            raise Exception('4 Parameters required in each assembly statement!')
        
        label = decoded_line[0]
        operator = decoded_line[1]
        operand1 = decoded_line[2]
        operand2 = decoded_line[3]
        
        
        if ISList.find_is_by_mnemonic(operator) is not None:
            IS = ISList.find_is_by_mnemonic(operator)
            print('('+IS.tag+','+IS.numericOpcode+')',end='\t\t')    
        elif ADList.find_ad_by_mnemonic(operator) is not None:
            AD = ADList.find_ad_by_mnemonic(operator)                
            print('('+AD.tag+','+AD.numericOpcode+')',end='\t\t')            
        elif DLList.find_dl_by_mnemonic(operator) is not None:            
            DL = DLList.find_dl_by_mnemonic(operator)
            print('('+DL.tag+','+DL.numericOpcode+')',end='\t\t')
        elif CCList.find_cc_by_mnemonic(operator) is not None:       
            CC = CCList.find_dl_by_mnemonic(operator)
            print('('+CC.numericOpcode+')',end='\t\t')  
        

        if operand1=='':
            pass
        elif RegList.find_reg_by_mnemonic(operand1) is not None:
            REG = RegList.find_reg_by_mnemonic(operand1)
            print('('+REG.tag+')',end='\t\t')
        else:
            if operand1.startswith('='):
                idx = find_literal_by_name(operand1)
                print('(L,'+str(idx+1)+')',end='\t\t')
            else:
                try:
                    value = int(operand1)
                    print('(C,'+operand2+')',end='\t\t')
                except:                    
                    idx =  find_symbol_by_name(operand1)  
                    print('(S,'+str(idx+1)+')',end='\t\t')  


        if operand2=='':
            pass
        elif RegList.find_reg_by_mnemonic(operand2) is not None:
            REG = RegList.find_reg_by_mnemonic(operand1)
            print('('+REG.tag+')',end=' ')
        else:
            if operand2.startswith('='):
                idx = find_literal_by_name(operand2)
                print('(L,'+str(idx+1)+')',end='\t\t')
            else:    
                try:
                    value = int(operand2)
                    print('(C,'+operand2+')',end='\t\t')
                except:
                    idx =  find_symbol_by_name(operand2)  
                    print('(S,'+str(idx+1)+')',end='\t\t')          
        print('')


print('')
print('')
print('Variant 2 Intermediate Code')
with open(file_path,'r') as f:
    lines = f.readlines() # lines = List of lines in file f
    line_count = 0
    for line in lines:
        line_count = line_count + 1

        line = line.upper().replace('\n','').replace('\t','').replace(' ','').replace(',','')
        decoded_line = line.split('-')
        if len(decoded_line)!=4:
            raise Exception('4 Parameters required in each assembly statement!')
        
        label = decoded_line[0]
        operator = decoded_line[1]
        operand1 = decoded_line[2]
        operand2 = decoded_line[3]
        
        
        if ISList.find_is_by_mnemonic(operator) is not None:
            IS = ISList.find_is_by_mnemonic(operator)
            print('('+IS.tag+','+IS.numericOpcode+')',end='\t\t')    
        elif ADList.find_ad_by_mnemonic(operator) is not None:
            AD = ADList.find_ad_by_mnemonic(operator)                
            print('('+AD.tag+','+AD.numericOpcode+')',end='\t\t')            
        elif DLList.find_dl_by_mnemonic(operator) is not None:            
            DL = DLList.find_dl_by_mnemonic(operator)
            print('('+DL.tag+','+DL.numericOpcode+')',end='\t\t')       
        elif CCList.find_cc_by_mnemonic(operator) is not None:       
            CC = CCList.find_dl_by_mnemonic(operator)
            print('('+CC.numericOpcode+')',end='\t\t')  

        

        if operand1=='':
            pass
        elif RegList.find_reg_by_mnemonic(operand1) is not None:
            REG = RegList.find_reg_by_mnemonic(operand1)
            print(REG.mnemonicOpcode,end='\t\t')
        else:
            if operand1.startswith('='):
                idx = find_literal_by_name(operand1)
                print('(L,'+str(idx+1)+')',end='\t\t')
            else:
                try:
                    value = int(operand1)
                    print('(C,'+operand1+')',end='\t\t')
                except:                    
                    idx =  find_symbol_by_name(operand1)  
                    print(SLIST[idx].name,end='\t\t')  


        if operand2=='':
            pass
        elif RegList.find_reg_by_mnemonic(operand2) is not None:
            REG = RegList.find_reg_by_mnemonic(operand1)
            print(REG.mnemonicOpcode,end='\t\t')
        else:
            if operand2.startswith('='):
                idx = find_literal_by_name(operand2)
                print('(L,'+str(idx+1)+')',end='\t\t')
            else:    
                try:
                    value = int(operand2)
                    print('(C,'+operand2+')',end='\t\t')
                except:
                    idx =  find_symbol_by_name(operand2)   
                    print(SLIST[idx].name,end='\t\t')       
        print('')
    


    
