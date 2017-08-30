a = input("Enter a string: ")           #By H.D
b=a
print ("Entered string: "+a)
r = int(input("Enter the rotation places: "))     #Concenate the spliced string from the indexed position to the last and the
print ("After rotating left: "+a[r:] + a[:r])    #string from the first to the indexed position and vice versa for opposite rotation
print ("After rotating right: "+a[-r:] + a[:-r])
