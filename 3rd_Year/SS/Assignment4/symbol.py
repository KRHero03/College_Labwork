class Symbol:
    
    def __init__(self,name):
        self.name = name
        self.address = -1
        self.length = -1
        self.value = -1
        self.linked = False
        self.link = ""
    