#!/usr/bin/env python3
"""
Simple TCP client stub - connects to a server, reads response, and prints it.
"""

import socket
import sys

# Configuration
HOST = "127.0.0.1"  # Server hostname or IP
PORT = 9999         # Server port

def main():
    try:
        # Create a TCP socket
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
            # Connect to the server
            print(f"[*] Connecting to {HOST}:{PORT}...")
            sock.connect((HOST, PORT))
            print("[+] Connected!")

            # Receive data from the server
            data = sock.recv(4096)
            
            # Print the response
            print(f"[+] Received: {data.decode('utf-8', errors='replace')}")

    except ConnectionRefusedError:
        print(f"[-] Connection refused to {HOST}:{PORT}")
        sys.exit(1)
    except Exception as e:
        print(f"[-] Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()

