
class AssemblerDirective:
    
    def __init__(self,mO,nO,p):
        self.mnemonicOpcode = mO
        self.numericOpcode = nO
        self.tag = "AD"
        self.params = p


class ADList:
    def __init__(self):

        self.list = [
            AssemblerDirective("START", "01",1), 
            AssemblerDirective("END", "02",0), 
            AssemblerDirective("ORIGIN", "03",1), 
            AssemblerDirective("EQU", "04",1), 
            AssemblerDirective("LTORG", "05",0), 
        ]
    
    def find_ad_by_mnemonic(self,mO):
        for AD in self.list:
            if AD.mnemonicOpcode==mO:
                return AD
        return None
    
    def find_ad_by_numeric(self,nO):
        for AD in self.list:
            if AD.numericOpcode==nO:
                return AD
        return None