# Docker Netcat Communication Setup

This setup demonstrates communication between two Docker containers (client and server) using Netcat. The client sends data to the server over a custom bridge network.

## 1. How to Build the Docker Images

To build the Docker images for the client and the server:

1. Open a terminal and navigate to the project root directory (where `images` and `scripts` are located).

2. Build the Docker images for both the client and the server:

   - **Build the client image**:
     ```bash
     docker build -f images/Dockerfile.client -t client-image .
     ```

   - **Build the server image**:
     ```bash
     docker build -f images/Dockerfile.server -t server-image .
     ```

This will create two Docker images: `client-image` and `server-image`, which will be used to run the client and server containers respectively.

## 2. How to Create the Custom Network

   - **To allow communication between the containers, create a custom bridge network**:
     ```bash
     docker network create --driver bridge my_custom_network
     ```
 
## 3. How to Run the Containers

   - **Run the server container, ensuring it is connected 
     to the my_custom_network network**:
     ```bash
     docker run -d --name server --network my_custom_network -v $(pwd):/usr/src/app server-image
     ```

   - **Run the client container similarly 
       connected to the same network (my_custom_network)**:
     ```bash
     docker run -d --name client --network my_custom_network -v $(pwd):/usr/src/app client-image
     ```  

## 4. Verify the Containers Are Running

   - **To check if both containers are running**:
       Run the client container similarly connected to the same network (my_custom_network):
     ```bash
     docker ps
     ```

## 5. Commands to Verify Containers Connectivity Between Containers

   - **Exec into the client container**:
       Run the client container similarly connected to the same network (my_custom_network):
     ```bash
     docker exec -it client sh
     ```
   
   - **Test if the client can ping the server**:
    Run the client container similarly connected to the same network (my_custom_network):
     ```bash
     ping server
     ```


## 6. Commands to Verify Netcat Scripts

   - **Exec into the server container**:
       Run the client container similarly connected to the same network (my_custom_network):
     ```bash
     docker exec -it server sh
     ```
   
   - **To verify that the netcat communication works, follow these steps**:
       Run the server script:
     ```bash
     ./server.sh
     ```

   - **Exec into the client container**:
     ```bash
     docker exec -it client sh
     ```

   - **Run the client script:**:
     ```bash
     ./client.sh
     ```
