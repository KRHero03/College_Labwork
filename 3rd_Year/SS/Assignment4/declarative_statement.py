class DeclarativeStatement:

    def __init__(self,mO,nO,p):
        self.mnemonicOpcode = mO
        self.numericOpcode = nO
        self.tag = "DL"
        self.params = p


class DLList:
    def __init__(self):

        self.list = [
            DeclarativeStatement("DS", "01",1), 
            DeclarativeStatement("DC", "02",1), 
        ]
    
    def find_dl_by_mnemonic(self,mO):
        for DL in self.list:
            if DL.mnemonicOpcode==mO:
                return DL
        return None
    
    def find_dl_by_numeric(self,nO):
        for DL in self.list:
            if DL.numericOpcode==nO:
                return DL
        return None