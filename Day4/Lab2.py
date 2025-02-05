import os
import socket

# Function to scan a range of ports on a given IP
def scan_port(ip, start_port, end_port):
    for port in range(start_port, end_port + 1):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
                sock.settimeout(1)
                result = sock.connect_ex((ip, port))
                if result == 0:
                    print(f"Port {port} is open on {ip}")
        except Exception as e:
            print(f"Error scanning port {port}: {e}")

# Function to create or append to a file
def create_file(file_path, data):
    try:
        with open(file_path, 'a') as file:
            file.write(data + '\n')
        print(f"Data written to file: {file_path}")
    except Exception as e:
        print(f"Error writing to file: {e}")

# Function to scan a range of IP addresses
def scan_ip_range(start_ip, end_ip):
    online_ips = []
    base_ip = "192.168.174."
    for i in range(start_ip, end_ip + 1):
        ip = base_ip + str(i)
        response = os.system(f"ping {ip} -n 1 -w 100 > nul 2>&1")
        if response == 0:
            print(f"Host {ip} is online")
            online_ips.append(ip)
            create_file("E:/python/Abdelrhman/online_ips.txt", ip)
        else:
            print(f"Host {ip} is offline")
    return online_ips

# Main program
if __name__ == "__main__":
    # Get IP range from user
    start_ip = int(input("Enter the starting IP range (192.168.174.x): "))
    end_ip = int(input("Enter the ending IP range (192.168.174.y): "))

    # Scan IP range
    online_ips = scan_ip_range(start_ip, end_ip)

    if online_ips:
        # Get port range from user
        start_port = int(input("Enter the starting port range: "))
        end_port = int(input("Enter the ending port range: "))

        # Scan ports on the first online IP
        target_ip = online_ips[0]
        print(f"Scanning ports on {target_ip}...")
        scan_port(target_ip, start_port, end_port)
    else:
        print("No online hosts found.")
