from multiprocessing import Process, Queue


class ProcessNode(Process):
    def __init__(self, process_id, num_processes, queue):
        super().__init__()
        self.process_id = process_id
        self.num_processes = num_processes
        self.queue = queue
        self.timestamp = [0] * num_processes
        self.requested = False
        self.granted = False

    def run(self):
        while True:
            message = self.queue.get()
            if message == "release":
                self.granted = False
            else:
                sender_id, sender_timestamp = message
                self.timestamp[sender_id] = sender_timestamp
                if not self.requested:
                    self.send_grant(sender_id)
                else:
                    self.check_defer(sender_id)

    def send_grant(self, recipient_id):
        self.queue.put((recipient_id, self.timestamp.copy()))
        self.granted = True

    def check_defer(self, sender_id):
        if self.timestamp[sender_id] < self.timestamp[self.process_id]:
            self.send_grant(sender_id)
        elif not self.granted:
            self.requested = False
            self.send_grant(sender_id)

    def request_cs(self):
        self.requested = True
        self.timestamp[self.process_id] += 1
        for i in range(self.num_processes):
            if i != self.process_id:
                self.queue.put((i, self.timestamp.copy()))
        self.check_grant()

    def check_grant(self):
        grants_received = 0
        for i in range(self.num_processes):
            if i != self.process_id and self.queue.get()[1][self.process_id] <= self.timestamp[self.process_id]:
                grants_received += 1
        if grants_received == self.num_processes - 1:
            self.granted = True
        else:
            self.requested = False
            for i in range(self.num_processes):
                if i != self.process_id:
                    self.queue.put("release")


if __name__ == '__main__':
    num_processes = 3
    queue = Queue()
    processes = []
    for i in range(num_processes):
        processes.append(ProcessNode(i, num_processes, queue))
    for process in processes:
        process.start()
    processes[0].request_cs()
