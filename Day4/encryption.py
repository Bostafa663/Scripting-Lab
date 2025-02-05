from cryptography.fernet import Fernet
import os

def generate_key():
    key = Fernet.generate_key()
    with open("key.txt", "wb") as key_file:
        key_file.write(key)
    return key

def encrypt_file(key, file_path):
    fernet = Fernet(key)
    with open(file_path, "rb") as file:
        data = file.read()
    encrypted_data = fernet.encrypt(data)
    encrypted_path = os.path.splitext(file_path)[0] + ".encrypted"
    with open(encrypted_path, "wb") as enc_file:
        enc_file.write(encrypted_data)
    os.remove(file_path)
    print(f"File '{file_path}' encrypted as '{encrypted_path}'.")
    return encrypted_path

def decrypt_file(key, encrypted_path):
    fernet = Fernet(key)
    with open(encrypted_path, "rb") as enc_file:
        encrypted_data = enc_file.read()
    data = fernet.decrypt(encrypted_data)
    decrypted_path = os.path.splitext(encrypted_path)[0] + ".decrypted"
    with open(decrypted_path, "wb") as dec_file:
        dec_file.write(data)
    print(f"File '{encrypted_path}' decrypted as '{decrypted_path}'.")

key = generate_key()

while True:
    print("Operations:\n1. Encrypt a file\n2. Decrypt a file\n3. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        file_path = input("Enter the file path to encrypt: ")
        encrypt_file(key, file_path)
    elif choice == "2":
        encrypted_path = input("Enter the file path to decrypt: ")
        decrypt_file(key, encrypted_path)
    elif choice == "3":
        break
    else:
        print("Invalid choice. Please enter 1, 2, or 3.")