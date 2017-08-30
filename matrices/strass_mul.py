temp=0          #By H.D
a=[]

print ("Enter the matrix elements of Mat_A and Mat_B: ")
print ("Entering a character will terminate the entry of values for the matices")
while(type(temp)==int):
    try:
        temp= int(input());
        a.append(temp)

    except:                 #Strassen's multiplication with time complexity of O(n2)
        p1=a[0]*(a[5]-a[7]);
        p2=a[7]*(a[0]+a[1]);
        p3=a[4]*(a[2]+a[3]);
        p4=a[3]*(a[6]-a[4]);
        p5=(a[0]+a[3])*(a[4]+a[7]);
        p6=(a[1]-a[3])*(a[6]+a[7]);
        p7=(a[0]-a[2])*(a[4]+a[5]);
        print ("Strassen's Multiplication: ")
        print (str(p6+p5+p4-p2)+"\t"+str(p1+p2))
        print (str(p3+p4)+"\t"+str(p1+p5-p3-p7))
        break
