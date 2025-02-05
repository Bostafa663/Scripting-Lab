import os
drives = ["C:\\" , "E:\\","F:\\"]
filename = input("Please input your file name to research : ")

file_found =0
for drive in drives :
    print(f"searching in {drive}....")
    for partation , dirs , files in os.walk(drive):
        if filename in files :
            file_path = os.path.join(partation,filename)
            print("file found at : ",file_path)
            file_found = 1
            break
    if file_found :
        break
if file_found == 0 :
    print("file not found")


