from flask import Flask, request
import requests
import threading
import time

app = Flask(__name__)

# List of available servers
servers = ['http://server1:5000', 'http://server2:5000', 'http://server3:5000']

# Mutex for accessing the servers list
mutex = threading.Lock()

# Function to check the health of a server


def check_server_health(server):
    try:
        response = requests.get(server + '/healthcheck')
        if response.status_code == 200:
            return True
        else:
            return False
    except:
        return False

# Function to periodically check the health of the servers


def check_servers():
    while True:
        with mutex:
            for server in servers:
                if not check_server_health(server):
                    servers.remove(server)
                    print(f'Removing server {server} from the pool')
        time.sleep(10)


# Start the health checking thread
t = threading.Thread(target=check_servers)
t.start()


@app.route('/')
def index():
    # Select a server from the pool
    with mutex:
        selected_server = servers.pop(0)
    try:
        # Make a request to the selected server
        response = requests.get(selected_server + request.path)
    except requests.exceptions.RequestException as e:
        # If the request fails, add the server back to the pool and raise an error
        with mutex:
            servers.append(selected_server)
        raise e
    else:
        # Add the selected server back to the pool and return the response
        with mutex:
            servers.append(selected_server)
        return response.content


@app.route('/healthcheck')
def healthcheck():
    # Return a 200 OK response to indicate that the server is healthy
    return 'OK'


if __name__ == '__main__':
    app.run()
