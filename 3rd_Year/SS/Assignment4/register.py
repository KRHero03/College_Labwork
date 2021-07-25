class Register:

    def __init__(self,mO,nO):
        self.mnemonicOpcode = mO
        self.numericOpcode = nO
        self.tag = nO


class RegList:
    def __init__(self):

        self.list = [
            Register("AREG", "01"), 
            Register("BREG", "02"), 
            Register("CREG", "03"), 
            Register("DREG", "04"), 
        ]
    
    def find_reg_by_mnemonic(self,mO):
        for REG in self.list:
            if REG.mnemonicOpcode==mO:
                return REG
        return None
    
    def find_reg_by_numeric(self,nO):
        for REG in self.list:
            if REG.numericOpcode==nO:
                return REG
        return None