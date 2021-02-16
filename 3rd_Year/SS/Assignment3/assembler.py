import argparse

# Machine Opcode Table
MOT = {"MOVER":1,"MOVEM":2,"ADD":3,"SUB":4,"MULT":5,"DIV":6,"SIC":7,"COMP":8,"PRINT":9,"READ":10}

# Pseudo Operation Table
POT = {"START":1,"END":2,"EQU":3,"ORIGIN":4,"LTORG":5}

DL = {"DS":1,"DC":2}

# Registers
REGISTERS = {"AREG":1,"BREG":2,"CREG":3,"DREG":4}

# Parsing FilePath as Arguments
parser = argparse.ArgumentParser(description="Generates Target Code for Assembly Source Code")
parser.add_argument('file_path',metavar='filePath',help='File Path to Assembly Source Code')
args = parser.parse_args()
file_path = args.file_path

# Table of Incomplete Instructions
TII = {}

# Symbol Table
ST = {}

# Pool Table
PT = {}

# Literal Table
LT = {}

# Program Counter
PC = 0

# Target Code
TC = {}

# Parsing the File
try:
    with open(file_path,'r') as f:
        lines = f.readlines() # lines = List of lines in file f
        line_count = 1
        for line in lines:
            line = line.strip().upper()
            operator = line.split(' ')[0]
            if POT.get(operator,-1)!=-1:
                line_code = []
                operands = line.split(' ')[1].split(',')
                operands = [a.strip() for a in operands]
                if REGISTERS.get(operands[0],-1)==-1:
                    raise "Invalid Instruction Format! Expected Register!"
                if LT.get(operands[1],-1)==-1:
                    LT[operands[1]]={"Address":"-1","Value":int(operands[1][2:-1])}
                    TII[PC]=operands[1]
                line_code.append(PC)
                line_code.append(operator)
                line_code.append(operands[0])
                line_code.append(operands[1])
                PC = PC + 1

            elif MOT.get(operator,-1)!=-1:
                if operator=="START":
                    operand = int(line.split(' ')[1])
                    line_code.append(PC)
                    line_code.append(operator)
                    line_code.append(operands)
                    if operand<PC:
                        raise "Operand cannot be less than current Program Counter!"
                    PC = operand
                elif operator=="ORIGIN":
                    operand = int(line.split(' ')[1])
                    line_code.append(PC)
                    line_code.append(operator)
                    line_code.append(operands)
                    if operand<PC:
                        raise "Operand cannot be less than current Program Counter!"
                    PC = operand
                elif operator=="LTORG":
                    for (key,val) in TII.items():
                        if(LT[val]["Address"]!=-1):
                            LT[val]["Address"] = PC
                            line_code.append(PC)
                            line_code.append(LT[val]["Value"])
                            PC = PC + 1
                elif operator=="END":
                    for (key,val) in TII.items():
                        if(LT[val]["Address"]!=-1):
                            LT[val]["Address"] = PC
                            line_code.append(PC)
                            line_code.append(LT[val]["Value"])
                            PC = PC + 1
                elif operator=="EQU":
                    line_code.append(PC)
                    operand = line.split(' ')[1]


            else:
            
            line_count = line_count + 1
        f.close()

except Exception as e:
    print('Error in Line',line_count,':',end=' ')
    print(e)