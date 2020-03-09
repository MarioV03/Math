def GCD(a, b):
    if(a==b):
        return a
    elif (a>b):
        return GCD(a-b, b)
    else:
        return GCD(b-a, a)

def LCM(a, b):
    return int(a*b/GCD(a, b))

def main():
    
    IfContinue = True
    
    while(IfContinue==True):
        a = int(input("Input first number: "))
        b = int(input("Input secind number: "))
        
        print("\nGCD = ", GCD(a, b), "\nLCM = ", LCM(a, b))

        if(input("\nExit? (1 - YES; 0 - NO)\n")=="1"):
            IfContinue = False
        print("\n\n")


#EXECUTE
main()
