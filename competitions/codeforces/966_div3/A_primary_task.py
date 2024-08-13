def main():
    a = input()
    if a[:2] != '10':
        print("no")
        return 
    if a[2:] and int(a[2:]) >= 2 and len(a[2:]) == len(str(int(a[2:]))):
        print("yes")
        return 
    print("no")
    
    
for t in range(int(input())):
    main()