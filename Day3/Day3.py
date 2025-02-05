My_list=[]
while 1:
    check = int(input("Enter '1' for add items \n Enter '2' to remove an items \n enter '3' to Display an items\n Enter '4' to clears the list \n enter '5' to exit\n"))
    if check ==1 :
        x=input("please Enter your item\n")
        y=My_list.append(x)
    elif check == 2 :
        x = str(input("please Enter your name's items to remove\n"))
        if x in My_list:
            My_list.remove(x)
        else:
            print("erorr")
    elif check == 3 :
        print(f"your items is {x}\n")
        print(My_list)
    elif check == 4 :
        My_list.clear()
    elif check == 5:
        break
    else:
        continue