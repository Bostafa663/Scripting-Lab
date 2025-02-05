# Initialize an empty list to store items
My_list = []

# Start an infinite loop to keep the program running until the user chooses to exit
while True:
    # Display the menu options to the user
    check = int(input(
        "Enter '1' to add items\n"
        "Enter '2' to remove an item\n"
        "Enter '3' to display all items\n"
        "Enter '4' to clear the list\n"
        "Enter '5' to exit\n"
    ))

    # Option 1: Add an item to the list
    if check == 1:
        x = input("Please enter your item: ")  # Prompt the user to enter an item
        My_list.append(x)  # Add the item to the list
        print(f"'{x}' has been added to the list.\n")

    # Option 2: Remove an item from the list
    elif check == 2:
        x = input("Please enter the item to remove: ")  # Prompt the user to enter the item to remove
        if x in My_list:  # Check if the item exists in the list
            My_list.remove(x)  # Remove the item from the list
            print(f"'{x}' has been removed from the list.\n")
        else:
            print("Error: Item not found in the list.\n")  # Display an error if the item is not found

    # Option 3: Display all items in the list
    elif check == 3:
        if My_list:  # Check if the list is not empty
            print("Your items are:")
            for item in My_list:  # Loop through the list and print each item
                print(f"- {item}")
        else:
            print("The list is empty.\n")  # Display a message if the list is empty

    # Option 4: Clear the entire list
    elif check == 4:
        My_list.clear()  # Clear all items from the list
        print("The list has been cleared.\n")

    # Option 5: Exit the program
    elif check == 5:
        print("Exiting the program. Goodbye!")  # Display a goodbye message
        break  # Exit the loop and end the program

    # Handle invalid input
    else:
        print("Invalid option. Please try again.\n")  # Display an error for invalid input