
![Minitalk](https://github.com/user-attachments/assets/df151b9c-8e50-45af-a287-ec98e67bd598)

## Description

The minitalk project is about communication between server and client.
We need to be able to send messages with the client and display them with the server using the SIGUSR1 and SIGUSR2 signals.

## Usage

```
git clone https://github.com/monsieurCanard/Minitalk.git && make
```
In the first terminal :
```
./serveur
```
In the second one :
```
./client
```

Now you can write something in the client, hit Enter and see it in the server terminal.
