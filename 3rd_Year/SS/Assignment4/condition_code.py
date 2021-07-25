class ConditionCode:

    def __init__(self,mO,nO):
        self.mnemonicOpcode = mO
        self.numericOpcode = nO



class CCList:
    def __init__(self):

        self.list = [
            ConditionCode("LT", "01"), 
            ConditionCode("LE", "02"), 
            ConditionCode("EQ", "03"), 
            ConditionCode("GT", "04"), 
            ConditionCode("GE", "05"), 
            ConditionCode("ANY", "06"), 
        ]
    
    def find_cc_by_mnemonic(self,mO):
        for CC in self.list:
            if CC.mnemonicOpcode==mO:
                return CC
        return None
    
    def find_cc_by_numeric(self,nO):
        for CC in self.list:
            if CC.numericOpcode==nO:
                return CC
        return None