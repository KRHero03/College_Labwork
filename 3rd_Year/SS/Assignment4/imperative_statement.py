class ImperativeStatement:
    def __init__(self, mO, nO,p):
        self.mnemonicOpcode = mO
        self.numericOpcode = nO
        self.tag = "IS"
        self.params = p

class ISList:
    def __init__(self):

        self.list = [
            ImperativeStatement("STOP", "00",0), 
            ImperativeStatement("ADD", "01",2),
            ImperativeStatement("SUB", "02",2), 
            ImperativeStatement("MUL", "03",2), 
            ImperativeStatement("MOVER", "04",2), 
            ImperativeStatement("MOVEM", "05",2), 
            ImperativeStatement("COMP", "06",2), 
            ImperativeStatement("BC", "07",2), 
            ImperativeStatement("DIV", "08",2), 
            ImperativeStatement("READ", "09",1), 
            ImperativeStatement("PRINT", "10",1), 
        ]
    
    def find_is_by_mnemonic(self,mO):
        for IS in self.list:
            if IS.mnemonicOpcode==mO:
                return IS
        return None
    
    def find_is_by_numeric(self,nO):
        for IS in self.list:
            if IS.numericOpcode==nO:
                return IS
        return None
