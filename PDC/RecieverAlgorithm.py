import random


class Sender:
    def __init__(self):
        self.next_message_id = 1

    def send(self, message):
        message_id = self.next_message_id
        self.next_message_id += 1
        return message_id, message

    def receive_ack(self, message_id):
        print("Received ACK for message", message_id)


class Receiver:
    def __init__(self, sender):
        self.sender = sender
        self.next_expected_message_id = 1

    def receive(self, message_with_id):
        message_id, message_text = message_with_id
        if message_id == self.next_expected_message_id:
            self.next_expected_message_id += 1
            self.sender.receive_ack(message_id)
            print("Received message:", message_text)
        else:
            print("Received out-of-order message:", message_text)

    def send_ack(self):
        message_id = self.next_expected_message_id - 1
        return message_id


# Create sender and receiver objects
sender = Sender()
receiver = Receiver(sender)

# Send some messages
for i in range(10):
    message = "Message #" + str(i)
    message_id = str(i); 
    message_with_id = sender.send(message)
    print("Sending message:", message_with_id)
    if random.random() < 0.5:
        # Simulate lost message
        print("Message lost!")
    else:
        # Receive acknowledgement
        receiver.receive(message_with_id)
        ack = receiver.send_ack()
        sender.receive_ack(ack)
