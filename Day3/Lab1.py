import os

# Function to open Facebook in Chrome
def open_facebook():
    os.system('start chrome https://web.facebook.com/')
    print("Facebook opened in Chrome.")

# Function to create a directory and write to a file
def create_directory_and_file():
    file_path = r"E:/python/ahmed"
    
    # Create a new directory
    if not os.path.exists(file_path):
        os.mkdir(file_path)
        print(f"Directory created: {file_path}")
    else:
        print(f"Directory already exists: {file_path}")
    
    # Define the file path
    file_path = r"E:/python/ahmed/file_path.txt"
    
    # Write to the file
    with open(file_path, 'w') as file:
        file.write("hi python")
    print(f"File created and written: {file_path}")

# Function to print a star pattern
def print_star_pattern():
    number = int(input("Please enter the number of rows for the star pattern: "))
    
    # Print the decreasing pattern
    for i in range(number, 0, -1):
        print('*' * i)
    
    # Print the increasing pattern
    for i in range(2, number + 1):
        print('*' * i)

# Function to check if a number is prime
def check_prime():
    number = int(input("Enter a number: "))
    
    # Check if the number is valid
    if number <= 0:
        print("Error: The number is zero or negative.")
    else:
        # Check if the number is prime
        is_prime = True
        for i in range(2, int(number**0.5) + 1):
            if number % i == 0:
                is_prime = False
                break
        # Print the result
        if is_prime:
            print("The number is prime.")
        else:
            print("The number is not prime.")

# Function for string formatting and list/tuple manipulation
def string_and_list_operations():
    # Define first and last names
    first_name = "abdelrhman"
    last_name = "hamed"
    
    # Format the full name using f-strings
    full_name = f"Hello {first_name}, your full name is {first_name} {last_name}."
    print(full_name)
    
    # Manipulate a list
    My_list = [1, 2, 3, 4]
    My_list.append(5)
    print("Updated List:", My_list)
    
    # Convert a tuple to a list, remove an element, and convert it back to a tuple
    y = (1, 3, 5)
    x = list(y)
    x.remove(5)
    print("List after removal:", x)
    z = tuple(x)
    print("Tuple after conversion:", z)

# Main function to run all tasks
def main():
    while True:
        print("\nChoose an option:")
        print("1. Open Facebook in Chrome")
        print("2. Create a directory and write to a file")
        print("3. Print a star pattern")
        print("4. Check if a number is prime")
        print("5. Perform string and list operations")
        print("6. Exit")
        
        choice = input("Enter your choice (1-6): ")
        
        if choice == '1':
            open_facebook()
        elif choice == '2':
            create_directory_and_file()
        elif choice == '3':
            print_star_pattern()
        elif choice == '4':
            check_prime()
        elif choice == '5':
            string_and_list_operations()
        elif choice == '6':
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

# Run the main function
if __name__ == "__main__":
    main()