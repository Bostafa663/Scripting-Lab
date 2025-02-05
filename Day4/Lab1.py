while True:
    import re
    password = input("Please Enter your password: ")
    
    # Check the length of the password
    if len(password) <= 8:
        print("Your password is less than 8 characters.")
        continue
    
    # Check for at least one lowercase letter
    if not any(c.islower() for c in password):
        print("Your password doesn't have a lowercase character.")
        continue
    
    # Check for at least one uppercase letter
    if not any(c.isupper() for c in password):
        print("Your password doesn't have an uppercase character.")
        continue
    
    # Check for at least one digit
    if not re.search("[0-9]", password):
        print("Your password doesn't have a digit.")
        continue
    
    # Check for at least one special character
    if not re.search("[*~!@#$%^&*()_+}{\"}]", password):
        print("Your password doesn't have a special character.")
        continue
    
    # If all checks pass, the password is valid
    print("Valid Password")
    break