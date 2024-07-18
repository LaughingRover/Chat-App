# Simple Chat Application (Single Client-Server Model)

A basic chat application that allows users to communicate in real-time, including features like creating user profiles, sending messages, and receiving notifications.

## Road Map

### Milestone 1:

1. Protocol Design: Designing communication protocols.

   - Define Message Types: Determine the types of messages that need to be
     exchanged (e.g., login, message, logout).
   - Message Format: Decide on the structure of each message type
     (e.g., headers, delimiters, encoding).
   - Error Handling: Specify how errors will be communicated and handled.
   - State Management: Outline how the state will be managed
     (e.g., connection states, session management).
2. Setting Up Client-Server Communication: Implement the basic communication
   mechanism using the designed protocol

   - Setting up server and client communication using sockets
   - Implement message parsing and display.

E.g

	server						|	client
	------------------------------------------------------------------------------------------
	Open socket
	Start listening
								Client will create a socket
								Try to connect to server
	Server will accept or reject connection
	Server will wait for any data in recv
								If accepted, send a string
								Wait for the response from server
	Server will recv the string and print
	The user will type a response and
	send it to the client and wait
								Accept and send again
	Accept and send again
	...
	...
	...
								Client will close when its done.
	Server will wait for some other client
	or it may close.

### Milestone 2:

Handle multiple clients (e.g., using threading or asynchronous I/O)

### Milestone 3:

Handling Multiple Clients with Error Handling and Robustness

Purpose: Ensure that the application can handle multiple clients efficiently and robustly.

Steps:

- Concurrency Errors: Handle errors related to threading or asynchronous I/O.
- Resource Management: Manage resources (e.g., file handles, memory)
  efficiently to avoid leaks and exhaustion.

### Milestone 4:

Robustness Considerations

- Scalability: Implement strategies to handle high loads and avoid server
  overload.
- Graceful Degradation: Ensure the system continues to operate at reduced
  functionality if some parts fail.
- Redundancy: Implement redundancy where necessary, such as backup servers or
  additional threads to handle peak loads.
- Logging and Monitoring: Implement comprehensive logging and monitoring to
  detect and diagnose issues in real-time.
- Security: Implement security measures to handle and recover from malicious
  attacks or unauthorized access.
