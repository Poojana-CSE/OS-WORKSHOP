class VirtualMachine:
    def __init__(self, tot_mem):
        self.tot_mem = tot_mem
        self.used_mem = 0
    
    def allocate(self, amt):
        if(self.used_mem + amt <= self.tot_mem):
            self.used_mem += amt
            print("Memory is allocated")
        else:
            print("Memory is not allocated")

    def balloon(self, amt):
        if(amt <= self.used_mem):
            self.used_mem -= amt
            print("Memory is released and it can be reused!")
        else:
            print("Balloon Is failed!")

vm = VirtualMachine(1000)
vm.allocate(600)
vm.balloon(200)
vm.balloon(500)